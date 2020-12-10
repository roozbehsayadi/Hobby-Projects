all: main flock boid point 
	g++ main.o boid.o point.o -o Flocking -Wall -O2 -std=c++11
run:
	./Flocking
main: main.cpp 
	g++ -c main.cpp 
flock: flock.h flock.cpp
	g++ -c flock.cpp 
boid: boid.h boid.cpp
	g++ -c boid.cpp 
point: utils/point.h utils/point.cpp 
	g++ -c utils/point.cpp 
clean:
	rm -rf *.o Flocking
