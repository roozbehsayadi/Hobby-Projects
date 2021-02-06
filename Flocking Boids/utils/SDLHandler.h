
#ifndef __UTILS__SDLHANDLER_H
#define __UTILS_SDLHANDLER_H

#include <iostream>
#include <string>
#include <math.h>

#include "SDL/SDL.h"
#include "SDL/SDL_gfxPrimitives.h"

#include "point.h"
#include "color.h"

class SDLHandler {

	public:
	
		static void initSDL( int );
		// If -1 is passed as windowWidth and windowHeight, the passed
		// variable will change value to the screen's size accordingly.
		static SDL_Surface *initWindow( std::string, int &, int & );
		static SDL_Surface *loadIMG( std::string );
		
		static void drawCircle( SDL_Surface *, int, const Point &, const Color & );
		static void drawRotatedBox( SDL_Surface *, const Point &, const Point &, int, const Color & );

};

#endif

