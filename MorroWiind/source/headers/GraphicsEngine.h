/*
 * GraphicsEngine.h
 *
 *  Created on: 1 févr. 2011
 *      Author: jpCapelle
 */

#ifndef GRAPHICSENGINE_H_
#define GRAPHICSENGINE_H_
#include "Singleton.h"
#include "Engine.h"
#include "global.h"


class GraphicsEngine : public Singleton<GraphicsEngine>, public Engine {
	friend class Singleton<GraphicsEngine>;
	friend class Engine;

protected:
	GraphicsEngine(){};
	virtual ~GraphicsEngine(){};
public:
	void init(void);
	void nextLoop(void);
	void loadImage(char*,int,int);//Chargement d'une image
private:
	void drawAll();
public:
	void clean(void);
#ifdef COMPILEPC
	IrrlichtDevice* device;
	video::IVideoDriver* driver;
	scene::ISceneManager* smgr;
	gui::IGUIEnvironment* guienv;
#endif
};

#endif /* GRAPHICSENGINE_H_ */
