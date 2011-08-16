/*
 * main.cpp
 *
 *  Created on: 9 févr. 2011
 *      Author: jpCapelle
 *
 *  Indexation du fichier esm dans un format plus adapté
 */

#include <iostream>
#include "Record.h"
#include "SubRecord.h"

using namespace std;

#define NBRECORD 42

struct enteteDest{
	char type[4];
	int lastIdent;
};

struct esmObject{
	int identifiant;
	int position;//position dans le fichier esm/esp/ess
	//int len;//? utile ?
};

/**
 * Listes d'objets dont on ne charge que la position dans le fichier pour économiser de la place
 */
typedef struct objInFile objInFile;
struct objInFile{
	char name[100];
	int pos;
}objEnCours, *lstBook, *lstInfo, *lstNpc_, *lstPgrd, *lstCell;
int nbBook = 0;
int nbInfo = 0;
int nbNpc_ = 0;
int nbPgrd = 0;
int nbCell = 0;

typedef struct landInFile landInFile;
struct landInFile{
	int mapX;
	int mapY;
	int pos;
}landEnCours, *lstLand;
int nbLand = 0;

typedef struct tableauVals tableauVals;
struct tableauVals {
	char name[5];
	int size;
	int nbOccurs;
}lstRecordsCount[NBRECORD];
int nbVals1 = 0;
int nbVals2 = 0;

bool firstCellData=true;
bool firstCellName=true;
bool trouveName=false;

typedef char baliseName[5];

static baliseName lstBalises[]={"ACTI","ALCH","APPA","ARMO",
		"BODY","BOOK","BSGN",
		"CELL","CLAS","CLOT","CONT","CREA",
		"DIAL","DOOR",
		"ENCH",
		"FACT",
		"GLOB","GMST",
		"INFO","INGR",
		"LAND","LEVC","LEVI","LIGH","LOCK","LTEX",
		"MGEF","MISC",
		"NPC_",
		"PGRD","PROB",
		"RACE","REGN","REPA",
		"SCPT","SKIL","SNDG","SOUN","SPEL","STAT",
		"TES3",
		"WEAP"};
static baliseName lstSousBalises[]={"AADT","AI_A","AI_E","AI_F","AI_T","AI_W","AIDT","ALDT","AMBI","ANAM","AODT","ASND","AVFX",
		"BKDT","BNAM","BSND","BVFX","BYDT",
		"CLDT","CNAM","CNDT","CSND","CTDT","CVFX",
		"DATA","DELE","DESC","DNAM","DODT",
		"ENAM","ENDT",
		"FADT","FLAG","FLTV","FNAM","FRMR",
		"HEDR","HSND","HVFX",
		"INAM","INDX","INTV","IRDT","ITEX",
		"KNAM",
		"LHDT","LKDT",
		"MAST","MCDT","MEDT","MODL",
		"NAM0","NAM5","NAM9","NAME","NNAM","NPCO","NPCS","NPDT",
		"ONAM",
		"PBDT","PNAM","PTEX",
		"QSTF","QSTN","QSTR",
		"RADT","RGNN","RIDT","RNAM",
		"SCHD","SCIP","SCRI","SCPT","SNAM","SCVR","SCDT","SCTX","SNAM","SPDT",
		"TEXT","TNAM",
		"UNAM",
		"VCLR","VHGT","VNML","VTEX",
		"WEAT","WHGT","WNAM","WPDT",
		"XSCL","XSOL"};


bool isBalise(char *balise) {
	bool retour = false;
	for(unsigned int x=0;x<sizeof(lstBalises)/4;x++){
		if (!memcmp(lstBalises[x],balise,4)){
			retour = true;
			break;
		}
	}
	return retour;
}

bool isSousBalise(char *balise) {
	bool retour = false;
	for(unsigned int x=0;x<sizeof(lstBalises)/4;x++){
		if (!memcmp(lstSousBalises[x],balise,4)){
			retour = true;
			break;
		}
	}
	return retour;
}

