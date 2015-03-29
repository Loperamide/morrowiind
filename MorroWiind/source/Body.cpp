/*
 * Body.cpp
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#include "Body.h"

Body::Body() {
	// TODO Auto-generated constructor stub

}

Body::~Body() {
	// TODO Auto-generated destructor stub
}
void Body::trtSousBalise(subRecord* sousEnreg, char* bufferChar){
	if (!memcmp("NAME", sousEnreg->name, 4)) {
		this->name = (char *)malloc(sousEnreg->size + 1);
		memset(this->name,'\0',sousEnreg->size + 1);
		memcpy(this->name, bufferChar, sousEnreg->size);
	} else if (!memcmp("BYDT", sousEnreg->name, 4)) {
		memset(&this->bodydata,'\0',4);
		memcpy(&this->bodydata, bufferChar, sousEnreg->size);
	} else if (!memcmp("MODL", sousEnreg->name, 4)) {
		this->modelName = (char *)malloc(sousEnreg->size + 1);
		memset(this->modelName,'\0',sousEnreg->size + 1);
		memcpy(this->modelName, bufferChar, sousEnreg->size);
	} else if (!memcmp("FNAM", sousEnreg->name, 4)) {
		this->itemName = (char *)malloc(sousEnreg->size + 1);
		memset(this->itemName,'\0',sousEnreg->size + 1);
		memcpy(this->itemName, bufferChar, sousEnreg->size);
	} else {
		cout << "Erreur BODY subEnreg " << sousEnreg->name << endl;
	}
}
