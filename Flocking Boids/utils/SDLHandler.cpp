
#include "SDLHandler.h"

void SDLHandler::initSDL( int flag ) {
	if ( SDL_Init( flag ) < 0 ) {
		std::cerr << "Error in initializing SDL in SDLHandler::initSDL\n";
		return;
	}
	int IMGFlags = IMG_INIT_JPG || IMG_INIT_PNG;
	if ( IMG_Init( IMGFlags ) != IMGFlags ) {
		std::cerr << "Error in initializing SDL_Image in SDLHandler::initSDL\n";
		return;
	}
}

SDL_Surface *SDLHandler::initWindow( std::string caption, int &screenWidth, int &screenHeight ) {

	SDL_WM_SetCaption( caption.c_str(), NULL );

	if ( screenWidth == -1 ) {
		const SDL_VideoInfo *info = SDL_GetVideoInfo();
		screenWidth = info->current_w;
		screenHeight = info->current_h;
		return SDL_SetVideoMode( screenWidth, screenHeight, 32, SDL_FULLSCREEN );
	}
	else 
		return SDL_SetVideoMode( screenWidth, screenHeight, 32, SDL_HWSURFACE );

}

SDL_Surface *loadIMG( std::string path ) { 

	SDL_Surface *loadedImage = NULL, *optimizedImage = NULL; 

	loadedImage = IMG_Load( path.c_str() );

	if ( loadedImage == NULL ) {
		std::cerr << "Error in loading image from path " << path << " in SDLHandler::loadIMG\n";
		return NULL;
	}

	optimizedImage = SDL_DisplayFormat( loadedImage );

	SDL_FreeSurface( loadedImage );

	return optimizedImage;

}

void SDLHandler::drawCircle( SDL_Surface *screen, int radius, const Point &center, const Color &color ) {

	filledCircleRGBA( screen, center.getX(), center.getY(), radius, color.r, color.g, color.b, 255 );

}
