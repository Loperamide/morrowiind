/*
 * Tes3.cpp
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#include "Tes3.h"

Dial* newDial = NULL;

Tes3::Tes3() {
	// TODO Auto-generated constructor stub

}

Tes3::~Tes3() {
	// TODO Auto-generated destructor stub
}

void Tes3::createObject(record* enreg){
	//Cas particulier des DIAL et INFO qui doivent se suivre
	//1 DIAL -> N INFO
	if (!memcmp("DIAL", enreg->name, 4) && newDial!=NULL){
		//Changement de DIAL, mise en liste du DIAL courrant
		lstDial.push_back(newDial);
	}
	if ((memcmp("DIAL", enreg->name, 4) && memcmp("INFO", enreg->name, 4)) && newDial!=NULL){
		//Ne vaut ni DIAL ni INFO et on a un DIAL en cours
		lstDial.push_back(newDial);
		newDial = NULL;
	}

	if (!memcmp("ACTI", enreg->name, 4)) {
		Acti* newActi = new Acti();
		newActi->getSousBalises(ficEsm, enreg);
		lstActi.push_back(newActi);
	} else if (!memcmp("ALCH", enreg->name, 4)) {
		Alch* newAlch = new Alch();
		newAlch->getSousBalises(ficEsm, enreg);
		lstAlch.push_back(newAlch);
	} else if (!memcmp("APPA", enreg->name, 4)) {
		Appa* newAppa = new Appa();
		newAppa->getSousBalises(ficEsm, enreg);
		lstAppa.push_back(newAppa);
	} else if (!memcmp("ARMO", enreg->name, 4)) {
		Armo* newArmo = new Armo();
		newArmo->getSousBalises(ficEsm, enreg);
		newArmo->closeIndx();
		lstArmo.push_back(newArmo);
	} else if (!memcmp("BODY", enreg->name, 4)) {
		Body* newBody = new Body();
		newBody->getSousBalises(ficEsm, enreg);
		lstBody.push_back(newBody);
	} else if (!memcmp("BOOK", enreg->name, 4)) {
		Book* newBook = new Book();
		newBook->getSousBalises(ficEsm, enreg);
	} else if (!memcmp("BSGN", enreg->name, 4)) {
		Bsgn* newBsgn = new Bsgn();
		newBsgn->getSousBalises(ficEsm, enreg);
		lstBsgn.push_back(newBsgn);
	} else if (!memcmp("CELL", enreg->name, 4)) {
		Cell* newCell = new Cell();
		newCell->getSousBalises(ficEsm, enreg);
	} else if (!memcmp("CLAS", enreg->name, 4)) {
		Clas* newClas = new Clas();
		newClas->getSousBalises(ficEsm, enreg);
		lstClas.push_back(newClas);
	} else if (!memcmp("CLOT", enreg->name, 4)) {
		Clot* newClot = new Clot();
		newClot->getSousBalises(ficEsm, enreg);
		newClot->closeIndx();
		lstClot.push_back(newClot);
	} else if (!memcmp("CONT", enreg->name, 4)) {
		Cont* newCont = new Cont();
		newCont->getSousBalises(ficEsm, enreg);
		lstCont.push_back(newCont);
	} else if (!memcmp("CREA", enreg->name, 4)) {
		Crea* newCrea = new Crea();
		newCrea->getSousBalises(ficEsm, enreg);
		lstCrea.push_back(newCrea);
	} else if (!memcmp("DIAL", enreg->name, 4)) {
		newDial = new Dial();
		newDial->getSousBalises(ficEsm, enreg);
	} else if (!memcmp("DOOR", enreg->name, 4)) {
		Door* newDoor = new Door();
		newDoor->getSousBalises(ficEsm, enreg);
		lstDoor.push_back(newDoor);
	} else if (!memcmp("ENCH", enreg->name, 4)) {
		Ench* newEnch = new Ench();
		newEnch->getSousBalises(ficEsm, enreg);
		lstEnch.push_back(newEnch);
	} else if (!memcmp("FACT", enreg->name, 4)) {
		Fact* newFact = new Fact();
		newFact->getSousBalises(ficEsm, enreg);
		lstFact.push_back(newFact);
	} else if (!memcmp("GLOB", enreg->name, 4)) {
		Glob* newGlob = new Glob();
		newGlob->getSousBalises(ficEsm, enreg);
		lstGlob.push_back(newGlob);
	} else if (!memcmp("GMST", enreg->name, 4)) {
		Gmst* newGmst = new Gmst();
		newGmst->getSousBalises(ficEsm, enreg);
		lstGmst.push_back(newGmst);
	} else if (!memcmp("INFO", enreg->name, 4)) {
		if (newDial == NULL) {
			cout << "INFO sans DIAL" << endl;
		} else {
			Info* newInfo = new Info();
			newInfo->getPosition(ficEsm, enreg);
			newInfo->getSousBalises(ficEsm, enreg);
			newDial->push_back(newInfo);
		}
	} else if (!memcmp("INGR", enreg->name, 4)) {
		Ingr* newIngr = new Ingr();
		newIngr->getSousBalises(ficEsm, enreg);
		lstIngr.push_back(newIngr);
	} else if (!memcmp("LAND", enreg->name, 4)) {
		Land* newLand = new Land();
		newLand->getSousBalises(ficEsm, enreg);
	} else if (!memcmp("LEVC", enreg->name, 4)) {
		Levc* newLevc = new Levc();
		newLevc->getSousBalises(ficEsm, enreg);
		lstLevc.push_back(newLevc);
	} else if (!memcmp("LEVI", enreg->name, 4)) {
		Levi* newLevi = new Levi();
		newLevi->getSousBalises(ficEsm, enreg);
		lstLevi.push_back(newLevi);
	} else if (!memcmp("LIGH", enreg->name, 4)) {
		Ligh* newLigh = new Ligh();
		newLigh->getSousBalises(ficEsm, enreg);
		lstLigh.push_back(newLigh);
	} else if (!memcmp("LOCK", enreg->name, 4)) {
		Lock* newLock = new Lock();
		newLock->getSousBalises(ficEsm, enreg);
		lstLock.push_back(newLock);
	} else if (!memcmp("LTEX", enreg->name, 4)) {
		Ltex* newLtex = new Ltex();
		newLtex->getSousBalises(ficEsm, enreg);
		lstLtex.push_back(newLtex);
	} else if (!memcmp("MGEF", enreg->name, 4)) {
		Mgef* newMgef = new Mgef();
		newMgef->getSousBalises(ficEsm, enreg);
		lstMgef.push_back(newMgef);
	} else if (!memcmp("MISC", enreg->name, 4)) {
		Misc* newMisc = new Misc();
		newMisc->getSousBalises(ficEsm, enreg);
		lstMisc.push_back(newMisc);
	} else if (!memcmp("NPC_", enreg->name, 4)) {
		Npc_* newNpc_ = new Npc_();
		newNpc_->getSousBalises(ficEsm, enreg);
	} else if (!memcmp("PGRD", enreg->name, 4)) {
		Pgrd* newPgrd = new Pgrd();
		newPgrd->getSousBalises(ficEsm, enreg);
	} else if (!memcmp("PROB", enreg->name, 4)) {
		Prob* newProb = new Prob();
		newProb->getSousBalises(ficEsm, enreg);
		lstProb.push_back(newProb);
	} else if (!memcmp("RACE", enreg->name, 4)) {
		Race* newRace = new Race();
		newRace->getSousBalises(ficEsm, enreg);
		lstRace.push_back(newRace);
	} else if (!memcmp("REGN", enreg->name, 4)) {
		Regn* newRegn = new Regn();
		newRegn->getSousBalises(ficEsm, enreg);
		lstRegn.push_back(newRegn);
	} else if (!memcmp("REPA", enreg->name, 4)) {
		Repa* newRepa = new Repa();
		newRepa->getSousBalises(ficEsm, enreg);
		lstRepa.push_back(newRepa);
	} else if (!memcmp("SCPT", enreg->name, 4)) {
		Scpt* newScpt = new Scpt();
		newScpt->getSousBalises(ficEsm, enreg);
		lstScpt.push_back(newScpt);
	} else if (!memcmp("SKIL", enreg->name, 4)) {
		Skil* newSkil = new Skil();
		newSkil->getSousBalises(ficEsm, enreg);
		lstSkil.push_back(newSkil);
	} else if (!memcmp("SNDG", enreg->name, 4)) {
		Sndg* newSndg = new Sndg();
		newSndg->getSousBalises(ficEsm, enreg);
		lstSndg.push_back(newSndg);
	} else if (!memcmp("SOUN", enreg->name, 4)) {
		Soun* newSoun = new Soun();
		newSoun->getSousBalises(ficEsm, enreg);
		lstSoun.push_back(newSoun);
	} else if (!memcmp("SPEL", enreg->name, 4)) {
		Spel* newSpel = new Spel();
		newSpel->getSousBalises(ficEsm, enreg);
		lstSpel.push_back(newSpel);
	} else if (!memcmp("STAT", enreg->name, 4)) {
		Stat* newStat = new Stat();
		newStat->getSousBalises(ficEsm, enreg);
		lstStat.push_back(newStat);
	} else if (!memcmp("TES3", enreg->name, 4)) {
		getSousBalises(ficEsm, enreg);
	} else if (!memcmp("WEAP", enreg->name, 4)) {
		Weap* newWeap = new Weap();
		newWeap->getSousBalises(ficEsm, enreg);
		lstWeap.push_back(newWeap);
	}
}

bool Tes3::loadFile(const char *fichier){
	bool retour = true;
	ficEsm = fopen(fichier,"rb");

	record enreg;
	for(;;){
		int retour = 0;
		memset(&enreg,'\0',sizeof(enreg));
		retour = fread(&enreg,sizeof(enreg),1,ficEsm);
		if (enreg.name[0] == '\0') break;

		if (retour == EOF) break;

		if(DefBalises::isBalise(enreg.name)){
			//Création de l'instance de l'objet et ajout à la liste correspondante
			createObject(&enreg);

		} else {
			//TODO a modifier pour log erreur fichier esm/esp
			cout << "Erreur" << endl;
			cout << enreg.name << endl;
			retour = false;
			break;
		}
	}
	fclose(ficEsm);
	return retour;
}

void Tes3::trtSousBalise(subRecord* sousEnreg, char* bufferChar){
	if (!strncmp("HEDR", sousEnreg->name, 4)) {
	} else if(!strncmp("MAST", sousEnreg->name, 4)){
	} else if(!strncmp("DATA", sousEnreg->name, 4)){
	}
}
