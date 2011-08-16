/*
 * BaseBalise.h
 *
 *  Created on: 11 avr. 2011
 *      Author: jpCapelle
 */

#ifndef BASEBALISE_H_
#define BASEBALISE_H_

#include "defBalises.h"

class BaseBalise {
protected:
	BaseBalise();
	virtual ~BaseBalise();
public:
	void getSousBalises(FILE* ficEsm, record* enreg);
protected:
	virtual void trtSousBalise(subRecord* sousEnreg, char* bufferChar) = 0;
};

#endif /* BASEBALISE_H_ */
