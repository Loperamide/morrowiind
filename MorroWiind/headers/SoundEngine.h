/*
 * SoundEngine.h
 *
 *  Created on: 1 févr. 2011
 *      Author: jpCapelle
 */

#ifndef SOUNDENGINE_H_
#define SOUNDENGINE_H_
#include "Singleton.h"
#include "Engine.h"
#include "global.h"


class SoundEngine : public Singleton<SoundEngine>, public Engine {
	friend class Singleton<SoundEngine>;
	friend class Engine;

protected:
	SoundEngine(){};
	virtual ~SoundEngine(){};
public:
	void init(void);
	void nextLoop(void);
};

#endif /* SOUNDENGINE_H_ */
