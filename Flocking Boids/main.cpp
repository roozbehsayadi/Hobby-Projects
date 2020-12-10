
#include <iostream>
#include <string>

#include "flock.h"

int main ( int argc, char **argv ) {

	if ( argc != 2 ) {
		std::cout << "Usage:\n./Flocking Number_of_Boids" << std::endl;
		return 1;
	}

	Flock flock;
	flock.initialize( atoi( argv[1] ) );

	return 0;

}

