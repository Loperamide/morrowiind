/*
 * Lock.h
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#ifndef LOCK_H_
#define LOCK_H_

#include "defBalises.h"
#include "BaseBalise.h"

class Lock : public BaseBalise {
friend class BaseBalise;
private:
	void trtSousBalise(subRecord* sousEnreg, char* bufferChar);
public:
	Lock();
	virtual ~Lock();
};

#endif /* LOCK_H_ */
