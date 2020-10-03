CC = g++
exe_file = wizard_db
$(exe_file): wizard_db.o driver.o
	$(CC) wizard_db.o driver.o -o $(exe_file)
wizard_db.o: wizard_db.cpp
	$(CC) -c wizard_db.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp

clean:
	rm -f *.out *.o $(exe_file)
