/*
 * Scpt.h
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#ifndef SCPT_H_
#define SCPT_H_

#include "defBalises.h"
#include "BaseBalise.h"

class Scpt : public BaseBalise {
friend class BaseBalise;
private:
	void trtSousBalise(subRecord* sousEnreg, char* bufferChar);
public:
	Scpt();
	virtual ~Scpt();
};

#endif /* SCPT_H_ */
