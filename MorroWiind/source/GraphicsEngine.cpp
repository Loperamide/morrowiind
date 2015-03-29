/*
 * GraphicsEngine.cpp
 *
 *  Created on: 1 févr. 2011
 *      Author: jpCapelle
 */

#include "GraphicsEngine.h"
#include "GameEngine.h"

void GraphicsEngine::init(void){
#ifndef COMPILEPC
    GRRLIB_Init();
    GRRLIB_Settings.antialias = true;

    GRRLIB_SetBackgroundColour(0x00, 0x00, 0x00, 0xFF);
    GRRLIB_Camera3dSettings(0.0f,0.0f,13.0f, 0,1,0, 0,0,0);
#else
	device = createDevice(video::EDT_OPENGL,
			core::dimension2d<u32>(SCREEN_16_9), 16, true, false, false, GameEngine::getInstance()->getReceiver());
	driver = device->getVideoDriver();
	smgr = device->getSceneManager();
	guienv = device->getGUIEnvironment();

#endif
}

void GraphicsEngine::nextLoop(void){
	drawAll();
}

void GraphicsEngine::drawAll(void){
#ifndef COMPILEPC
	GX_Begin(GX_QUADS, GX_VTXFMT0, 24);
		//Liste des objets à dessiner (textes, 3D, 2D, ...)
	GX_End();
    GRRLIB_Render();
#else
	if (!device->run())GameEngine::getInstance()->pushMessage(SORTIE);

	driver->beginScene(true, true, video::SColor(255,113,113,133));
	smgr->drawAll(); // draw the 3d scene
	guienv->drawAll();
	driver->endScene();
#endif
}

void GraphicsEngine::clean(void){
#ifndef COMPILEPC
	GRRLIB_Exit();
#else
	device->drop();
#endif
}

void GraphicsEngine::loadImage(char *image,int posx,int posy)
{
	#ifndef COMPILEPC

	#else
	#endif
}
