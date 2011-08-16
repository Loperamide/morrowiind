/*
 * Bsgn.cpp
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#include "headers/Bsgn.h"

Bsgn::Bsgn() {
	// TODO Auto-generated constructor stub

}

Bsgn::~Bsgn() {
	// TODO Auto-generated destructor stub
}
void Bsgn::trtSousBalise(subRecord* sousEnreg, char* bufferChar){
	if (!memcmp("NAME", sousEnreg->name, 4)) {
		this->name = (char *)malloc(sousEnreg->size + 1);
		memset(this->name,'\0',sousEnreg->size + 1);
		memcpy(this->name, bufferChar, sousEnreg->size);
	} else if (!memcmp("FNAM", sousEnreg->name, 4)) {
		this->itemName = (char *)malloc(sousEnreg->size + 1);
		memset(this->itemName,'\0',sousEnreg->size + 1);
		memcpy(this->itemName, bufferChar, sousEnreg->size);
	} else if (!memcmp("TNAM", sousEnreg->name, 4)) {
		this->textureName = (char *)malloc(sousEnreg->size + 1);
		memset(this->textureName,'\0',sousEnreg->size + 1);
		memcpy(this->textureName, bufferChar, sousEnreg->size);
	} else if (!memcmp("DESC", sousEnreg->name, 4)) {
		this->desc = (char *)malloc(sousEnreg->size + 1);
		memset(this->desc,'\0',sousEnreg->size + 1);
		memcpy(this->desc, bufferChar, sousEnreg->size);
	} else if (!memcmp("NPCS", sousEnreg->name, 4)) {
		char *tmp;
		tmp = (char *)malloc(sousEnreg->size + 1);
		memset(tmp,'\0',sousEnreg->size + 1);
		lstAbility.push_back(tmp);
	} else {
		cout << "Erreur BSGN subEnreg " << this->name << endl;
		cout << "Erreur BSGN subEnreg " << sousEnreg->name << endl;
	}
}
