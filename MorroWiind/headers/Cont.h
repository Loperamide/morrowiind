/*
 * Cont.h
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#ifndef CONT_H_
#define CONT_H_

#include "defBalises.h"
#include "BaseBalise.h"

class Cont : public BaseBalise {
friend class BaseBalise;
private:
	void trtSousBalise(subRecord* sousEnreg, char* bufferChar);
public:
	Cont();
	virtual ~Cont();
private:
	char *name;
	char *nifModel;
	char *contName;
	float contData;
	int contFlags;
	vector<nPco *> lstNpco;
	char *scriId;
};

#endif /* CONT_H_ */
