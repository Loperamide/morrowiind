/*
 * Door.h
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#ifndef DOOR_H_
#define DOOR_H_

#include "defBalises.h"
#include "BaseBalise.h"

class Door : public BaseBalise {
friend class BaseBalise;
private:
	void trtSousBalise(subRecord* sousEnreg, char* bufferChar);
public:
	Door();
	virtual ~Door();
};

#endif /* DOOR_H_ */
