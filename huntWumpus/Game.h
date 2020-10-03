/******************************************************
 * ** Program Name: Game.h
 * ** Author: Miya DeGeer 
 * ** Date: 05/24/2020
 * ** Description: Interface file for the game class.
 * ** Has various functions for carrying out Hunt the Wumpus,
 * ** including checkers/main game/shooting events/etc.
 * ******************************************************/
#ifndef Game_H
#define Game_H

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include "check_functions.h"
#include "Room.h"
#include "Wumpus.h"
#include "Bat.h"
#include "Pit.h"
#include "Gold.h"

using namespace std;

class Game{
	private:
		vector<vector<Room> > rooms;
		bool has_gold;
		bool debug;
		int num_arrows;
	public:
		Game();
		Game(int, bool);
		void generate_events();
		void add_events(int,int);
		void print_game_debug(bool);
		void print_header();
		void move_adventurer(int, int);
		string ending_options();
		bool arrow_event(int, int,string);
		bool move_wumpus(int, int);
		int find_ad_x();
		int find_ad_y();
		string main_game(bool);
		void do_percept();
		bool do_event();
		void reset_dungeon();
		void move_shoot();
		bool move_player(int,int);
		bool move_overview(string);
		bool shoot_arrow(string);
		void shoot_up();
		void shoot_down();
		void shoot_left();
		void shoot_right();
};

#endif
