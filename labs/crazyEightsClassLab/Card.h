#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <string>
using namespace std;
class Card{
	private:
		int rank;
		int suit;
	public:
		Card();
		~Card();
		//H (const Card &);
		//Hand& operator=(const Hand &);
		void init(int, int);
		void print_card();
		int get_suit();
		int get_rank();
		bool can_play(int, int);
		string map_rank();
		string map_suit();
};

#endif
