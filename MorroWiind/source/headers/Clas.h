/*
 * Clas.h
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#ifndef CLAS_H_
#define CLAS_H_

#include "defBalises.h"
#include "BaseBalise.h"



class Clas : public BaseBalise {
friend class BaseBalise;
private:
	void trtSousBalise(subRecord* sousEnreg, char* bufferChar);
public:
	Clas();
	virtual ~Clas();
private:
	char *name;
	char *itemName;
	data clasData;
	char *desc;
};

#endif /* CLAS_H_ */
