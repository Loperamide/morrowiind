/*
 * defBalises.cpp
 *
 *  Created on: 16 mars 2011
 *      Author: jpCapelle
 */
#include "defBalises.h"

DefBalises::DefBalises(){
	// TODO Auto-generated constructor stub
}

DefBalises::~DefBalises(){
	// TODO Auto-generated constructor stub
}


bool DefBalises::isSousBalise(char *balise) {
	bool retour = false;
	for(unsigned int x=0;x<sizeof(lstSousBalises)/5;x++){
		if (!strncmp(lstSousBalises[x],balise,4)){
			retour = true;
			break;
		}
	}
	return retour;
}

bool DefBalises::isBalise(char *balise) {
	bool retour = false;
	for(unsigned int x=0;x<sizeof(lstBalises)/4;x++){
		if (!strncmp(lstBalises[x],balise,4)){
			retour = true;
			break;
		}
	}
	return retour;
}

