/*
 * Clas.cpp
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#include "headers/Clas.h"

Clas::Clas() {
	// TODO Auto-generated constructor stub

}

Clas::~Clas() {
	// TODO Auto-generated destructor stub
}
void Clas::trtSousBalise(subRecord* sousEnreg, char* bufferChar){
	if (!memcmp("NAME", sousEnreg->name, 4)) {
		this->name = (char *)malloc(sousEnreg->size + 1);
		memset(this->name,'\0',sousEnreg->size + 1);
		memcpy(this->name, bufferChar, sousEnreg->size);
	} else if (!memcmp("FNAM", sousEnreg->name, 4)) {
		memset(&this->itemName,'\0',4);
		memcpy(&this->itemName, bufferChar, sousEnreg->size);
	} else if (!memcmp("CLDT", sousEnreg->name, 4)) {
		memcpy(&this->clasData, bufferChar, sousEnreg->size);
	} else if (!memcmp("DESC", sousEnreg->name, 4)) {
		this->desc = (char *)malloc(sousEnreg->size + 1);
		memset(this->desc,'\0',sousEnreg->size + 1);
		memcpy(this->desc, bufferChar, sousEnreg->size);
	} else {
		cout << "Erreur CLAS subEnreg " << sousEnreg->name << endl;
	}
}
