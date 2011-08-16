/*
 * Prob.h
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#ifndef PROB_H_
#define PROB_H_

#include "defBalises.h"
#include "BaseBalise.h"

class Prob : public BaseBalise {
friend class BaseBalise;
private:
	void trtSousBalise(subRecord* sousEnreg, char* bufferChar);
public:
	Prob();
	virtual ~Prob();
};

#endif /* PROB_H_ */
