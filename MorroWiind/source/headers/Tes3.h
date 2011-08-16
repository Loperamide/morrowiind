/*
 * Tes3.h
 *
 *  Created on: 14 mars 2011
 *      Author: jpCapelle
 *
 *  Reférence le contenu des fichiers TES3.
 *  1 seule instance, les fichiers TES3 complémentaires au Master viennent remplacer les occurences au besoin.
 *  Sont chargés en mémoire les balises :
 *  GMST, GLOB, CLAS, FACT, RACE, SOUN, SKIL, MGEF, SCPT, REGN, BSGN, LTEX, STAT, DOOR, MISC, WEAP, CONT, SPEL, CREA,
 *  BODY, LIGH, ENCH, ARMO, CLOT, REPA, ACTI, APPA, LOCK, PROB, INGR, ALCH, LEVI, LEVC, SNDG, DIAL
 *  On ne charge que les références (fichier, identifiant, position) pour les balises :
 *  NPC_, BOOK, CELL, LAND, PGRD, INFO
 */

#ifndef TES3_H_
#define TES3_H_

#include "global.h"
#include "Singleton.h"
#include "AllBalises.h"
#include "defBalises.h"
#include "BaseBalise.h"
#include <iostream>

class Tes3 : public Singleton<Tes3>,public BaseBalise {
friend class Singleton<Tes3>;
friend class BaseBalise;
protected:
	Tes3();
	virtual ~Tes3();

public:
	bool loadFile(const char *fichier);
private:
	void createObject(record* enreg);
	void trtSousBalise(subRecord* sousEnreg, char* bufferChar);
private:
	vector<Gmst*> lstGmst;
	vector<Glob*> lstGlob;
	vector<Clas*> lstClas;
	vector<Fact*> lstFact;
	vector<Race*> lstRace;
	vector<Soun*> lstSoun;
	vector<Skil*> lstSkil;
	vector<Mgef*> lstMgef;
	vector<Scpt*> lstScpt;
	vector<Regn*> lstRegn;
	vector<Bsgn*> lstBsgn;
	vector<Stat*> lstStat;
	vector<Door*> lstDoor;
	vector<Misc*> lstMisc;
	vector<Weap*> lstWeap;
	vector<Cont*> lstCont;
	vector<Spel*> lstSpel;
	vector<Crea*> lstCrea;
	vector<Body*> lstBody;
	vector<Ligh*> lstLigh;
	vector<Ench*> lstEnch;
	vector<Armo*> lstArmo;
	vector<Clot*> lstClot;
	vector<Repa*> lstRepa;
	vector<Acti*> lstActi;
	vector<Appa*> lstAppa;
	vector<Lock*> lstLock;
	vector<Prob*> lstProb;
	vector<Ingr*> lstIngr;
	vector<Alch*> lstAlch;
	vector<Levi*> lstLevi;
	vector<Levc*> lstLevc;
	vector<Sndg*> lstSndg;
	vector<Dial*> lstDial;
	vector<Npc_*> lstNpc_;
	vector<Book*> lstBook;
	vector<Cell*> lstCell;
	vector<Land*> lstLand;
	vector<Pgrd*> lstPgrd;
	vector<Info*> lstInfo;
	vector<Ltex*> lstLtex;

	FILE *ficEsm;
};

#endif /* TES3_H_ */
