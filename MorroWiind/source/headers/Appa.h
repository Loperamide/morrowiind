/*
 * Appa.h
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#ifndef APPA_H_
#define APPA_H_

#include "defBalises.h"
#include "BaseBalise.h"


class Appa : public BaseBalise {
friend class BaseBalise;
private:
	void trtSousBalise(subRecord* sousEnreg, char* bufferChar);
public:
	Appa();
	virtual ~Appa();
private:
	char *name;
	char *modelName;
	char *itemName;
	appaData alchdata;
	char *inventoryIcon;
	char *scriptName;
};

#endif /* APPA_H_ */
