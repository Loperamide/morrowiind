/*
 * Info.cpp
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#include "Info.h"

Info::Info() {
	// TODO Auto-generated constructor stub

}

Info::~Info() {
	// TODO Auto-generated destructor stub
}

void Info::getPosition(FILE* ficEsm, record* enreg){
	fgetpos(ficEsm,&position);
	//fsetpos(ficEsm,position+enreg->size);
}

void Info::trtSousBalise(subRecord* sousEnreg, char* bufferChar){
	if (!memcmp("INAM", sousEnreg->name, 4)) {

	} else if (!memcmp("PNAM", sousEnreg->name, 4)) {
	} else if (!memcmp("NNAM", sousEnreg->name, 4)) {
	} else if (!memcmp("DATA", sousEnreg->name, 4)) {
	} else if (!memcmp("ONAM", sousEnreg->name, 4)) {
	} else if (!memcmp("RNAM", sousEnreg->name, 4)) {
	} else if (!memcmp("CNAM", sousEnreg->name, 4)) {
	} else if (!memcmp("FNAM", sousEnreg->name, 4)) {
	} else if (!memcmp("ANAM", sousEnreg->name, 4)) {
	} else if (!memcmp("DNAM", sousEnreg->name, 4)) {
	} else if (!memcmp("NAME", sousEnreg->name, 4)) {
	} else if (!memcmp("SNAM", sousEnreg->name, 4)) {
	} else if (!memcmp("QSTN", sousEnreg->name, 4)) {
	} else if (!memcmp("QSTF", sousEnreg->name, 4)) {
	} else if (!memcmp("QSTR", sousEnreg->name, 4)) {
	} else if (!memcmp("SCVR", sousEnreg->name, 4)) {
	} else if (!memcmp("INTV", sousEnreg->name, 4)) {
	} else if (!memcmp("FLTV", sousEnreg->name, 4)) {
	} else if (!memcmp("BNAM", sousEnreg->name, 4)) {
	} else {
		cout << "Erreur INFO subEnreg " << sousEnreg->name << endl;
	}
}
