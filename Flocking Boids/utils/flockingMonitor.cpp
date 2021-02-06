
#include "flockingMonitor.h"

FlockingMonitor::FlockingMonitor() {}

FlockingMonitor::FlockingMonitor( int &screenWidth, int &screenHeight ) {

	SDLHandler::initSDL( SDL_INIT_EVERYTHING );

	screen = SDLHandler::initWindow( "Flocking Boid", screenWidth, screenHeight );

}

FlockingMonitor::~FlockingMonitor() {
	SDL_Quit();
}

SDLEventType FlockingMonitor::handleEvents() {

	SDL_Event event;
	if ( SDL_PollEvent( &event ) ) {
		if ( event.type == SDL_KEYDOWN )
			if ( event.key.keysym.sym == SDLK_q )
				return SDLEventType::QUIT;
		if ( event.type == SDL_QUIT )
			return SDLEventType::QUIT;
	}
	return SDLEventType::NONE;

}

void FlockingMonitor::drawBoids( Flock * flock ) {

	boxRGBA( screen, 0, 0, screen->w, screen->h, 0, 0, 0, 30 );
	//SDL_FillRect( screen, NULL, 0 );
	for ( auto &i : flock->boids ) {
		SDLHandler::drawRotatedBox( screen, i.prevLocation, i.location, 3, flock->color );
		SDLHandler::drawCircle( screen, 3, i.location, flock->color );
	}

}

void FlockingMonitor::updateScreen() {
	SDL_Flip( screen );
}

