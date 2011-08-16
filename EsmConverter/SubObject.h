/*
 * SubObject.h
 *
 *  Created on: 18 févr. 2011
 *      Author: JPC
 */

#ifndef SUBOBJECT_H_
#define SUBOBJECT_H_

#include "SubRecord.h"

class SubObject {
private:
	char name[100];//Balise
public:
	SubObject();
	virtual ~SubObject();

	char* getName();
	void addSubRecord(SubRecord *subRecord);
private:
	SubRecord *lstSubRecords;
	int nbSubRecords;
};

#endif /* SUBOBJECT_H_ */
