#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include "Card.h"
#include "Player.h"
#include "Deck.h"
#include "Hand.h"

using namespace std;

class Game{
	private:
		Deck cards;
		Player players[2];
		Card top_card;
		int game_suit;
		int game_rank;
	public:
		Game();
		void print_game_info();
		void tie_win_condition();
		bool overarching_win_condition();
		void player_intro();
		void initialize_hands();
		void change_game_values(int);
		bool player_turn();
		bool comp_turn();
		void draw_one_player();
		void draw_one_AI();
		bool game_main();
		bool draw_while(int, int, int);
};

#endif
