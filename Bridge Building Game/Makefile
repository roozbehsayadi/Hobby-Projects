all: main.o bridge_building.o bbmonitor.o circle.o color.o FPSDelayer.o physics.o
	g++ *.o -o Bridge\ Building.out -Wall -g -O2 -std=c++17 -lSDL2
run: 
	./Bridge\ Building.out 
main.o: main.cpp
	g++ -c main.cpp 
bridge_building.o: bb/bridge_building.h bb/bridge_building.cpp 
	g++ -c bb/bridge_building.cpp 
bbmonitor.o: bb/utils/bbmonitor.h bb/utils/bbmonitor.cpp
	g++ -c bb/utils/bbmonitor.cpp 
circle.o: bb/physical_objects/circle.h bb/physical_objects/circle.cpp 
	g++ -c bb/physical_objects/circle.cpp 
color.o: bb/utils/color.h bb/utils/color.cpp 
	g++ -c bb/utils/color.cpp
FPSDelayer.o: bb/utils/FPSDelayer.h bb/utils/FPSDelayer.cpp
	g++ -c bb/utils/FPSDelayer.cpp
physics.o: bb/utils/physics.h bb/utils/physics.cpp
	g++ -c bb/utils/physics.cpp 
clean: 
	rm -rf *.o *.out
