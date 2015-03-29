/*
 * Misc.h
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#ifndef MISC_H_
#define MISC_H_

#include "defBalises.h"
#include "BaseBalise.h"

class Misc : public BaseBalise {
friend class BaseBalise;
private:
	void trtSousBalise(subRecord* sousEnreg, char* bufferChar);
public:
	Misc();
	virtual ~Misc();
};

#endif /* MISC_H_ */