/**
 * Mises à jour des compteurs pour chaque balise reconnue dans le fichier en entrée
 */
void ajouteTableau(Record *balise) {
	bool trouve = false;
	for(int x = 0;x < nbVals2; x++) {
		if (!strcmp(lstRecordsCount[x].name, balise->getName())) {
			lstRecordsCount[x].size += balise->getSize();
			lstRecordsCount[x].nbOccurs += 1;
			trouve = true;
			break;
		}
	}
	if (!trouve) {
		strcpy(lstRecordsCount[nbVals2].name, balise->getName());
		lstRecordsCount[nbVals2].size = balise->getSize();
		lstRecordsCount[nbVals2].nbOccurs = 1;
		nbVals2++;
	}
}

void lstAddName(SubRecord* sousBalise, char *buffer, int& compteur, objInFile* liste, int posIn) {
	char buffTmp[100];
	char name[sousBalise->getSize()+1];
	memcpy(name,buffer,sousBalise->getSize());
	name[sousBalise->getSize()]='\0';
	sprintf(buffTmp, "%-s", name);

	memcpy(objEnCours.name,buffTmp,25);
	objEnCours.pos = posIn;

	int x;
	for(x=0; x<compteur; x++){
		if (strcmp(liste[x].name,objEnCours.name)>0){
			//Décalage
			for(int y=compteur;y>x;y--){
				memcpy(&liste[y],&liste[y-1],sizeof(objInFile));
			}
			break;
		}
	}

	memcpy(&liste[x],&objEnCours,sizeof(objInFile));
	compteur++;
}

void lstAddName(SubRecord* sousBalise, int *buffer, int& compteur, landInFile* liste, int posIn) {
	landEnCours.mapX = buffer[0];
	landEnCours.mapY = buffer[1];
	landEnCours.pos = posIn;

	int x;
	for(x=0; x<compteur; x++){
		if ((liste[x].mapX > landEnCours.mapX)||(liste[x].mapY > landEnCours.mapY)){
			//Décalage
			for(int y=compteur;y>x;y--){
				memcpy(&liste[y],&liste[y-1],sizeof(landInFile));
			}
			break;
		}
	}

	memcpy(&liste[x],&landEnCours,sizeof(landInFile));
	compteur++;
}

/**
 * Traitement des données lues dans les fichiers esm/esp
 */
