CC = g++ 
exe_file = hunt_wumpus 
$(exe_file): Event.o Bat.o Wumpus.o Gold.o Pit.o Room.o Game.o check_functions.o driver.o
	$(CC) Event.o Bat.o Wumpus.o Gold.o Pit.o Room.o Game.o check_functions.o driver.o -o $(exe_file)
Event.o: Event.cpp
	$(CC) -c Event.cpp
Bat.o: Bat.cpp
	$(CC) -c Bat.cpp
Wumpus.o: Wumpus.cpp
	$(CC) -c Wumpus.cpp
Gold.o: Gold.cpp
	$(CC) -c Gold.cpp
Pit.o: Pit.cpp
	$(CC) -c Pit.cpp
Game.o: Game.cpp
	$(CC) -c Game.cpp
Room.o: Room.cpp
	$(CC) -c Room.cpp
check_functions.o: check_functions.cpp
	$(CC) -c check_functions.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp
clean:
	rm -f *.out *.o $(exe_file)
