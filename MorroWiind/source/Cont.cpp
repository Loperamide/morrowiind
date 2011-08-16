/*
 * Cont.cpp
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#include "headers/Cont.h"

Cont::Cont() {
	// TODO Auto-generated constructor stub

}

Cont::~Cont() {
	// TODO Auto-generated destructor stub
}
void Cont::trtSousBalise(subRecord* sousEnreg, char* bufferChar){
	if (!memcmp("NAME", sousEnreg->name, 4)) {
		this->name = (char *)malloc(sousEnreg->size + 1);
		memset(this->name,'\0',sousEnreg->size + 1);
		memcpy(this->name, bufferChar, sousEnreg->size);
	} else if (!memcmp("MODL", sousEnreg->name, 4)) {
		this->nifModel = (char *)malloc(sousEnreg->size + 1);
		memset(this->nifModel,'\0',sousEnreg->size + 1);
		memcpy(this->nifModel, bufferChar, sousEnreg->size);
	} else if (!memcmp("FNAM", sousEnreg->name, 4)) {
		this->contName = (char *)malloc(sousEnreg->size + 1);
		memset(this->contName,'\0',sousEnreg->size + 1);
		memcpy(this->contName, bufferChar, sousEnreg->size);
	} else if (!memcmp("CNDT", sousEnreg->name, 4)) {
		memcpy(&this->contData, bufferChar, sousEnreg->size);
	} else if (!memcmp("FLAG", sousEnreg->name, 4)) {
		memcpy(&this->contFlags, bufferChar, sousEnreg->size);
	} else if (!memcmp("NPCO", sousEnreg->name, 4)) {
		nPco *tmp = (nPco *)malloc(sizeof(nPco));
		memcpy(tmp, bufferChar, sousEnreg->size);
		lstNpco.push_back(tmp);
	} else if (!memcmp("SCRI", sousEnreg->name, 4)) {
		this->scriId = (char *)malloc(sousEnreg->size + 1);
		memset(this->scriId,'\0',sousEnreg->size + 1);
		memcpy(this->scriId, bufferChar, sousEnreg->size);
	} else {
		cout << "Erreur CONT subEnreg " << sousEnreg->name << endl;
	}
}