//void traiteDonnees(Record *balise, SubRecord *sousBalise, char *buffer, FILE *ficSortie1, FILE *ficSortie3, int posIn) {
void traiteDonnees(Record *balise, SubRecord *sousBalise, char *buffer, int posIn) {
	char buffTmp[100];
	if (sousBalise == NULL) {
		firstCellName = true;//Init début de CELL
		firstCellData = true;//Init début de CELL
		trouveName = false;
//		sprintf(buffSortie,"pos : %d\n", pos);
//		fwrite(&buffSortie,strlen(buffSortie),1,ficSortie1);
//		sprintf(buffTmp,"name : %s\n", balise->getName());
//		fwrite(&buffTmp,strlen(buffTmp),1,ficSortie1);
//		sprintf(buffTmp,"size : %d\n", balise->getSize());
//		fwrite(&buffTmp,strlen(buffTmp),1,ficSortie1);
		return;
	}

	char buffSortie[sousBalise->getSize()];

	if (!strcmp(balise->getName(),"ACTI")){

	}
	if (!strcmp(balise->getName(),"ALCH")){

	}
	if (!strcmp(balise->getName(),"APPA")){

	}
	if (!strcmp(balise->getName(),"ARMO")){

	}
	if (!strcmp(balise->getName(),"BODY")){

	}
	if (!strcmp(balise->getName(),"BOOK")){
		if (!strcmp(sousBalise->getName(),"NAME")){
			lstAddName(sousBalise, buffer, nbBook, lstBook, posIn);
		}
	}
	if (!strcmp(balise->getName(),"BSGN")){

	}
	if (!strcmp(balise->getName(),"CELL")){
		if (!strcmp(sousBalise->getName(),"NAME")){
//			sprintf(buffSortie,"\tNAME : %s\n", buffer);
//			fwrite(&buffSortie,strlen(buffSortie),1,ficSortie1);
			if (firstCellName) {
				if(strlen(buffer)>0) {
					lstAddName(sousBalise, buffer, nbCell, lstCell, posIn);
					trouveName = true;
				}
				firstCellName = false;
			}
		} else if (!strcmp(sousBalise->getName(),"RGNN")){
			if (!trouveName) {
				lstAddName(sousBalise, buffer, nbCell, lstCell, posIn);
			}
//			sprintf(buffSortie,"\tRGNN : %s\n", buffer);
//			fwrite(&buffSortie,strlen(buffSortie),1,ficSortie1);
		} else if (!strcmp(sousBalise->getName(),"DATA")){
			if (firstCellData) {
				//Au premier DATA sur la balise, coordonnées de la CELL
				int pos[3];
				memcpy(pos,buffer,12);

				firstCellData = false;
			} else {
				//Les DATA suivants contiennent la position/orientation de la référence de l'objet de la CELL
				float pos[6];
				memcpy(pos,buffer,24);

//				sprintf(buffSortie,"\tDATA Obj CoordX : %f\n", pos[0]);
//				fwrite(&buffSortie,strlen(buffSortie),1,ficSortie1);
//				sprintf(buffSortie,"\tDATA Obj CoordY : %f\n", pos[1]);
//				fwrite(&buffSortie,strlen(buffSortie),1,ficSortie1);
//				sprintf(buffSortie,"\tDATA Obj CoordZ : %f\n", pos[2]);
//				fwrite(&buffSortie,strlen(buffSortie),1,ficSortie1);
//				sprintf(buffSortie,"\tDATA Obj RotateX : %f\n", pos[3]);
//				fwrite(&buffSortie,strlen(buffSortie),1,ficSortie1);
//				sprintf(buffSortie,"\tDATA Obj RotateY : %f\n", pos[4]);
//				fwrite(&buffSortie,strlen(buffSortie),1,ficSortie1);
//				sprintf(buffSortie,"\tDATA Obj RotateZ : %f\n", pos[5]);
//				fwrite(&buffSortie,strlen(buffSortie),1,ficSortie1);
			}
		} else {
//			sprintf(buffSortie,"\tBALISE : %s\n", sousBalise->getName());
//			cout << buffSortie << endl;
//			fwrite(&buffSortie,strlen(buffSortie),1,ficSortie1);
		}

	}
	if (!strcmp(balise->getName(),"CLAS")){

	}
	if (!strcmp(balise->getName(),"CLOT")){

	}
	if (!strcmp(balise->getName(),"CONT")){

	}
	if (!strcmp(balise->getName(),"CREA")){

	}
	if (!strcmp(balise->getName(),"DIAL")){

	}
	if (!strcmp(balise->getName(),"DOOR")){

	}
	if (!strcmp(balise->getName(),"ENCH")){

	}
	if (!strcmp(balise->getName(),"FACT")){

	}
	if (!strcmp(balise->getName(),"GLOB")){

	}
	if (!strcmp(balise->getName(),"GMST")){

	}
	if (!strcmp(balise->getName(),"INFO")){
		if (!strcmp(sousBalise->getName(),"INAM")){
			lstAddName(sousBalise, buffer, nbInfo, lstInfo, posIn);
		}
	}
	if (!strcmp(balise->getName(),"INGR")){

	}
	if (!strcmp(balise->getName(),"LAND")){
		if (!strcmp(sousBalise->getName(),"INTV")){
			lstAddName(sousBalise, (int *)buffer, nbLand, lstLand, posIn);
		}
	}
	if (!strcmp(balise->getName(),"LEVC")){

	}
	if (!strcmp(balise->getName(),"LEVI")){

	}
	if (!strcmp(balise->getName(),"LIGH")){

	}
	if (!strcmp(balise->getName(),"LOCK")){

	}
	if (!strcmp(balise->getName(),"LTEX")){

	}
	if (!strcmp(balise->getName(),"MGEF")){

	}
	if (!strcmp(balise->getName(),"MISC")){

	}
	if (!strcmp(balise->getName(),"NPC_")){
		if (!strcmp(sousBalise->getName(),"NAME")){
			lstAddName(sousBalise, buffer, nbNpc_, lstNpc_, posIn);
		}
	}
	if (!strcmp(balise->getName(),"PGRD")){
//...?
	}
	if (!strcmp(balise->getName(),"PROB")){

	}
	if (!strcmp(balise->getName(),"RACE")){

	}
	if (!strcmp(balise->getName(),"REGN")){
		if (!strcmp(sousBalise->getName(),"NAME")){
//			sprintf(buffSortie,"\tNAME : %s\n", buffer);
//			fwrite(&buffSortie,strlen(buffSortie),1,ficSortie1);
		}
		if (!strcmp(sousBalise->getName(),"SNAM")){
//			sprintf(buffSortie,"\tSNAM : %s\n", buffer);
//			fwrite(&buffSortie,strlen(buffSortie),1,ficSortie1);
		}
	}
	if (!strcmp(balise->getName(),"REPA")){

	}
	if (!strcmp(balise->getName(),"SCPT")){

	}
	if (!strcmp(balise->getName(),"SKIL")){

	}
	if (!strcmp(balise->getName(),"SNDG")){

	}
	if (!strcmp(balise->getName(),"SOUN")){

	}
	if (!strcmp(balise->getName(),"SPEL")){

	}
	if (!strcmp(balise->getName(),"STAT")){

	}
	if (!strcmp(balise->getName(),"TES3")){

	}
	if (!strcmp(balise->getName(),"WEAP")){

	}
}

