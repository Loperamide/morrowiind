/*
 * Dial.cpp
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#include "headers/Dial.h"

Dial::Dial() {
	// TODO Auto-generated constructor stub

}

Dial::~Dial() {
	// TODO Auto-generated destructor stub
}
void Dial::trtSousBalise(subRecord* sousEnreg, char* bufferChar){
	if (!memcmp("NAME", sousEnreg->name, 4)) {
		this->name = (char *)malloc(sousEnreg->size + 1);
		memset(this->name,'\0',sousEnreg->size + 1);
		memcpy(this->name, bufferChar, sousEnreg->size);
	} else if (!memcmp("DATA", sousEnreg->name, 4)) {
		this->name = (char *)malloc(sousEnreg->size + 1);
		memset(&this->dialdata,'\0',sousEnreg->size + 1);
		memcpy(&this->dialdata, bufferChar, sousEnreg->size);
	} else {
		cout << "Erreur BODY subEnreg " << sousEnreg->name << endl;
	}
}
void Dial::push_back(Info *info){
	lstInfo.push_back(info);
}
