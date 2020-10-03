*crazyEights*: C++ program that plays a game of crazy eights against a bot. Allows user to hold cards, draw cards from deck, play cards,
 and checks to see if cards are valid plays. Related files:
  -Card.cpp, Card.h: Card class, stores information about individual cards, has retrieval for that information
  -Hand.cpp, Hand.h: Hand class, stores information about cards in a player/bot's hands, including functions for retrieval of that information.
   Includes functions for manipulating hand.
  -Player.cpp, Player.h: Player class, stores information (name) about each player and their hand, handles special cases (if card selected was
   an 8, etc). Functions include accessing and manipulating information.
  -Deck.cpp, Deck.h: Deck class, stores information about available cards in deck (including drawn ones, which are stored at end of array).
   Includes functions for using deck and retrieving information about it.
  -Game.cpp, Game.h: Game class, stores information about overarching game, tracks win/loss conditions, handles computer turns. Variety of
   functions for using/accessing game information.
  -driver.cpp: Driver file, has the main function. Continues to cycle through the game_main function of the Game class until player chooses
   to quit, then exits program.
