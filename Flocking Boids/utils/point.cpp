
#include "point.h"

Point::Point() : Point( 0, 0 ) {}

Point::Point( double x, double y ) {
	setX( x );
	setY( y );
}

double Point::getX() const {
	return x;
}

double Point::getY() const {
	return y;
}

void Point::setX( double x ) {
	this->x = x;
}

void Point::setY( double y ) {
	this->y = y;
}

