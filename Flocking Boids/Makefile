all: main.o flock.o boid.o point.o color.o
	g++ main.o flock.o boid.o point.o color.o -o Flocking -Wall -O2 -std=c++11
run:
	./Flocking 100
main.o: main.cpp 
	g++ -c main.cpp 
flock.o: flock.h flock.cpp
	g++ -c flock.cpp 
boid.o: boid.h boid.cpp
	g++ -c boid.cpp 
point.o: utils/point.h utils/point.cpp 
	g++ -c utils/point.cpp 
color.o: utils/color.h utils/color.cpp 
	g++ -c utils/color.cpp 
clean:
	rm -rf *.o Flocking
open:
	vim -p flock.h flock.cpp boid.h boid.cpp utils/point.h utils/point.cpp utils/color.h utils/color.cpp main.cpp Makefile 
