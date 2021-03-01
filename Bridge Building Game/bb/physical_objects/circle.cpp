
#include "circle.h"

Circle::Circle( double radius, double density, double centerx, double centery, const Color &color ) : Object( density, color ) {
	this->radius = radius;
	this->center = std::make_pair( centerx, centery );
}

void Circle::move( double deltaT ) {
	std::cout << std::left;
	std::cout << std::setw( 9 ) << "a: " << getAccelerationY() << std::endl;
	std::cout << std::setw( 9 ) << "deltaT: " << deltaT << std::endl;
	std::cout << std::setw( 9 ) << "V0: " << getVelocityY() << std::endl;
	std::cout << std::setw( 9 ) << "Y0: " << getCenter().second << std::endl;
	auto temp = this->getCenter();
	double newXMeters = 0.5 * getAccelerationX() * deltaT * deltaT + getVelocityX() * deltaT + getCenter().first;
	double newYMeters = 0.5 * getAccelerationY() * deltaT * deltaT + getVelocityY() * deltaT + getCenter().second;
	std::cout << "New Y Meters: " << newYMeters << std::endl;
	this->setCenter( std::make_pair( newXMeters, newYMeters ));
}

void Circle::draw( std::function<void(int, int)> &drawer ) {

	double xStart = ScreenScale::getInstance()->getPixels( getCenter().first - getRadius() );
	double xEnd = ScreenScale::getInstance()->getPixels( getCenter().first + getRadius() );
	double yStart = ScreenScale::getInstance()->getPixels( getCenter().second - getRadius() );
	double yEnd = ScreenScale::getInstance()->getPixels( getCenter().second + getRadius() );
	double centerXPixels = ScreenScale::getInstance()->getPixels( getCenter().first );
	double centerYPixels = ScreenScale::getInstance()->getPixels( getCenter().second );
	double radiusPixels = ScreenScale::getInstance()->getPixels( getRadius() );

	std::cout << xStart << ' ' << xEnd << ' ' << yStart << ' ' << yEnd << std::endl;

	for ( int i = xStart; i <= xEnd; i++ )
		for ( int j = yStart; j <= yEnd; j++ )
			if ( pow( i - centerXPixels, 2 ) + pow( j - centerYPixels, 2 ) < pow( radiusPixels, 2 ) )
				drawer( i, j );	

	// exit( 0 );

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
