
#include "circle.h"

Circle::Circle( double radius, double centerx, double centery, const Color &color ) {
	this->radius = radius;
	this->center = std::make_pair( centerx, centery );
	this->color = color;
}

double Circle::getDensity() const {
	return this->density;
}

double Circle::getRadius() const {
	return radius;
}

const std::pair<double, double> &Circle::getCenter() const {
	return center;
}

const Color &Circle::getColor() const {
	return color;
}

bool Circle::setDensity( double density ) {
	if ( density <= 0 )
		return false;
	this->density = density;
	return true;
}

bool Circle::setRadius( double radius ) {
	if ( radius <= 0 ) 
		return false;
	this->radius = radius;
	return true;
}

bool Circle::setCenter( const std::pair<double, double> &center ) {
	this->center = center;
	return true;
}

bool Circle::setColor( const Color &color ) {
	this->color = color;
	return true;
}

double Circle::getArea() const {
	return M_PI * radius * radius;
}

double Circle::getMass() const {
	return getArea() * density;
}
