/*
 * Weap.h
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#ifndef WEAP_H_
#define WEAP_H_

#include "defBalises.h"
#include "BaseBalise.h"

class Weap : public BaseBalise {
friend class BaseBalise;
private:
	void trtSousBalise(subRecord* sousEnreg, char* bufferChar);
public:
	Weap();
	virtual ~Weap();
};

#endif /* WEAP_H_ */