/**
 * Renvoie le nombre d'occurences du Record en param
 */
int getNbOccurs(char* recordName) {
	int retour = 0;
	for(int x=0;x<NBRECORD;x++){
		if (!strcmp(lstRecordsCount[x].name, recordName)){
			retour = lstRecordsCount[x].nbOccurs;
		}
	}
	return retour;
}

/**
 * Initialisation de la taille des listes
 */
void initListSize(){
	lstBook = (objInFile*)malloc(getNbOccurs("BOOK") * sizeof(objInFile));
	lstCell = (objInFile*)malloc(getNbOccurs("CELL") * sizeof(objInFile));
	lstInfo = (objInFile*)malloc(getNbOccurs("INFO") * sizeof(objInFile));
	lstLand = (landInFile*)malloc(getNbOccurs("LAND") * sizeof(landInFile));
	lstNpc_ = (objInFile*)malloc(getNbOccurs("NPC_") * sizeof(objInFile));
	lstPgrd = (objInFile*)malloc(getNbOccurs("PGRD") * sizeof(objInFile));
}

/**
 * Init des compteurs de Records
 */
void countObjects(){
	FILE *ficEsm = fopen("F:\\ExemplesMorrowiind\\Morrowind.esm","rb");

	record enreg;
	int x=0;

	for(;;x++){
		int retour = 0;
		memset(&enreg,'\0',sizeof(enreg));
		retour = fread(&enreg,sizeof(enreg),1,ficEsm);
		if (enreg.name[0] == '\0') break;

		if (retour == EOF) break;

		if(isBalise(enreg.name)){
			//Commence par une balise
			Record* balise = new Record(enreg);

			ajouteTableau(balise);

			retour = fseek(ficEsm, balise->getSize(), SEEK_CUR);
			if (retour != 0) {
				cout << "Erreur" << endl;
			}

			delete(balise);

		} else {
			cout << "Erreur" << endl;
			cout << enreg.name << endl;
			break;
		}
	}
	initListSize();
	fclose(ficEsm);
}

