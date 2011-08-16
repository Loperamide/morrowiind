/*
 * GameEngine.h
 *
 *  Created on: 1 févr. 2011
 *      Author: jpCapelle
 */

#ifndef GAMEENGINE_H_
#define GAMEENGINE_H_
#include "Singleton.h"
#include "Engine.h"
#include "global.h"
#ifdef COMPILEPC
	#include "EventReceiver.h"
	#include <Windows.h>
	#include <process.h>
#else
	#include <ogc/lwp.h>
#endif

class GameEngine : public Singleton<GameEngine>, public Engine {
	friend class Singleton<GameEngine>;
	friend class Engine;

protected:
	GameEngine():sortie(false),currentScreen(INLOAD){};
	virtual ~GameEngine(){};

public:
	bool init(void);
	bool out(void){return sortie;};
#ifdef COMPILEPC
	EventReceiver* getReceiver(void){return &receiver;};
	static unsigned int __stdcall threadCredits(void * pThis){
		GameEngine * pthX = (GameEngine*)pThis;   // the tricky cast
		pthX->threadCredits();           // now call the true entry-point-function
		return 1;}
	void threadCredits(void);
#else
	static void * threadCredits(void * pThis){
		GameEngine * pthX = (GameEngine*)pThis;
		pthX->threadCredits();
		return 0;}
	void threadCredits(void);
#endif
	void nextLoop(void);

#ifdef COMPILEPC
public:
	HANDLE semaphore;
#else
	sem_t semaphore;
#endif
private:
	void analyseEtatCommandes(void);
	void loadMenu(void);
	void newGame(void);
	void loadGame(void);
	void saveGame(void);
	void credits(void);
private:
	bool sortie;
	int currentScreen;
#ifdef COMPILEPC
	EventReceiver receiver;
#ifdef TEST1ACTIF
	void test1(void);
	void test1ini(void);
	int newZ;
	bool up;
#endif
#endif
};
#endif /* GAMEENGINE_H_ */
