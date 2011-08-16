/*
 * SubRecord.cpp
 *
 *  Created on: 14 févr. 2011
 *      Author: jpCapelle
 */

#include "SubRecord.h"

#include <string.h>
#include <stdlib.h>

#include <iostream>
using namespace std;

SubRecord::SubRecord() {
	// TODO Auto-generated constructor stub

}

SubRecord::SubRecord(subRecord balise) {
	memcpy(name, balise.name, 4);
	name[4]='\0';

	size = balise.size;
}

SubRecord::~SubRecord() {
	// TODO Auto-generated destructor stub
}

char* SubRecord::getName() {
	return name;
}

int SubRecord::getSize() {
	return size;
}
