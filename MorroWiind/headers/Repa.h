/*
 * Repa.h
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#ifndef REPA_H_
#define REPA_H_

#include "defBalises.h"
#include "BaseBalise.h"

class Repa : public BaseBalise {
friend class BaseBalise;
private:
	void trtSousBalise(subRecord* sousEnreg, char* bufferChar);
public:
	Repa();
	virtual ~Repa();
};

#endif /* REPA_H_ */
