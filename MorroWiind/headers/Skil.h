/*
 * Skil.h
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#ifndef SKIL_H_
#define SKIL_H_

#include "defBalises.h"
#include "BaseBalise.h"

class Skil : public BaseBalise {
friend class BaseBalise;
private:
	void trtSousBalise(subRecord* sousEnreg, char* bufferChar);
public:
	Skil();
	virtual ~Skil();
};

#endif /* SKIL_H_ */
