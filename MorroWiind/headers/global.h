/*
 * global.h
 *
 *  Created on: 1 févr. 2011
 *      Author: jpCapelle
 */

#ifndef GLOBAL_H_
#define GLOBAL_H_

	#include <iostream>
	#include <stdio.h>
	#include <string.h>
	#include <vector>
	using namespace std;

	#ifndef COMPILEPC
		#include <gctypes.h>
		#include <grrlib.h>
		#include <wiiuse/wpad.h>
	#else
		#include "irrlicht.h"
		using namespace irr;
		//using namespace core;
		using namespace scene;
		using namespace video;
		//using namespace io;
		using namespace gui;
	#endif

	#include "defines.h"
#endif /* GLOBAL_H_ */
