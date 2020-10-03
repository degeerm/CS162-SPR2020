#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include <cstdlib>
#include "Card.h"
#include "Deck.h"
#include "Hand.h"

using namespace std;

class Player{
	private:
		Hand hand;
		string name;
	public:
		Player();
		Player(string);
		bool is_int(string);
		int get_int(string);
		int if_eight();
		void add_one_card(Card);
		Card remove_card(int);
		int get_num_cards();
		//Hand get_hand();
		
		string map_rank(int);
		string map_suit(int);	
		void change_name(string);
		string get_name();
		void print_hand();
		bool can_play(int, int);
		void change_card(int, Card);
		int if_eight_AI(int);
		Card select_card_AI(int, int);

		Card error_handle_input(int, int);
};

#endif
