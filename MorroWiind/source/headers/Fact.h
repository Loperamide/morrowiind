/*
 * Fact.h
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#ifndef FACT_H_
#define FACT_H_

#include "defBalises.h"
#include "BaseBalise.h"

class Fact : public BaseBalise {
friend class BaseBalise;
private:
	void trtSousBalise(subRecord* sousEnreg, char* bufferChar);
public:
	Fact();
	virtual ~Fact();
};

#endif /* FACT_H_ */
