/*
 * Ligh.h
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#ifndef LIGH_H_
#define LIGH_H_

#include "defBalises.h"
#include "BaseBalise.h"

class Ligh : public BaseBalise {
friend class BaseBalise;
private:
	void trtSousBalise(subRecord* sousEnreg, char* bufferChar);
public:
	Ligh();
	virtual ~Ligh();
};

#endif /* LIGH_H_ */
