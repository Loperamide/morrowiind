/*
 * Glob.cpp
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#include "headers/Glob.h"
#include "headers/defBalises.h"

Glob::Glob() {
	// TODO Auto-generated constructor stub

}

Glob::~Glob() {
	// TODO Auto-generated destructor stub
	free(this->name);
}
void Glob::trtSousBalise(subRecord* sousEnreg, char* bufferChar){
	if (!memcmp("NAME", sousEnreg->name, 4)) {
		this->name = (char *)malloc(sousEnreg->size + 1);
		memset(this->name,'\0',sousEnreg->size + 1);
		memcpy(this->name, bufferChar, sousEnreg->size);
	} else if (!memcmp("FNAM", sousEnreg->name, 4)) {
		memcpy(&this->type, bufferChar, sousEnreg->size);
	} else if (!memcmp("FLTV", sousEnreg->name, 4)) {
		memcpy(&this->value, bufferChar, sousEnreg->size);
	}
}
