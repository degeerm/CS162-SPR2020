/*****************************************************
** Program Name: Array.h 
** Author: Miya DeGeer
** Date: 05/10/2020
** Description: Interface file for Array class, which
** is a template class for arrays of Animals of different
** types. Dynamic.
******************************************************/

#ifndef Array_H
#define Array_H

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "Animal.h"
#include "Bear.h"
#include "SeaLion.h"
#include "Tiger.h"

using namespace std;

template <typename T>
class Array{
	private:
		T* array_;
		int size;
	public:
		Array();
		Array(int);
		~Array();
		Array(const Array &);
		Array& operator= (const Array&);
		T get_one_animal(int);
		void add_one_animal(T);
		void print_all_animals();
		int count_adults();
		int count_babies();
		int return_size();
		void age_up();
		int revenue();
		int sick_overview();
		int buying_animals(int,int);
		void baby_event(int);
		int buy_food(float);
		void change_food_costs(float);
		void remove_one_animal(int);	
};

#endif
