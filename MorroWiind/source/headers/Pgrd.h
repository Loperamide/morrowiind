/*
 * Pgrd.h
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#ifndef PGRD_H_
#define PGRD_H_

#include "defBalises.h"
#include "BaseBalise.h"

class Pgrd : public BaseBalise {
friend class BaseBalise;
private:
	void trtSousBalise(subRecord* sousEnreg, char* bufferChar);
public:
	Pgrd();
	virtual ~Pgrd();
};

#endif /* PGRD_H_ */
