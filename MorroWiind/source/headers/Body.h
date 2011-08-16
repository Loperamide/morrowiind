/*
 * Body.h
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#ifndef BODY_H_
#define BODY_H_

#include "defBalises.h"
#include "BaseBalise.h"


class Body : public BaseBalise {
friend class BaseBalise;
private:
	void trtSousBalise(subRecord* sousEnreg, char* bufferChar);
public:
	Body();
	virtual ~Body();
private:
	char *name;
	bodyData bodydata;
	char *modelName;
	char *itemName;
};

#endif /* BODY_H_ */
