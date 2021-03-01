all: main.o bridge_building.o bbmonitor.o object.o circle.o color.o timer.o FPSDelayer.o physics.o screenScale.o 
	g++ *.o -o Bridge\ Building.out -Wall -g -O2 -std=c++17 -lSDL2
run: 
	./Bridge\ Building.out 
main.o: main.cpp
	g++ -c main.cpp 
bridge_building.o: bb/bridge_building.h bb/bridge_building.cpp 
	g++ -c bb/bridge_building.cpp 
bbmonitor.o: bb/utils/bbmonitor.h bb/utils/bbmonitor.cpp
	g++ -c bb/utils/bbmonitor.cpp 
object.o: bb/physical_objects/object.h bb/physical_objects/object.cpp
	g++ -c bb/physical_objects/object.cpp
circle.o: bb/physical_objects/circle.h bb/physical_objects/circle.cpp 
	g++ -c bb/physical_objects/circle.cpp 
color.o: bb/utils/color.h bb/utils/color.cpp 
	g++ -c bb/utils/color.cpp
timer.o: bb/utils/timers/timer.h bb/utils/timers/timer.cpp 
	g++ -c bb/utils/timers/timer.cpp 
FPSDelayer.o: bb/utils/timers/FPSDelayer.h bb/utils/timers/FPSDelayer.cpp
	g++ -c bb/utils/timers/FPSDelayer.cpp
physics.o: bb/utils/physics.h bb/utils/physics.cpp
	g++ -c bb/utils/physics.cpp 
screenScale.o: bb/utils/screenScale.h bb/utils/screenScale.cpp 
	g++ -c bb/utils/screenScale.cpp 
clean: 
	rm -rf *.o *.out
