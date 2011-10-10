/*
 * GameEngine.cpp
 *
 *  Created on: 1 févr. 2011
 *      Author: jpCapelle
 */

#include "headers/GameEngine.h"
#include "headers/GraphicsEngine.h"
#include <tinyxml.h>
#include <tinystr.h>
#include "headers/Tes3.h"

bool GameEngine::init(void){
	//Chargement du fichier d'initialisation
	TiXmlDocument initFile(INIFILEPATH);
	bool loadOk = initFile.LoadFile();
	if (!loadOk) return false;

	//Contrôle des paramètres
	//et Chargement des données
	TiXmlElement* racine = initFile.RootElement();
	if (racine == NULL) return false;

	TiXmlElement* subElement = racine->FirstChildElement();
	for(;;){
		if (subElement==NULL) break;
		//cout << subElement->GetText() << endl;
		//Fichier ESM à charger
		if (!strcmp("ESM",subElement->Value())){
			Tes3::getInstance()->loadFile(subElement->GetText());
		}

		subElement = subElement->NextSiblingElement();
	}
	return true;
}

void GameEngine::nextLoop(void){
	while(hasNextMessage()) {
		int msg = getNextMessage();
		//Les messages non connus sont ignorés
		if(msg == ANALYSEETATCOMMANDES) {
			analyseEtatCommandes();
		}
		if(msg == MENU) {
			loadMenu();
		}
		if(msg == NEWGAME) {
			newGame();
		}
		if(msg == LOADGAME) {
			loadGame();
		}
		if(msg == SAVEGAME) {
			saveGame();
		}
		if(msg == CREDITS) {
			credits();
		}
#ifdef COMPILEPC
#ifdef TEST1ACTIF
		if(msg == TEST1INI) {
			test1ini();
		}
		if(msg == TEST1) {
			test1();
		}
#endif
#endif
		if(msg == SORTIE) {
			sortie = true;
		}
	}
}

void GameEngine::analyseEtatCommandes(){
	#ifndef COMPILEPC
		WPAD_ScanPads();
		if(WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME) sortie = true;
		if(WPAD_ButtonsHeld(0) & WPAD_BUTTON_A) ;
		if(WPAD_ButtonsHeld(0) & WPAD_BUTTON_B) ;
	#else
		if (receiver.GetMouseState().LeftButtonDown) {
			sortie = true;
		}
	#endif
}

#ifdef COMPILEPC
#ifdef TEST1ACTIF
void GameEngine::test1(void){
	scene::ICameraSceneNode * camera = GraphicsEngine::getInstance()->smgr->getActiveCamera();

	if (up)
		newZ += 1;
	else
		newZ -= 1;
	if (newZ < -50){
		newZ += 1;
		up = true;
	}
	if (newZ > 50){
		newZ -= 1;
		up = false;
	}
	camera->setPosition(core::vector3df(0, 0, newZ));
	GraphicsEngine::getInstance()->guienv->clear();

	char buffer[50];
	sprintf (buffer, "%d", newZ);
	wchar_t sortie[50];
	mbstowcs(sortie, buffer, 50);

	GraphicsEngine::getInstance()->guienv->addStaticText(sortie,
			core::rect<s32>(10,10,260,22), true);
}

void GameEngine::test1ini(void){
	scene::ISceneNode * node = GraphicsEngine::getInstance()->smgr->addMeshSceneNode(
			GraphicsEngine::getInstance()->smgr->addArrowMesh( "Arrow",
				video::SColor(255, 255, 0, 0),
				video::SColor(255, 0, 255, 0),
				16,16,
				2.f, 1.3f,
				0.1f, 0.6f
				)
		);
	node->setMaterialFlag(video::EMF_LIGHTING, false);

	scene::ICameraSceneNode * camera = GraphicsEngine::getInstance()->smgr->addCameraSceneNode();
	camera->setPosition(core::vector3df(0, 0, -10));
	GraphicsEngine::getInstance()->guienv->addStaticText(L"-10",
			core::rect<s32>(10,10,260,22), true);

	newZ = 0;
	up = true;
}
#endif
#endif

void GameEngine::loadMenu(void) {
	//chargement de l'image de fond
	//chargement du son
	//Modification de l'état de l'écran en cours
	currentScreen = INMENU;
}

void GameEngine::newGame(void) {
	//chargement de l'image de fond
	//chargement du son

	//Modification de l'état de l'écran en cours
	currentScreen = INGAME;
}

void GameEngine::loadGame(void) {
	//chargement de l'image de fond
	//chargement du son

	//Modification de l'état de l'écran en cours
	currentScreen = INGAME;
}

void GameEngine::saveGame(void) {
	//chargement de l'image de fond
	//chargement du son

	//Modification de l'état de l'écran en cours
	currentScreen = INGAME;
}

void GameEngine::credits(void) {
	//Modification de l'état de l'écran en cours
	currentScreen = INCREDITS;
	//chargement de l'image de fond
	//chargement du son
	//defilement du texte
	#ifdef COMPILEPC
		_beginthreadex(0, 0, GameEngine::threadCredits, this, 0, 0);
	#else
		LWP_CreateThread(0, GameEngine::threadCredits, this, NULL, 0, 0);
	#endif
}

void GameEngine::threadCredits(void)
{
	int y = 1000;
	while (currentScreen == INCREDITS) {
		#ifdef COMPILEPC
			WaitForSingleObject(semaphore, INFINITE);
			GraphicsEngine::getInstance()->guienv->clear();
			GraphicsEngine::getInstance()->guienv->addStaticText(L"Blabla1",
					core::rect<s32>(400,y,660,y+22), true);
			GraphicsEngine::getInstance()->guienv->addStaticText(L"Blabla2",
					core::rect<s32>(400,y+32,660,y+52), true);
			GraphicsEngine::getInstance()->guienv->addStaticText(L"Blabla3",
					core::rect<s32>(400,y+62,660,y+82), true);
			GraphicsEngine::getInstance()->guienv->addStaticText(L"Blabla4",
					core::rect<s32>(400,y+92,660,y+112), true);
			ReleaseSemaphore(semaphore, 1, 0);
		#else
			LWP_SemWait(semaphore);

			LWP_SemPost(semaphore);
		#endif
		y--;
	}
}
