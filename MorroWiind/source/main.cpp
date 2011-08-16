/*
 * main.cpp
 *
 *  Created on: 1 févr. 2011
 *      Author: jpCapelle
 */

#include "headers/global.h"

#include "headers/GameEngine.h"
#include "headers/GraphicsEngine.h"
#include "headers/ScriptEngine.h"
#include "headers/SoundEngine.h"

#ifdef COMPILEPC
#include <Windows.h>
#include <process.h>

unsigned int __stdcall mythread(void*)
{
	while (!GameEngine::getInstance()->out()) {
		WaitForSingleObject(GameEngine::getInstance()->semaphore, INFINITE);
		#ifdef TEST1ACTIF
			GameEngine::getInstance()->pushMessage(TEST1);
		#endif
		ReleaseSemaphore(GameEngine::getInstance()->semaphore, 1, 0);
		Sleep(1L);
	}
	return 0;
}
#endif

int boucleTraitements(void){
	GameEngine::getInstance()->nextLoop();
	ScriptEngine::getInstance()->nextLoop();
	SoundEngine::getInstance()->nextLoop();
	GraphicsEngine::getInstance()->nextLoop();
	return 0;
}

int main( int argc, char **argv ){
	GameEngine::getInstance()->init();
	ScriptEngine::getInstance()->init();
	SoundEngine::getInstance()->init();
	GraphicsEngine::getInstance()->init();

	#ifdef COMPILEPC
		GameEngine::getInstance()->semaphore = CreateSemaphore(0, 1, 1, 0);
		HANDLE hThread = (HANDLE)_beginthreadex(0, 0, &mythread, (void*)0, 0, 0);
	#endif
	#ifdef TEST1ACTIF
		GameEngine::getInstance()->pushMessage(TEST1INI);
	#else
		GameEngine::getInstance()->pushMessage(CREDITS);
	#endif

	while (!GameEngine::getInstance()->out()) {
		#ifdef COMPILEPC
			WaitForSingleObject(GameEngine::getInstance()->semaphore, INFINITE);
		#endif
		GameEngine::getInstance()->pushMessage(ANALYSEETATCOMMANDES);
		boucleTraitements();
		#ifdef COMPILEPC
			ReleaseSemaphore(GameEngine::getInstance()->semaphore, 1, 0);
		#endif
	}

	GameEngine::getInstance()->dropInstance();
	ScriptEngine::getInstance()->dropInstance();
	SoundEngine::getInstance()->dropInstance();

	GraphicsEngine::getInstance()->clean();
	GraphicsEngine::getInstance()->dropInstance();

	#ifdef COMPILEPC
		WaitForSingleObject(hThread, INFINITE);
		CloseHandle(hThread);
		CloseHandle(GameEngine::getInstance()->semaphore);
	#endif

	return 0;
}

