/*
 * Levi.h
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#ifndef LEVI_H_
#define LEVI_H_

#include "defBalises.h"
#include "BaseBalise.h"

class Levi : public BaseBalise {
friend class BaseBalise;
private:
	void trtSousBalise(subRecord* sousEnreg, char* bufferChar);
public:
	Levi();
	virtual ~Levi();
};

#endif /* LEVI_H_ */
