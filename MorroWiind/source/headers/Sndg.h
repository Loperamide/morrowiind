/*
 * Sndg.h
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#ifndef SNDG_H_
#define SNDG_H_

#include "defBalises.h"
#include "BaseBalise.h"

class Sndg : public BaseBalise {
friend class BaseBalise;
private:
	void trtSousBalise(subRecord* sousEnreg, char* bufferChar);
public:
	Sndg();
	virtual ~Sndg();
};

#endif /* SNDG_H_ */
