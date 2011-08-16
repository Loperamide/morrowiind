/*
 * Alch.cpp
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#include "headers/Alch.h"

Alch::Alch() {
	// TODO Auto-generated constructor stub

}

Alch::~Alch() {
	// TODO Auto-generated destructor stub
}
void Alch::trtSousBalise(subRecord* sousEnreg, char* bufferChar){
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
	} else if (!memcmp("ALDT", sousEnreg->name, 4)) {
		memcpy(&this->alchdata, bufferChar, sousEnreg->size);
	} else if (!memcmp("ENAM", sousEnreg->name, 4)) {
		alchEnchant alchenchant;
		memcpy(&alchenchant, bufferChar, sousEnreg->size);
		this->alchenchantList.push_back(alchenchant);
	} else if (!memcmp("TEXT", sousEnreg->name, 4)) {
		this->inventoryIcon = (char *)malloc(sousEnreg->size + 1);
		memset(this->inventoryIcon,'\0',sousEnreg->size + 1);
		memcpy(this->inventoryIcon, bufferChar, sousEnreg->size);
	} else if (!memcmp("SCRI", sousEnreg->name, 4)) {
		this->scriptName = (char *)malloc(sousEnreg->size + 1);
		memset(this->scriptName,'\0',sousEnreg->size + 1);
		memcpy(this->scriptName, bufferChar, sousEnreg->size);
	} else {
		cout << "Erreur ALCH subEnreg " << sousEnreg->name << endl;
	}
}
