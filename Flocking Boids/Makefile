all: main.o flock.o boid.o SDLHandler.o FlockingMonitor.o point.o color.o
	g++ *.o -o Flocking -Wall -O2 -std=c++11 -lSDL -lSDL_image 
run: all 
	./Flocking 100
main.o: main.cpp 
	g++ -c main.cpp 
flock.o: utils/flock.h utils/flock.cpp
	g++ -c utils/flock.cpp 
boid.o: utils/boid.h utils/boid.cpp
	g++ -c utils/boid.cpp 
SDLHandler.o: utils/SDLHandler.h utils/SDLHandler.cpp 
	g++ -c utils/SDLHandler.cpp 
FlockingMonitor.o: utils/flockingMonitor.h utils/flockingMonitor.cpp 
	g++ -c utils/flockingMonitor.cpp 
point.o: utils/point.h utils/point.cpp 
	g++ -c utils/point.cpp 
color.o: utils/color.h utils/color.cpp 
	g++ -c utils/color.cpp 
clean:
	rm -rf *.o Flocking
open:
	vim -p utils/flock.h utils/flock.cpp utils/flockingMonitor.h utils/flockingMonitor.cpp utils/SDLHandler.h utils/SDLHandler.cpp utils/boid.h utils/boid.cpp main.cpp Makefile 
