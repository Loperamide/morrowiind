/*
 * Scpt.h
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#ifndef SCPT_H_
#define SCPT_H_

#include "defBalises.h"
#include "BaseBalise.h"

typedef struct baliseSchd baliseSchd;
struct baliseSchd {
	char Name[32];
	long NumShorts;
	long NumLongs;
	long NumFloats;
	long ScriptDataSize;
	long LocalVarSize;
};

class Scpt : public BaseBalise {
friend class BaseBalise;
private:
	void trtSousBalise(subRecord* sousEnreg, char* bufferChar);
public:
	Scpt();
	virtual ~Scpt();
private:
	baliseSchd header;
};

#endif /* SCPT_H_ */
