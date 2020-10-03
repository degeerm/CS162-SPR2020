CC = g++ -std=c++11 -g
exe_file = hand_cards
$(exe_file): Card.o Hand.o driver.o
	$(CC) Card.o Hand.o driver.o -o $(exe_file)
Card.o: Card.cpp
	$(CC) -c Card.cpp
Hand.o: Hand.cpp
	$(CC) -c Hand.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp
clean:
	rm -f *.out *.o $(exe_file)
