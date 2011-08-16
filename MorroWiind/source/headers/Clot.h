/*
 * Clot.h
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#ifndef CLOT_H_
#define CLOT_H_

#include "defBalises.h"
#include "BaseBalise.h"

class Clot : public BaseBalise {
friend class BaseBalise;
private:
	void trtSousBalise(subRecord* sousEnreg, char* bufferChar);
	void openIndx(subRecord* sousEnreg, char* bufferChar);
	void closeIndx(subRecord* sousEnreg, char* bufferChar);
public:
	Clot();
	virtual ~Clot();
	void closeIndx();
private:
	char *name;
	char *modelName;
	char *itemName;
	clothData clothdata;
	char *iconName;
	vector<bdyPart> bdyPartList;
	char *scriptName;
	char *enchantName;

	bdyPart tmpBdyPart;
	bool tmpBdyPartOpen;

};

#endif /* CLOT_H_ */
