/*
 * Land.h
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#ifndef LAND_H_
#define LAND_H_

#include "defBalises.h"
#include "BaseBalise.h"

class Land : public BaseBalise {
friend class BaseBalise;
private:
	void trtSousBalise(subRecord* sousEnreg, char* bufferChar);
public:
	Land();
	virtual ~Land();
};

#endif /* LAND_H_ */
