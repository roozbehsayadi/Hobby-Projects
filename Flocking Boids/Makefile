all: main.o flockingBoids.o flock.o boid.o SDLHandler.o flockingMonitor.o point.o color.o
	g++ *.o -o Flocking -Wall -O2 -g -std=c++11 -lSDL -lSDL_gfx
run: 
	./Flocking 200
main.o: main.cpp 
	g++ -c main.cpp 
flockingBoids.o: flockingBoids.h flockingBoids.cpp
	g++ -c flockingBoids.cpp 
flock.o: utils/flock.h utils/flock.cpp
	g++ -c utils/flock.cpp 
boid.o: utils/boid.h utils/boid.cpp
	g++ -c utils/boid.cpp 
SDLHandler.o: utils/SDLHandler.h utils/SDLHandler.cpp 
	g++ -c utils/SDLHandler.cpp 
flockingMonitor.o: utils/flockingMonitor.h utils/flockingMonitor.cpp 
	g++ -c utils/flockingMonitor.cpp 
point.o: utils/point.h utils/point.cpp 
	g++ -c utils/point.cpp 
color.o: utils/color.h utils/color.cpp 
	g++ -c utils/color.cpp 
clean:
	rm -rf *.o Flocking
open:
	vim -p flockingBoids.h flockingBoids.cpp utils/flock.h utils/flock.cpp utils/flockingMonitor.h utils/flockingMonitor.cpp utils/boid.h utils/boid.cpp main.cpp Makefile 
