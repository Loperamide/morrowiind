/*
 * Info.h
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#ifndef INFO_H_
#define INFO_H_

#include "defBalises.h"
#include "BaseBalise.h"

typedef struct infoData infoData;
struct infoData{
	int uk1;//Non défini
	int disposition;
	char rank;
	char gender;
	char pcrank;
	char uk2;//Non défini
};

typedef struct infoSvcr infoSvcr;
struct infoSvcr{
	char index;
	char type;
	char functype[2];
	char compareop;
	char *name;
};

class Info : public BaseBalise {
friend class BaseBalise;
private:
	void trtSousBalise(subRecord* sousEnreg, char* bufferChar);
public:
	Info();
	virtual ~Info();
	void getPosition(FILE* ficEsm, record* enreg);
private:
	fpos_t position;

	char *inam;
	char *pnam;
	char *nnam;
	infoData infodata;
	char *onam;
	char *rnam;
	char *cnam;
	char *fnam;
	char *anam;
	char *dnam;
	char *name;
	char *snam;
	char qstn;
	char qstf;
	char qstr;
	infoSvcr infosvcr;
	int intv;
	float fltv;
	char *bnam;
};

#endif /* INFO_H_ */
