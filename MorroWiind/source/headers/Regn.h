/*
 * Regn.h
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#ifndef REGN_H_
#define REGN_H_

#include "defBalises.h"
#include "BaseBalise.h"

class Regn : public BaseBalise {
friend class BaseBalise;
private:
	void trtSousBalise(subRecord* sousEnreg, char* bufferChar);
public:
	Regn();
	virtual ~Regn();
};

#endif /* REGN_H_ */
