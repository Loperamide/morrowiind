/*
 * Book.h
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#ifndef BOOK_H_
#define BOOK_H_

#include "defBalises.h"
#include "BaseBalise.h"

class Book : public BaseBalise {
friend class BaseBalise;
private:
	void trtSousBalise(subRecord* sousEnreg, char* bufferChar);
public:
	Book();
	virtual ~Book();
};

#endif /* BOOK_H_ */
