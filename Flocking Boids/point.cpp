
#include "point.h"

Point::Point() : Point( 0, 0 ) {}

Point::Point( int x, int y ) {
	setX( x );
	setY( y );
}

int Point::getX() const {
	return x;
}

int Point::getY() const {
	return y;
}

void Point::setX( int x ) {
	this->x = x;
}

void Point::setY( int y ) {
	this->y = y;
}

