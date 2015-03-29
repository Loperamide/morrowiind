/*
 * ScriptEngine.h
 *
 *  Created on: 1 févr. 2011
 *      Author: jpCapelle
 */

#ifndef SCRIPTENGINE_H_
#define SCRIPTENGINE_H_
#include "Singleton.h"
#include "Engine.h"
#include "global.h"


class ScriptEngine : public Singleton<ScriptEngine>, public Engine {
	friend class Singleton<ScriptEngine>;
	friend class Engine;

protected:
	ScriptEngine(){};
	virtual ~ScriptEngine(){};
public:
	void init(void);
	void nextLoop(void);
};

#endif /* SCRIPTENGINE_H_ */
