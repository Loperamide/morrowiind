/*
 * Spel.h
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#ifndef SPEL_H_
#define SPEL_H_

#include "defBalises.h"
#include "BaseBalise.h"

class Spel : public BaseBalise {
friend class BaseBalise;
private:
	void trtSousBalise(subRecord* sousEnreg, char* bufferChar);
public:
	Spel();
	virtual ~Spel();
};

#endif /* SPEL_H_ */
