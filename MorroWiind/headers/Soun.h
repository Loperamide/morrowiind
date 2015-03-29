/*
 * Soun.h
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#ifndef SOUN_H_
#define SOUN_H_

#include "defBalises.h"
#include "BaseBalise.h"

class Soun : public BaseBalise {
friend class BaseBalise;
private:
	void trtSousBalise(subRecord* sousEnreg, char* bufferChar);
public:
	Soun();
	virtual ~Soun();
};

#endif /* SOUN_H_ */
