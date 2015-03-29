/*
 * Alch.h
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#ifndef ALCH_H_
#define ALCH_H_

#include "defBalises.h"
#include "BaseBalise.h"

class Alch : public BaseBalise {
friend class BaseBalise;
private:
	void trtSousBalise(subRecord* sousEnreg, char* bufferChar);
public:
	Alch();
	virtual ~Alch();
private:
	char *name;
	char *modelName;
	char *itemName;
	alchData alchdata;
	vector<alchEnchant> alchenchantList;
	char *inventoryIcon;
	char *scriptName;
};

#endif /* ALCH_H_ */
