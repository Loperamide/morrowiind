/*
 * BaseBalise.cpp
 *
 *  Created on: 11 avr. 2011
 *      Author: jpCapelle
 */

#include "headers/BaseBalise.h"

BaseBalise::BaseBalise() {
	// TODO Auto-generated constructor stub

}

BaseBalise::~BaseBalise() {
	// TODO Auto-generated destructor stub
}

void BaseBalise::getSousBalises(FILE* ficEsm, record* enreg){
	subRecord sousEnreg;
	char *bufferChar = NULL;
	unsigned int nbLus = 0;
	for(;;) {
		int retour = 0;

		memset(&sousEnreg,'\0',sizeof(sousEnreg));
		retour = fread(&sousEnreg,sizeof(sousEnreg),1,ficEsm);
		nbLus += sizeof(sousEnreg);
		if (sousEnreg.name[0] == '\0') break;

		if (retour == EOF) break;

		if(DefBalises::isSousBalise(sousEnreg.name)){
			bufferChar = (char *)realloc(bufferChar, sousEnreg.size + 1);
			retour = fread(bufferChar,sousEnreg.size,1,ficEsm);
			trtSousBalise(&sousEnreg, bufferChar);
			nbLus += sousEnreg.size;
		} else {
			//TODO a modifier pour log erreur fichier esm/esp
			cout << "Erreur" << endl;
			cout << sousEnreg.name << endl;
			break;
		}
		if (nbLus == enreg->size){
			break;
		}
	}
	free(bufferChar);
}

