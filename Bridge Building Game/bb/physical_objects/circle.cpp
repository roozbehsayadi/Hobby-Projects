
#include "circle.h"

Circle::Circle( double radius, double density, double centerx, double centery, const Color &color ) : Object( density, color ) {
	this->radius = radius;
	this->center = std::make_pair( centerx, centery );
}

void Circle::move() {
	auto temp = this->getCenter();
	this->setCenter( std::make_pair( temp.first + this->getVelocityX(), temp.second + this->getVelocityY() ) );
}

void Circle::draw( std::function<void(int, int)> &drawer ) {
	for ( int i = getCenter().first - getRadius(); i <= getCenter().first + getRadius(); i++ )
		for ( int j = getCenter().second - getRadius(); j <= getCenter().second + getRadius(); j++ )
			if ( pow( i - getCenter().first, 2 ) + pow( j - getCenter().second, 2 ) < pow( getRadius(), 2 ) )
				drawer( i, j );
}

double Circle::getRadius() const {
	return radius;
}

const std::pair<double, double> &Circle::getCenter() const {
	return center;
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

double Circle::getArea() const {
	return M_PI * radius * radius;
}

double Circle::getMass() const {
	return this->getArea() * getDensity();
}
