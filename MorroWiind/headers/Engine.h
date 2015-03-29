/*
 * Engine.h
 *
 *  Created on: 24 févr. 2011
 *      Author: jpCapelle
 */

#ifndef ENGINE_H_
#define ENGINE_H_

#include "global.h"

class Engine {
public:
	void pushMessage(int inMessage);
protected:
	Engine();
	virtual ~Engine();

	bool hasNextMessage();
	int getNextMessage();
private:
	vector<int> lstMessages;
};

#endif /* ENGINE_H_ */
