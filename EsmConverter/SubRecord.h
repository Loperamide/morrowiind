/*
 * SubRecord.h
 *
 *  Created on: 14 févr. 2011
 *      Author: jpCapelle
 */

#ifndef SUBRECORD_H_
#define SUBRECORD_H_

typedef struct subRecord subRecord;
struct subRecord{
	char name[4];//Balise
	int size;//Taille de l'enreg
};

class SubRecord{
private:
	char name[5];//Balise
	int size;//Taille de l'enreg
public:
	SubRecord();
	SubRecord(subRecord);
	virtual ~SubRecord();
	SubRecord& operator=(SubRecord& me);

	char* getName();
	int getSize();
};

#endif /* SUBRECORD_H_ */
