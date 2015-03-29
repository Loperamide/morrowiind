/*
 * defBalises.h
 *
 *  Created on: 16 mars 2011
 *      Author: jpCapelle
 */

#ifndef DEFBALISES_H_
#define DEFBALISES_H_

#include "Singleton.h"

typedef char baliseName[5];

typedef struct record record;
struct record{
	char name[4];//Balise
	unsigned int size;//Taille de l'enreg
	int header1;//Pas utilisé ?
	int flags;//0x00002000 : Blocked;0x00000400 : Persistant
};
typedef struct subRecord subRecord;
struct subRecord{
	char name[4];//Balise
	int size;//Taille de l'enreg
};
typedef struct nPco nPco;
struct nPco{
	int nbItem;
	char nameItem[32];
};
typedef struct alchData alchData;
struct alchData {
	float weight;
	int value;
	int autocalc;
};

typedef struct alchEnchant alchEnchant;
struct alchEnchant {
	short effectId;
	char skillId;
	char attributeId;
	int un1;
	int un2;
	int duration;
	int magnitude;
	int un3;
};
typedef struct appaData appaData;
struct appaData{
	int type;
	float quality;
	float weight;
	int value;
};
typedef struct armourData armourData;
struct armourData{
	int type;
	float weight;
	int value;
	int health;
	int enchantPoints;
	int armour;
};
typedef struct bodyData bodyData;
struct bodyData{
	char part;
	char vampire;
	char flags;
	char partType;
};
typedef struct data data;
struct data{
	int attribId1;
	int attribId2;
	int specialisation;
	int minorId1;
	int majorId1;
	int minorId2;
	int majorId2;
	int minorId3;
	int majorId3;
	int minorId4;
	int majorId4;
	int minorId5;
	int majorId5;
	int flags;
	int AutoCalcFlags;
};
typedef struct clothData clothData;
struct clothData{
	long type;
	float weight;
	short value;
	short enchantpts;
};

typedef struct bdyPart bdyPart;
struct bdyPart{
	char bdyPartIndex;
	char *bdyPartNameMale;
	char *bdyPartNameFemale;
};
typedef struct ai_W ai_W;
struct ai_W{
	short distance;
	char duration;
	char timeOfDay;
	char idle[10];
};
typedef struct creadata creadata;
struct creadata{
	int type;
	int level;
	int strength;
	int intelligence;
	int willpower;
	int agility;
	int speed;
	int endurance;
	int personality;
	int luck;
	int health;
	int spellpoints;
	int fatigue;
	int soul;
	int combat;
	int magic;
	int stealth;
	int atckmin1;
	int atckmax1;
	int atckmin2;
	int atckmax2;
	int atckmin3;
	int atckmax3;
	int gold;
};

const baliseName lstBalises[]={"ACTI","ALCH","APPA","ARMO",
		"BODY","BOOK","BSGN",
		"CELL","CLAS","CLOT","CONT","CREA",
		"DIAL","DOOR",
		"ENCH",
		"FACT",
		"GLOB","GMST",
		"INFO","INGR",
		"LAND","LEVC","LEVI","LIGH","LOCK","LTEX",
		"MGEF","MISC",
		"NPC_",
		"PGRD","PROB",
		"RACE","REGN","REPA",
		"SCPT","SKIL","SNDG","SOUN","SPEL","STAT",
		"TES3",
		"WEAP"};
const baliseName lstSousBalises[]={"AADT","AI_A","AI_E","AI_F","AI_T","AI_W","AIDT","ALDT","AMBI","ANAM","AODT","ASND","AVFX",
		"BKDT","BNAM","BSND","BVFX","BYDT",
		"CLDT","CNAM","CNDT","CSND","CTDT","CVFX",
		"DATA","DELE","DESC","DNAM","DODT",
		"ENAM","ENDT",
		"FADT","FLAG","FLTV","FNAM","FRMR",
		"HEDR","HSND","HVFX",
		"INAM","INDX","INTV","IRDT","ITEX",
		"KNAM",
		"LHDT","LKDT",
		"MAST","MCDT","MEDT","MODL",
		"NAM0","NAM5","NAM9","NAME","NNAM","NPCO","NPCS","NPDT",
		"ONAM",
		"PBDT","PGRC","PGRP","PNAM","PTEX",
		"QSTF","QSTN","QSTR",
		"RADT","RGNN","RIDT","RNAM",
		"SCHD","SCIP","SCRI","SCPT","SCVR","SCDT","SCTX","SKDT","SNAM","SPDT","STRV",
		"TEXT","TNAM",
		"UNAM",
		"VCLR","VHGT","VNML","VTEX",
		"WEAT","WHGT","WNAM","WPDT",
		"XCHG","XSCL","XSOL"};

class DefBalises : public Singleton<DefBalises>{
	friend class Singleton<DefBalises>;
	protected:
		DefBalises();
		virtual ~DefBalises();

	public:
		static bool isSousBalise(char* balise);
		static bool isBalise(char* balise);
};

#endif /* DEFBALISES_H_ */