/**
 * Initialisation des listes à partir des données du fichier en entrée
 */
void loadObjects(){
	FILE *ficEsm = fopen("F:\\ExemplesMorrowiind\\Morrowind.esm","rb");

	char* buffer=NULL;

	record enreg;
	int x=0;
	int pos = 0;

	for(;;x++){
		int retour = 0;
		memset(&enreg,'\0',sizeof(enreg));
		retour = fread(&enreg,sizeof(enreg),1,ficEsm);
		if (enreg.name[0] == '\0') break;

		if (retour == EOF) break;

		if(isBalise(enreg.name)){
			//Commence par une balise
			Record* balise = new Record(enreg);
			SubRecord *sousBalise = NULL;

			traiteDonnees(balise, sousBalise, buffer, pos);
			{
				int nblus = 0;
				subRecord subEnreg;

				while (nblus < balise->getSize()) {
					retour = fread(&subEnreg, sizeof(subRecord), 1, ficEsm);

					if (retour == EOF) break;

					sousBalise = new SubRecord(subEnreg);

					buffer = (char *) malloc(sousBalise->getSize()+1);//Données de la sous balise
					retour = fread(buffer, sousBalise->getSize(), 1, ficEsm);
					buffer[sousBalise->getSize()] = '\0';
					traiteDonnees(balise, sousBalise, buffer, pos);

					free(buffer);

					nblus += sizeof(subRecord);
					nblus += sousBalise->getSize();
					delete(sousBalise);
				}
				pos += nblus;
			}

			delete(balise);

		} else {
			cout << "Erreur" << endl;
			cout << enreg.name << endl;
			break;
		}
		pos += sizeof(record);
	}
	fclose(ficEsm);
}

void printListRecords(){
	FILE* ficList = fopen("F:\\ExemplesMorrowiind\\listeRecords.jpc","w");
	char buffer[1000];
	for(int x=0;x<NBRECORD;x++){
		sprintf(buffer, "Name : %s | Size : %d | NBOccurs : %d\n", lstRecordsCount[x].name, lstRecordsCount[x].size, lstRecordsCount[x].nbOccurs);
		fwrite(&buffer, strlen(buffer), 1, ficList);
	}
	fclose(ficList);
}

void printListNpcs(){
	FILE* ficList = fopen("F:\\ExemplesMorrowiind\\listeNpcs.jpc","w");
	char buffer[1000];
	for(int x=0;x<getNbOccurs("NPC_");x++){
		sprintf(buffer, "Name : %s | Pos : %d\n", lstNpc_[x].name, lstNpc_[x].pos);
		fwrite(&buffer, strlen(buffer), 1, ficList);
	}
	fclose(ficList);
}

void printListBooks(){
	FILE* ficList = fopen("F:\\ExemplesMorrowiind\\listeBooks.jpc","w");
	char buffer[1000];
	for(int x=0;x<getNbOccurs("BOOK");x++){
		sprintf(buffer, "Name : %s | Pos : %d\n", lstBook[x].name, lstBook[x].pos);
		fwrite(&buffer, strlen(buffer), 1, ficList);
	}
	fclose(ficList);
}

void printListLands(){
	FILE* ficList = fopen("F:\\ExemplesMorrowiind\\listeLands.jpc","w");
	char buffer[1000];
	for(int x=0;x<getNbOccurs("LAND");x++){
		sprintf(buffer, "POSX : %d |POSY : %d | Pos : %d\n", lstLand[x].mapX, lstLand[x].mapY, lstLand[x].pos);
		fwrite(&buffer, strlen(buffer), 1, ficList);
	}
	fclose(ficList);
}

void printListCells(){
	FILE* ficList = fopen("F:\\ExemplesMorrowiind\\listeCells.jpc","w");
	char buffer[1000];
	for(int x=0;x<getNbOccurs("CELL");x++){

		//sprintf(buffer, "POSX : %d |POSY : %d | Pos : %d\n", lstCell[x].mapX, lstCell[x].mapY, lstCell[x].pos);
		sprintf(buffer, "NAME : %s \t\t| POS : %d\n", lstCell[x].name,lstCell[x].pos);
		fwrite(&buffer, strlen(buffer), 1, ficList);
	}
	fclose(ficList);
}

