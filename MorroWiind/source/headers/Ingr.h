/*
 * Ingr.h
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#ifndef INGR_H_
#define INGR_H_

#include "defBalises.h"
#include "BaseBalise.h"

class Ingr : public BaseBalise {
friend class BaseBalise;
private:
	void trtSousBalise(subRecord* sousEnreg, char* bufferChar);
public:
	Ingr();
	virtual ~Ingr();
};

#endif /* INGR_H_ */
