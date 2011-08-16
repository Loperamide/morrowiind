/*
 * SubObject.cpp
 *
 *  Created on: 18 févr. 2011
 *      Author: JPC
 */

#include "SubObject.h"

#include <iostream>

SubObject::SubObject() {
	// TODO Auto-generated constructor stub
	nbSubRecords = 0;
	strcpy(name,"  ");

}

SubObject::~SubObject() {
	// TODO Auto-generated destructor stub
}

char * SubObject::getName() {
	return name;
}
