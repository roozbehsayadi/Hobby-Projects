all: main boid
	g++ main.o boid.o -o Flocking -Wall -O2 -std=c++11
run:
	./Flocking
main:
	g++ -c main.cpp 
boid: boid.h boid.cpp
	g++ -c boid.cpp 
point: point.h point.cpp 
	g++ -c point.cpp 
clean:
	rm -rf *.o Flocking
