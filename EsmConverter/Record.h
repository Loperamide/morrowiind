/*
 * Record.h
 *
 *  Created on: 14 févr. 2011
 *      Author: jpCapelle
 */

#ifndef RECORD_H_
#define RECORD_H_

#include "SubObject.h"
#include <vector.h>

typedef struct record record;
struct record{
	char name[4];//Balise
	unsigned int size;//Taille de l'enreg
	int header1;//Pas utilisé ?
	int flags;//0x00002000 : Blocked;0x00000400 : Persistant
};

class Record {
private:
	char name[5];//Balise
	int size;//Taille de l'enreg
	int header1;//Pas utilisé ?
	int flags;//0x00002000 : Blocked;0x00000400 : Persistant
private:
	Record();
public:
	Record(record);
	virtual ~Record();

	char* getName();
	int getSize();

	void addSubObject(SubObject subObject);
	SubObject* getSubObject(char* name);
private:
	vector<SubObject> lstSubObjects;
	int nbSubObjects;
};

#endif /* RECORD_H_ */
