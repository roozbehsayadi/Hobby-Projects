
#include "flockingMonitor.h"

FlockingMonitor::FlockingMonitor() {}

FlockingMonitor::FlockingMonitor( Flock *flock, int &screenWidth, int &screenHeight ) {

	this->flock = flock;

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

void FlockingMonitor::drawBoids() {

	SDL_FillRect( screen, NULL, 0 );
	for ( auto &i : flock->boids )
		SDLHandler::drawCircle( screen, 2, i.location, flock->color );

}

void FlockingMonitor::updateScreen() {
	SDL_Flip( screen );
}

