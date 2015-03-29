/*
 * Armo.h
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#ifndef ARMO_H_
#define ARMO_H_

#include "defBalises.h"
#include "BaseBalise.h"


class Armo : public BaseBalise {
friend class BaseBalise;
private:
	void trtSousBalise(subRecord* sousEnreg, char* bufferChar);
	void openIndx(subRecord* sousEnreg, char* bufferChar);
	void closeIndx(subRecord* sousEnreg, char* bufferChar);
public:
	Armo();
	virtual ~Armo();
	void closeIndx();
private:
	char *name;
	char *modelName;
	char *itemName;
	armourData armourdata;
	char *iconName;
	vector<bdyPart> bdyPartList;
	char *scriptName;
	char *enchantName;

	bdyPart tmpBdyPart;
	bool tmpBdyPartOpen;
};

#endif /* ARMO_H_ */
