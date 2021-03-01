
#include "screenScale.h"

ScreenScale *ScreenScale::instance = NULL;

void ScreenScale::init( double meters ) {
	int monitorWidth = BBMonitor::getMonitorSize().first;
	scale = meters / monitorWidth;
}

double ScreenScale::getMeters( double pixels ) const {
	return pixels * scale;
}

double ScreenScale::getPixels( double meters ) const {
	return meters / scale;
}

ScreenScale::ScreenScale() {}

ScreenScale *ScreenScale::getInstance() {
	if ( instance == NULL )
		instance = new ScreenScale();
	return instance;
}
