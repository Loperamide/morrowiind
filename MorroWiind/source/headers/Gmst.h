/*
 * Gmst.h
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#ifndef GMST_H_
#define GMST_H_

#include "defBalises.h"
#include "BaseBalise.h"

class Gmst : public BaseBalise {
friend class BaseBalise;
private:
	void trtSousBalise(subRecord* sousEnreg, char* bufferChar);
public:
	Gmst();
	virtual ~Gmst();
};

#endif /* GMST_H_ */
