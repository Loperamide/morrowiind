/*
 * Stat.h
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#ifndef STAT_H_
#define STAT_H_

#include "defBalises.h"
#include "BaseBalise.h"

class Stat : public BaseBalise {
friend class BaseBalise;
private:
	void trtSousBalise(subRecord* sousEnreg, char* bufferChar);
public:
	Stat();
	virtual ~Stat();
};

#endif /* STAT_H_ */
