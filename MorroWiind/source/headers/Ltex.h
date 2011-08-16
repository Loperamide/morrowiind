/*
 * Ltex.h
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#ifndef LTEX_H_
#define LTEX_H_

#include "defBalises.h"
#include "BaseBalise.h"

class Ltex : public BaseBalise {
friend class BaseBalise;
private:
	void trtSousBalise(subRecord* sousEnreg, char* bufferChar);
public:
	Ltex();
	virtual ~Ltex();
};

#endif /* LTEX_H_ */
