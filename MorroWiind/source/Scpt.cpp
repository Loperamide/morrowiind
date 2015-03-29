/*
 * Scpt.cpp
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#include "Scpt.h"

Scpt::Scpt() {
	// TODO Auto-generated constructor stub

}

Scpt::~Scpt() {
	// TODO Auto-generated destructor stub
}
void Scpt::trtSousBalise(subRecord* sousEnreg, char* bufferChar){
	if (!memcmp("SCHD", sousEnreg->name, 4)) {
		memcpy(&this->header, bufferChar, sousEnreg->size);

		char name[33];
		strncpy(name,this->header.Name,32);
		name[32] = '\0';
		cout << endl;
		cout << "SCHD : " << endl;
		cout << "Name : " << this->header.Name << endl;
		cout << "NumShorts : " << this->header.NumShorts << endl;
		cout << "NumLongs : " << this->header.NumLongs << endl;
		cout << "NumFloats : " << this->header.NumFloats << endl;
		cout << "ScriptDataSize : " << this->header.ScriptDataSize << endl;
		cout << "LocalVarSize : " << this->header.LocalVarSize << endl;
	} else if (!memcmp("SCVR", sousEnreg->name, 4)) {
		char *liste;
		liste = (char *)malloc(sousEnreg->size + 1);
		memset(liste,'\0',sousEnreg->size + 1);
		memcpy(liste, bufferChar, sousEnreg->size);
		cout << "SCVR : " << liste << endl;
	} else if (!memcmp("SCDT", sousEnreg->name, 4)) {
		char *liste;
		liste = (char *)malloc(sousEnreg->size + 1);
		memset(liste,'\0',sousEnreg->size + 1);
		memcpy(liste, bufferChar, sousEnreg->size);
		cout << "SCDT : " << liste << endl;
	} else if (!memcmp("SCTX", sousEnreg->name, 4)) {
		char *liste;
		liste = (char *)malloc(sousEnreg->size + 1);
		memset(liste,'\0',sousEnreg->size + 1);
		memcpy(liste, bufferChar, sousEnreg->size);
		cout << "SCTX : " << liste << endl;
	} else {
		cout << "Erreur SCPT subEnreg " << sousEnreg->name << endl;
	}

}
