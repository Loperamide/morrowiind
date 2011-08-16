/*
 * Crea.h
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#ifndef CREA_H_
#define CREA_H_

#include "defBalises.h"
#include "BaseBalise.h"

typedef struct char_32 char_32;
struct char_32{
	char chaine[32];
};

class Crea : public BaseBalise {
friend class BaseBalise;
private:
	void trtSousBalise(subRecord* sousEnreg, char* bufferChar);
public:
	Crea();
	virtual ~Crea();

private:
	char *name;
	char *modelName;
	char *itemName;
	creadata creaData;
	int flags;
	char *script;
	vector<nPco *> lstNpco;
	vector<char_32> lstNpcs;
	char aidt[12];
	ai_W ai_w;
	char *ai_t;
	char *ai_f;
	char *ai_e;
	char *ai_a;
	float size;
	char *sndGenCreature;
};

#endif /* CREA_H_ */
