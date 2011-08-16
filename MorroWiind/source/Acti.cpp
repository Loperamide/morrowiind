/*
 * Acti.cpp
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#include "headers/Acti.h"

Acti::Acti() {
	// TODO Auto-generated constructor stub

}

Acti::~Acti() {
	// TODO Auto-generated destructor stub
}

void Acti::trtSousBalise(subRecord* sousEnreg, char* bufferChar){
	if (!memcmp("NAME", sousEnreg->name, 4)) {
		this->name = (char *)malloc(sousEnreg->size + 1);
		memset(this->name,'\0',sousEnreg->size + 1);
		memcpy(this->name, bufferChar, sousEnreg->size);
	} else if (!memcmp("MODL", sousEnreg->name, 4)) {
		this->modelName = (char *)malloc(sousEnreg->size + 1);
		memset(this->modelName,'\0',sousEnreg->size + 1);
		memcpy(this->modelName, bufferChar, sousEnreg->size);
	} else if (!memcmp("FNAM", sousEnreg->name, 4)) {
		this->itemName = (char *)malloc(sousEnreg->size + 1);
		memset(this->itemName,'\0',sousEnreg->size + 1);
		memcpy(this->itemName, bufferChar, sousEnreg->size);
	} else if (!memcmp("SCRI", sousEnreg->name, 4)) {
		this->scriptName = (char *)malloc(sousEnreg->size + 1);
		memset(this->scriptName,'\0',sousEnreg->size + 1);
		memcpy(this->scriptName, bufferChar, sousEnreg->size);
	} else {
		cout << "Erreur ACTI subEnreg " << sousEnreg->name << endl;
	}
}
