
#include "color.h"

Color::Color() {
	r = g = b = 0;
}

Color::Color( unsigned char c ) {
	r = g = b = c;
}

Color::Color( unsigned char r, unsigned char g, unsigned char b ) {
	setColor( r, g, b );
}

void Color::setColor( unsigned char r, unsigned char g, unsigned char b ) {
	this->r = r;
	this->g = g;
	this->b = b;
}

void Color::setColor( const Color &color ) {
	this->r = color.r;
	this->g = color.g;
	this->b = color.b;
}

