
#include "boid.h"
#include <forward_list>

int main () {

	Boid b1;
	Boid b2( 4, 5 );
	Boid b3( std::array<int, 2> {10, 11}.begin() );
	Boid b4( std::vector<int>{15, 16}.begin() );

	return 0;

}

