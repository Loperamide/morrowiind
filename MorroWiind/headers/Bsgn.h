/*
 * Bsgn.h
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#ifndef BSGN_H_
#define BSGN_H_

#include "defBalises.h"
#include "BaseBalise.h"

class Bsgn : public BaseBalise {
friend class BaseBalise;
private:
	void trtSousBalise(subRecord* sousEnreg, char* bufferChar);
public:
	Bsgn();
	virtual ~Bsgn();
private:
	char *name;
	char *itemName;
	char *textureName;
	char *desc;
	vector<char *> lstAbility;
};

#endif /* BSGN_H_ */