void getDonnees(Record *balise, SubRecord *sousBalise, char *buffer, int posIn) {
}

int getCellPosInFile(char* cellName, int next) {
	int retour = 0;
	for(int x = 0; x < nbCell; x++) {
		if(!strcmp(lstCell[x].name,cellName)){
			//Bonne Cell
			retour = lstCell[x].pos;
			break;
		}
	}
	return retour;
}
void printCellInfo(char *cellName){
	FILE *ficEntree = fopen("F:\\ExemplesMorrowiind\\Morrowind.esm","rb");
	FILE *ficSortie = fopen("F:\\ExemplesMorrowiind\\Cell.jpc","w");

	fpos_t pos = 0;
	fgetpos(ficEntree, &pos);
	cout << "pos : " << pos << endl;
	pos = getCellPosInFile(cellName, 0);

	if (pos == 0) {
		cout << "erreur recherche Cellule" << endl;
		return;
	}

	int x=0;
	x = fseek(ficEntree, pos, SEEK_SET);
	fgetpos(ficEntree, &pos);
	cout << "pos : " << pos << endl;

	cout << "result : " << x << endl;

	char* buffer=NULL;
	char bufferSortie[200];

	record enreg;

	//for(;;x++){
		int retour = 0;
		memset(&enreg,'\0',sizeof(enreg));
		retour = fread(&enreg,sizeof(enreg),1,ficEntree);

		if((enreg.name[0]!='\0')&&(retour!=EOF)) {
			if(isBalise(enreg.name)){
				Record* balise = new Record(enreg);
				SubRecord *sousBalise = NULL;

	//			traiteDonnees(balise, sousBalise, buffer, pos);

				sprintf(bufferSortie,"Name : %s\tSize : %d\n",balise->getName(),balise->getSize());
				fwrite(&bufferSortie, strlen(bufferSortie), 1, ficSortie);
				{
					int nblus = 0;
					subRecord subEnreg;

					while (nblus < balise->getSize()) {
						retour = fread(&subEnreg, sizeof(subRecord), 1, ficEntree);

						if (retour == EOF) break;

						sousBalise = new SubRecord(subEnreg);

						buffer = (char *) malloc(sousBalise->getSize()+1);//Données de la sous balise
						retour = fread(buffer, sousBalise->getSize(), 1, ficEntree);
						buffer[sousBalise->getSize()] = '\0';
	//					traiteDonnees(balise, sousBalise, buffer, pos);
						sprintf(bufferSortie,"\tSub_Name : %s\tSize : %d\n",sousBalise->getName(),sousBalise->getSize());
						fwrite(&bufferSortie, strlen(bufferSortie), 1, ficSortie);

						free(buffer);

						nblus += sizeof(subRecord);
						nblus += sousBalise->getSize();
						delete(sousBalise);
					}
					pos += nblus;
				}
				delete(balise);

			} else {
				cout << "Erreur Balise : " << endl;
			}
		}
	//}

	fclose(ficEntree);
	fclose(ficSortie);
}

int main(void) {

	cout << "count..." << endl;
	countObjects();
	cout << "load..." << endl;
	loadObjects();

	cout << "print records..." << endl;
	//printListRecords();
	cout << "print books..." << endl;
	//printListBooks();
	cout << "print cells..." << endl;
	printListCells();
	printCellInfo("Vivec, quartiers de Milo");
	cout << "print infos..." << endl;
	//printListInfos();
	cout << "print lands..." << endl;
	//printListLands();
	cout << "print npc_s..." << endl;
	//printListNpcs();
	cout << "print pgrds..." << endl;
	//printListPgrds();

	cout << "Fin" << endl;
	return 0;
}
