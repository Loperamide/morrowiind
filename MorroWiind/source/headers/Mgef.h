/*
 * Mgef.h
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#ifndef MGEF_H_
#define MGEF_H_

#include "defBalises.h"
#include "BaseBalise.h"

class Mgef : public BaseBalise {
friend class BaseBalise;
private:
	void trtSousBalise(subRecord* sousEnreg, char* bufferChar);
public:
	Mgef();
	virtual ~Mgef();
};

#endif /* MGEF_H_ */
