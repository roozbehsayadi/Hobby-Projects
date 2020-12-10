
#include "color.h"

Color::Color() {
	r = g = b = 0;
}

Color::Color( unsigned char c ) {
	r = g = b = c;
}

Color::Color( unsigned char r, unsigned char g, unsigned char b ) {
	this->r = r;
	this->g = g;
	this->b = b;
}
