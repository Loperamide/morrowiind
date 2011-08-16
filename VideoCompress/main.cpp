/*
 * main.cpp
 *
 *  Created on: 21 mars 2011
 *      Author: jpCapelle
 *
 * Produit un fichier au format vjp (pour video JP).
 * Ce fichier est constitué de la manière suivante :
 * 4 octets pour VJP + version
 * 4 octets pour la position de la bande son
 * 4 octets pour nombre d'images
 * 4 octets par position d'image
 * n octets par image png
 * n octets pour la bande son en mp3
 */

#include <dirent.h>
#include <iostream>
#include <vector>
#include <sys/stat.h>

using namespace std;
typedef struct dirent dirent;
typedef struct stat fileStatus;

int main(int argc, const char* argv[]) {
	//argv[1] : repertoire de travail
	if (argc < 2) return -1;

	//Liste les fichiers du répertoire
	dirent *dirContent;

	DIR* directory = opendir(argv[1]);
	if (directory == NULL) return -1;

	//position currentImg = 12
	int nbImages=0;
	int tailleImages = 0;
	int taille;
	vector<unsigned int> listTailles;

	char bandeSonName[strlen(argv[1])+1+50];
	for(;;) {
		dirContent = readdir(directory);
		if (dirContent == NULL) break;

		//Pour chaque fichier, si extention png
		char *fileName = dirContent->d_name;
		char *fileExt = fileName + (strlen(fileName)-4);
		char *ficEtDir = new char[strlen(argv[1])+1+strlen(fileName)];
		strcpy(ficEtDir,argv[1]);
		strcat(ficEtDir,"\\");
		strcat(ficEtDir,fileName);

		if(!strncmp(fileExt,".png",4)){
			//recup taille
			fileStatus status;
			stat(ficEtDir, &status);
			taille = status.st_size;
			tailleImages += taille;
			//nombre images ++
			nbImages++;
			//ajout liste taille
			listTailles.push_back(taille);
		}
		if(!strncmp(fileExt,".mp3",4)){
			strcpy(bandeSonName,argv[1]);
			strcat(bandeSonName,"\\");
			strcat(bandeSonName, dirContent->d_name);
			cout << bandeSonName << endl;
		}
	}
	rewinddir(directory);
	//Ouverture fichier final
	char *nomFicSortie = new char[strlen(argv[1])+50];

	strcpy(nomFicSortie, argv[1]);
	strcat(nomFicSortie, "\\");
	strcat(nomFicSortie, "sortie.vjp");
	FILE *ficSortie = fopen(nomFicSortie, "wb");
	//ecriture VJP + version
	fwrite("VJP0",4,1,ficSortie);
	//ecriture position bande son
	unsigned int posBdSon = tailleImages + 12 + (4*nbImages);
	fwrite(&posBdSon,4,1,ficSortie);
	//ecriture nombre images
	fwrite(&nbImages,4,1,ficSortie);
	fflush(ficSortie);
	//ecriture liste positions
	unsigned int position;
	for(int x = 0;x < listTailles.size();x++){
		unsigned int sommePrecedents = 0;
		for(int y=x;y>0;y--){
			sommePrecedents += listTailles.at(y);
		}
		position = 12 + (4*nbImages) + sommePrecedents;
		fwrite(&position,4,1,ficSortie);
	}
	//Concatenation images
	for(;;){
		dirContent = readdir(directory);
		if (dirContent == NULL) break;

		//Pour chaque fichier, si extention png
		char *fileName = dirContent->d_name;
		char *fileExt = fileName + (strlen(fileName)-4);
		char *ficEtDir = new char[strlen(argv[1])+1+strlen(fileName)];
		strcpy(ficEtDir,argv[1]);
		strcat(ficEtDir,"\\");
		strcat(ficEtDir,fileName);

		if(!strncmp(fileExt,".png",4)){
			//recup taille
			fileStatus status;
			stat(ficEtDir, &status);

			char *buffer[status.st_size];
			FILE* image = fopen(ficEtDir,"rb");
			fread(buffer,status.st_size,1,image);
			fwrite(buffer,status.st_size,1,ficSortie);
			fclose(image);
		}
	}
	//Concatenation bande son
	fileStatus status;
	stat(bandeSonName, &status);

	char buffer[status.st_size];
	FILE* bdSon = fopen(bandeSonName,"rb");
	fread(buffer,status.st_size,1,bdSon);
	fwrite(buffer,status.st_size,1,ficSortie);
	fclose(bdSon);
	//fermeture fichier
	fclose(ficSortie);
	return 0;
}
