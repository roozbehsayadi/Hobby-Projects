
#include "color.h"

Color::Color() : Color( 0, 0, 0 ) {}

Color::Color( unsigned char grayAmount ) : Color( grayAmount, grayAmount, grayAmount ) {}

Color::Color( unsigned char r, unsigned char g, unsigned char b, unsigned char alpha ) {
	setColor( r, g, b, alpha );
}

void Color::setColor( unsigned char grayAmount ) {
	setColor( grayAmount, grayAmount, grayAmount, 255 );
}

void Color::setColor( unsigned char r, unsigned char g, unsigned char b, unsigned char alpha ) { 
	this->r = r;
	this->g = g;
	this->b = b;
	this->alpha = alpha;
}

unsigned char Color::getRed() const {
	return r;
}

unsigned char Color::getGreen() const {
	return g;
}

unsigned char Color::getBlue() const {
	return b;
}

unsigned char Color::getAlpha() const {
	return alpha;
}
