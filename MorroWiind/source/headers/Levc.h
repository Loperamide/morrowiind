/*
 * Levc.h
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#ifndef LEVC_H_
#define LEVC_H_

#include "defBalises.h"
#include "BaseBalise.h"

class Levc : public BaseBalise {
friend class BaseBalise;
private:
	void trtSousBalise(subRecord* sousEnreg, char* bufferChar);
public:
	Levc();
	virtual ~Levc();
};

#endif /* LEVC_H_ */
