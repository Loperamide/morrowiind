/*
 * Acti.h
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#ifndef ACTI_H_
#define ACTI_H_

#include "defBalises.h"
#include "BaseBalise.h"

class Acti : public BaseBalise {
friend class BaseBalise;
private:
	void trtSousBalise(subRecord* sousEnreg, char* bufferChar);
public:
	Acti();
	virtual ~Acti();
private:
	char *name;
	char *modelName;
	char *itemName;
	char *scriptName;
};

#endif /* ACTI_H_ */
