/*
 * Dial.h
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#ifndef DIAL_H_
#define DIAL_H_

#include "defBalises.h"
#include "BaseBalise.h"
#include "Info.h"

class Dial : public BaseBalise {
friend class BaseBalise;
private:
	void trtSousBalise(subRecord* sousEnreg, char* bufferChar);
public:
	Dial();
	virtual ~Dial();
	void push_back(Info *info);
private:
	char *name;
	char *dialdata;
	vector<Info*> lstInfo;
};

#endif /* DIAL_H_ */
