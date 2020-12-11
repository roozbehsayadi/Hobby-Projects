
#ifndef __UTILS__SDLHANDLER_H
#define __UTILS_SDLHANDLER_H

#include <iostream>
#include <string>

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

class SDLHandler {

	public:
	
		static void initSDL( int );
		static SDL_Surface *initWindow( std::string, int = 0, int = 0 );
		static SDL_Surface *loadIMG( std::string );

};

#endif

