/*
 * Cell.h
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#ifndef CELL_H_
#define CELL_H_

#include "defBalises.h"
#include "BaseBalise.h"

class Cell : public BaseBalise {
friend class BaseBalise;
private:
	void trtSousBalise(subRecord* sousEnreg, char* bufferChar);
public:
	Cell();
	virtual ~Cell();
};

#endif /* CELL_H_ */
