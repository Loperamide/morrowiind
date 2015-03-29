/*
 * Race.h
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#ifndef RACE_H_
#define RACE_H_

#include "defBalises.h"
#include "BaseBalise.h"

class Race : public BaseBalise {
friend class BaseBalise;
private:
	void trtSousBalise(subRecord* sousEnreg, char* bufferChar);
public:
	Race();
	virtual ~Race();
};

#endif /* RACE_H_ */
