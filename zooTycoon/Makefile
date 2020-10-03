CC = g++ -std=c++11
exe_file = zoo_tycoon 
$(exe_file): Animal.o Bear.o Tiger.o SeaLion.o Zoo.o Array.o prog.o
	$(CC) Animal.o Bear.o Tiger.o SeaLion.o Zoo.o Array.o prog.o -o $(exe_file)
Animal.o: Animal.cpp
	$(CC) -c Animal.cpp
Bear.o: Bear.cpp
	$(CC) -c Bear.cpp
Tiger.o: Tiger.cpp
	$(CC) -c Tiger.cpp
SeaLion.o: SeaLion.cpp
	$(CC) -c SeaLion.cpp
Zoo.o: Zoo.cpp
	$(CC) -c Zoo.cpp
Array.o: Array.cpp
	$(CC) -c Array.cpp
prog.o: prog.cpp
	$(CC) -c prog.cpp

clean:
	rm -f *.out *.o $(exe_file)
