/*****************************************************
** Program Name: Zoo.h 
** Author: Miya DeGeer
** Date: 05/10/2020
** Description: Interface file for Zoo class, which keeps
** track of animals, food type, months_passed, food base_cost,
** and how much money user has in bank.
******************************************************/

#ifndef Zoo_H
#define Zoo_H

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "Animal.h"
#include "SeaLion.h"
#include "Bear.h"
#include "Tiger.h"
#include "Array.h"
#include "Array.cpp"
#include <cmath>
using namespace std;

class Zoo{
	private:
		int bank;
		int months_passed;
		int food_type; 	
		int base_cost;
		Array<Tiger> t;
		Array<Bear> b;
		Array<SeaLion> s;
	public:
		Zoo();
		bool is_int(string);
		int get_int(string);
		void main_game();
		bool spec_event();
		int calc_prob();
		void print_welcome_message();
		void print_monthly_info();
		int sick_event();
		void baby_event();
		int boom_event();
		bool bankruptcy_check();
		void collect_revenue();
		void age_up_animals();
		void test();
		void buying_animals();
		bool can_afford(string, int);
		string error_handle_response1();
		float calc_food_costs(float);
		void change_food_costs();
		float buying_food();
		float can_afford_food(int);
		void print_food_info();
		int calculate_sick_costs(int, int, int);
};

#endif
