/*
 * Ench.h
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#ifndef ENCH_H_
#define ENCH_H_

#include "defBalises.h"
#include "BaseBalise.h"

class Ench : public BaseBalise {
friend class BaseBalise;
private:
	void trtSousBalise(subRecord* sousEnreg, char* bufferChar);
public:
	Ench();
	virtual ~Ench();
};

#endif /* ENCH_H_ */
