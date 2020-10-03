CC = g++ -std=c++11
exe_file = deck_cards
$(exe_file): Deck.o Card.o Hand.o Player.o Game.o driver.o
	$(CC) Deck.o Card.o Hand.o Player.o Game.o driver.o -o $(exe_file)
Deck.o: Deck.cpp
	$(CC) -c Deck.cpp
Card.o: Card.cpp
	$(CC) -c Card.cpp
Hand.o: Hand.cpp
	$(CC) -c Hand.cpp
Player.o: Player.cpp
	$(CC) -c Player.cpp
Game.o: Game.cpp
	$(CC) -c Game.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp
clean:
	rm -f *.out *.o $(exe_file)
