all: main.o flock.o boid.o SDLHandler.o FlockingMonitor.o point.o color.o
	g++ *.o -o Flocking -Wall -O2 -std=c++11 -lSDL -lSDL_image 
run: all 
	./Flocking 100
main.o: main.cpp 
	g++ -c main.cpp 
flock.o: flock.h flock.cpp
	g++ -c flock.cpp 
boid.o: boid.h boid.cpp
	g++ -c boid.cpp 
SDLHandler.o: utils/SDLHandler.h utils/SDLHandler.cpp 
	g++ -c utils/SDLHandler.cpp 
FlockingMonitor.o: flockingMonitor.h flockingMonitor.cpp 
	g++ -c flockingMonitor.cpp 
point.o: utils/point.h utils/point.cpp 
	g++ -c utils/point.cpp 
color.o: utils/color.h utils/color.cpp 
	g++ -c utils/color.cpp 
clean:
	rm -rf *.o Flocking
open:
	vim -p flock.h flock.cpp boid.h boid.cpp utils/point.h utils/point.cpp utils/color.h utils/color.cpp main.cpp Makefile 
