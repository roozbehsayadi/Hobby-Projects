
#include "object.h"

Object::Object( double density, const Color &color ) {
	this->density = density;
	this->color = color;
	this->v = std::make_pair( 0.0, 0.0 );
}

double Object::getDensity() const {
	return this->density;
}

const std::pair<double, double> &Object::getVelocity() const {
	return this->v;
}

double Object::getVelocityX() const {
	return this->v.first;
}

double Object::getVelocityY() const {
	return this->v.second;
}

const Color &Object::getColor() const {
	return this->color;
}

bool Object::setDensity( double density ) {
	if ( density <= 0 )
		return false;
	this->density = density;
	return true;
}

bool Object::setVelocity( const std::pair<double, double> &v ) {
	this->v = v;
	return true;
}

bool Object::setVelocityX( double vx ) {
	this->v.first = vx;
	return true;
}

bool Object::setVelocityY( double vy ) {
	this->v.second = vy;
	return true;
}

bool Object::setColor( const Color &color ) {
	this->color = color;
	return true;
}
