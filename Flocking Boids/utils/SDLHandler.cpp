
#include "SDLHandler.h"

void SDLHandler::initSDL( int flag ) {
	if ( SDL_Init( flag ) < 0 ) {
		std::cerr << "Error in initializing SDL in SDLHandler::initSDL\n";
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

void SDLHandler::drawCircle( SDL_Surface *screen, int radius, const Point &center, const Color &color ) {

	filledCircleRGBA( screen, center.getX(), center.getY(), radius, color.r, color.g, color.b, 255 );

}

void SDLHandler::drawRotatedBox( SDL_Surface *screen, const Point &p1, const Point &p2, int width, const Color &color ) {

	// get angle between these two points
	double deltaY = p2.getY() - p1.getY();
	double deltaX = p2.getX() - p1.getX();
	double angle = atan2( deltaX, deltaY );
	
	// calculate the 4 points of the box we need to draw for the trail of the boid
	int16_t srcP1X = (int16_t) p1.getX() + width * cos( angle - M_PI / 2 );
	int16_t srcP1Y = (int16_t) p1.getY() + width * sin( angle - M_PI / 2 );
	int16_t srcP2X = (int16_t) p1.getX() + width * cos( angle + M_PI / 2 );
	int16_t srcP2Y = (int16_t) p1.getY() + width * sin( angle + M_PI / 2 );

	int16_t dstP1X = (int16_t) p2.getX() + width * cos( ( M_PI + angle ) - M_PI / 2 );
	int16_t dstP1Y = (int16_t) p2.getY() + width * sin( ( M_PI + angle ) - M_PI / 2 );
	int16_t dstP2X = (int16_t) p2.getX() + width * cos( ( M_PI + angle ) + M_PI / 2 );
	int16_t dstP2Y = (int16_t) p2.getY() + width * sin( ( M_PI + angle ) + M_PI / 2 );

	const int16_t vx[4] = { srcP1X, srcP2X, dstP1X, dstP2X };
	const int16_t vy[4] = { srcP1Y, srcP2Y, dstP1Y, dstP2Y };
	
	// draw the polygon
	filledPolygonRGBA( screen, vx, vy, 4, color.r, color.g, color.b, 255 );

}

