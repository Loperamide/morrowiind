/*
 * defines.h
 *
 *  Created on: 10 août 2011
 *      Author: jpCapelle
 */

#ifndef DEFINES_H_
#define DEFINES_H_

#define INIFILEPATH "F:\\ExemplesMorrowiind\\Morrowiind.xml"
#ifdef COMPILEPC
	#define SCREEN_4_3 1280, 1024
	#define SCREEN_16_9 1680, 1050
#else
	#ifdef PAL
		#define SCREEN_4_3 768, 576
		#define SCREEN_16_9 1024, 576
	#else
		#define SCREEN_4_3 640, 480
		#define SCREEN_16_9 853, 1050
	#endif
#endif

//Commandes pour la boucle de jeu
#define ANALYSEETATCOMMANDES 1
#define SORTIE 2

#define TEST1 3
#define TEST1INI 4

#define MENU 5
#define NEWGAME 6
#define LOADGAME 7
#define SAVEGAME 8
#define CREDITS 9

//Etat dans la séquence des écrans
#define INLOAD 0
#define INMENU 1
#define INGAME 2
#define INCREDITS 3

#endif /* DEFINES_H_ */
