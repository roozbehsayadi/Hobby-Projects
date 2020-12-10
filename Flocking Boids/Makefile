all: main flock boid point color
	g++ main.o flock.o boid.o point.o color.o -o Flocking -Wall -O2 -std=c++11
run:
	./Flocking 100
main: main.cpp 
	g++ -c main.cpp 
flock: flock.h flock.cpp
	g++ -c flock.cpp 
boid: boid.h boid.cpp
	g++ -c boid.cpp 
point: utils/point.h utils/point.cpp 
	g++ -c utils/point.cpp 
color: utils/color.h utils/color.cpp 
	g++ -c utils/color.cpp 
clean:
	rm -rf *.o Flocking
open:
	vim -p flock.h flock.cpp boid.h boid.cpp utils/point.h utils/point.cpp utils/color.h utils/color.cpp main.cpp Makefile 
