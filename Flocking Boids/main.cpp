
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

#include "flock.h"

int main ( int argc, char **argv ) {

	if ( argc != 2 ) {
		std::cout << "Usage:\n./Flocking Number_of_Boids" << std::endl;
		return 1;
	}
	if ( atoi( argv[1] ) == 0 ) {
		std::cout << "Number of boids shoud be more that zero\nOr maybe you entered a string instead of a number...?" << std::endl;
		return 1;
	}

	srand( time( nullptr ) );

	Flock flock( 1920, 1080 );
	flock.initialize( atoi( argv[1] ) );

	return 0;

}

