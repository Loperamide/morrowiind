/*
 * Clot.cpp
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#include "headers/Clot.h"

Clot::Clot() {
	// TODO Auto-generated constructor stub

}

Clot::~Clot() {
	// TODO Auto-generated destructor stub
}
void Clot::trtSousBalise(subRecord* sousEnreg, char* bufferChar){
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
	} else if (!memcmp("CTDT", sousEnreg->name, 4)) {
		memcpy(&this->clothdata, bufferChar, sousEnreg->size);
	} else if (!memcmp("ITEX", sousEnreg->name, 4)) {
		this->iconName = (char *)malloc(sousEnreg->size + 1);
		memset(this->iconName,'\0',sousEnreg->size + 1);
		memcpy(this->iconName, bufferChar, sousEnreg->size);
	} else if (!memcmp("INDX", sousEnreg->name, 4)) {
		openIndx(sousEnreg,bufferChar);
	} else if (!memcmp("BNAM", sousEnreg->name, 4)) {
		closeIndx(sousEnreg,bufferChar);
	} else if (!memcmp("CNAM", sousEnreg->name, 4)) {
		closeIndx(sousEnreg,bufferChar);
	} else if (!memcmp("ENAM", sousEnreg->name, 4)) {
		this->enchantName = (char *)malloc(sousEnreg->size + 1);
		memset(this->enchantName,'\0',sousEnreg->size + 1);
		memcpy(this->enchantName, bufferChar, sousEnreg->size);
	} else if (!memcmp("SCRI", sousEnreg->name, 4)) {
		this->scriptName = (char *)malloc(sousEnreg->size + 1);
		memset(this->scriptName,'\0',sousEnreg->size + 1);
		memcpy(this->scriptName, bufferChar, sousEnreg->size);
	} else {
		cout << "Erreur CLOT subEnreg " << sousEnreg->name << endl;
	}
}
void Clot::openIndx(subRecord* sousEnreg, char* bufferChar){
	if (tmpBdyPartOpen){
		closeIndx(sousEnreg,bufferChar);
	}
	tmpBdyPartOpen = true;
	memcpy(&this->tmpBdyPart.bdyPartIndex,bufferChar,1);
	this->tmpBdyPart.bdyPartNameMale = NULL;
	this->tmpBdyPart.bdyPartNameFemale = NULL;
}
void Clot::closeIndx(subRecord* sousEnreg, char* bufferChar){
	if (tmpBdyPartOpen){
		if (!memcmp("BNAM", sousEnreg->name, 4)) {
			this->tmpBdyPart.bdyPartNameMale = (char*)malloc(sousEnreg->size+1);
			memset(this->tmpBdyPart.bdyPartNameMale,'\0',sousEnreg->size + 1);
			memcpy(this->tmpBdyPart.bdyPartNameMale, bufferChar, sousEnreg->size);
		} else if (!memcmp("CNAM", sousEnreg->name, 4)) {
			this->tmpBdyPart.bdyPartNameFemale = (char*)malloc(sousEnreg->size+1);
			memset(this->tmpBdyPart.bdyPartNameFemale,'\0',sousEnreg->size + 1);
			memcpy(this->tmpBdyPart.bdyPartNameFemale, bufferChar, sousEnreg->size);
		}
		this->bdyPartList.push_back(tmpBdyPart);
		tmpBdyPartOpen = false;
	}
}
void Clot::closeIndx(){
	if (tmpBdyPartOpen){
		this->bdyPartList.push_back(tmpBdyPart);
		tmpBdyPartOpen = false;
	}
}
