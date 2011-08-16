/*
 * Glob.h
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#ifndef GLOB_H_
#define GLOB_H_

#include "defBalises.h"
#include "BaseBalise.h"

class Glob : public BaseBalise {
friend class BaseBalise;
private:
	void trtSousBalise(subRecord* sousEnreg, char* bufferChar);
public:
	Glob();
	virtual ~Glob();
private:
	char *name;
	char type;
	float value;
};

#endif /* GLOB_H_ */
