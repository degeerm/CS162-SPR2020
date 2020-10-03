#ifndef HAND_H
#define HAND_H

#include <iostream>
#include <string>

#include <cmath>
#include "Card.h"
using namespace std;

class Hand{
	private:
		Card* cards;
		int n_cards;
	public:
		Hand();
		~Hand();
		Hand(Hand &);
		Hand(int);
		Hand& operator= (const Hand&);	
		
		//Accessor/Mutator Methods
		void add_one_card(Card);
		Card remove_card(int);
		void change_card(int, Card);
		//void change_num_cards(int);
		int get_num_cards();
		Card* get_card_array();
		
		//Error Handling/Status Checking
		bool can_play(int, int);	
		bool check_suit(int);
		bool check_rank(int);	

		void print_hand() const;
};

#endif
