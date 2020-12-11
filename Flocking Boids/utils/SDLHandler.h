
#ifndef __UTILS__SDLHANDLER_H
#define __UTILS_SDLHANDLER_H

#include <iostream>
#include <string>

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

class SDLHandler {

	public:
	
		static void initSDL( int );
		// If -1 is passed as windowWidth and windowHeight, the passed
		// variable will change value to the screen's size accordingly.
		static SDL_Surface *initWindow( std::string, int &, int & );
		static SDL_Surface *loadIMG( std::string );

};

#endif

