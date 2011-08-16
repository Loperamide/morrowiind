/*
 * Record.cpp
 *
 *  Created on: 14 févr. 2011
 *      Author: jpCapelle
 */

#include "Record.h"
#include <string.h>
#include <stdlib.h>

#include <iostream>
using namespace std;

Record::Record() {
	// TODO Auto-generated constructor stub
}

Record::Record(record balise) {
	memcpy(name, balise.name, 4);
	name[4]='\0';

	nbSubObjects = 0;

	size = balise.size;
}

Record::~Record() {
	// TODO Auto-generated destructor stub
}

char* Record::getName() {
	return name;
}

int Record::getSize() {
	return size;
}

void Record::addSubObject(SubObject subObject){
	nbSubObjects++;
	lstSubObjects.resize(nbSubObjects);
	lstSubObjects.push_back(subObject);
}

SubObject* Record::getSubObject(char* name){
	for (int x=0;x < nbSubObjects;x++) {
		if (!strncmp(lstSubObjects.at(x).getName(), name, strlen(name))){
			return &lstSubObjects.at(x);
		}
	}
}
