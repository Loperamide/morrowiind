/*
 * Crea.cpp
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#include "headers/Crea.h"

Crea::Crea() {
	// TODO Auto-generated constructor stub

}

Crea::~Crea() {
	// TODO Auto-generated destructor stub
}
void Crea::trtSousBalise(subRecord* sousEnreg, char* bufferChar){
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
	} else if (!memcmp("NPDT", sousEnreg->name, 4)) {
		memcpy(&this->creaData, bufferChar, sousEnreg->size);
	} else if (!memcmp("FLAG", sousEnreg->name, 4)) {
		memcpy(&this->flags, bufferChar, sousEnreg->size);
	} else if (!memcmp("SCRI", sousEnreg->name, 4)) {
		this->script = (char *)malloc(sousEnreg->size + 1);
		memset(this->script,'\0',sousEnreg->size + 1);
		memcpy(this->script, bufferChar, sousEnreg->size);
	} else if (!memcmp("NPCO", sousEnreg->name, 4)) {
		nPco *tmp = (nPco *)malloc(sizeof(nPco));
		memcpy(tmp, bufferChar, sousEnreg->size);
		lstNpco.push_back(tmp);
	} else if (!memcmp("AIDT", sousEnreg->name, 4)) {
		memcpy(this->aidt, bufferChar, sousEnreg->size);
	} else if (!memcmp("AI_W", sousEnreg->name, 4)) {
		memcpy(&this->ai_w, bufferChar, sousEnreg->size);
	} else if (!memcmp("AI_T", sousEnreg->name, 4)) {
		this->ai_t = (char *)malloc(sousEnreg->size + 1);
		memset(this->ai_t,'\0',sousEnreg->size + 1);
		memcpy(this->ai_t, bufferChar, sousEnreg->size);
	} else if (!memcmp("AI_F", sousEnreg->name, 4)) {
		this->ai_f = (char *)malloc(sousEnreg->size + 1);
		memset(this->ai_f,'\0',sousEnreg->size + 1);
		memcpy(this->ai_f, bufferChar, sousEnreg->size);
	} else if (!memcmp("AI_E", sousEnreg->name, 4)) {
		this->ai_e = (char *)malloc(sousEnreg->size + 1);
		memset(this->ai_e,'\0',sousEnreg->size + 1);
		memcpy(this->ai_e, bufferChar, sousEnreg->size);
	} else if (!memcmp("AI_A", sousEnreg->name, 4)) {
		this->ai_a = (char *)malloc(sousEnreg->size + 1);
		memset(this->ai_a,'\0',sousEnreg->size + 1);
		memcpy(this->ai_a, bufferChar, sousEnreg->size);
	} else if (!memcmp("NPCS", sousEnreg->name, 4)) {
		char_32 tmp;
		memset(&tmp,'\0',sousEnreg->size + 1);
		memcpy(&tmp, bufferChar, sousEnreg->size);
		lstNpcs.push_back(tmp);
	} else if (!memcmp("CNAM", sousEnreg->name, 4)) {
		this->sndGenCreature = (char *)malloc(sousEnreg->size + 1);
		memset(this->sndGenCreature,'\0',sousEnreg->size + 1);
		memcpy(this->sndGenCreature, bufferChar, sousEnreg->size);
	} else if (!memcmp("XSCL", sousEnreg->name, 4)) {
		memcpy(&this->size, bufferChar, sousEnreg->size);
	} else {
		cout << "Name : " << this->name << endl;
		cout << "Erreur CREA subEnreg " << sousEnreg->name << endl;
	}
}
