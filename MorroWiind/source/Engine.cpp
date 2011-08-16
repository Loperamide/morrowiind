/*
 * Engine.cpp
 *
 *  Created on: 24 févr. 2011
 *      Author: jpCapelle
 */

#include "headers/Engine.h"

Engine::Engine() {
	// TODO Auto-generated constructor stub

}

Engine::~Engine() {
	// TODO Auto-generated destructor stub
}

/**
 * Ajoute un message a la liste de traitements
 */
void Engine::pushMessage(int inMessage) {
	lstMessages.push_back(inMessage);
}

/**
 * Renvoie vrai s'il y a un message a consomer
 */
bool Engine::hasNextMessage() {
	if (lstMessages.size() > 0){
		return true;
	} else {
		return false;
	}
}

/**
 * Renvoie le message suivant
 */
int Engine::getNextMessage() {
	int retour = lstMessages.front();
	lstMessages.erase(lstMessages.begin());
	return retour;
}
