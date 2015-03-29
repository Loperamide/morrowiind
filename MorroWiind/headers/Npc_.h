/*
 * Npc_.h
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 */

#ifndef NPC__H_
#define NPC__H_

#include "defBalises.h"
#include "BaseBalise.h"

class Npc_ : public BaseBalise {
friend class BaseBalise;
private:
	void trtSousBalise(subRecord* sousEnreg, char* bufferChar);
public:
	Npc_();
	virtual ~Npc_();
};

#endif /* NPC__H_ */
