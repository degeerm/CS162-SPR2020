#ifndef DECK_H
#define DECK_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Card.h"
using namespace std;
class Deck{
	private:
		Card cards[52];
		int n_cards;
	public:
		Deck();
		void swap(int, int);
		void shuffle();
		int get_cards_left();
		Card deal_one();
		bool check_tie();
};

#endif
