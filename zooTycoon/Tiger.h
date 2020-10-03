/*****************************************************
** Program Name: Tiger.h 
** Author: Miya DeGeer
** Date: 05/10/2020
** Description: Interface file for Tiger class (inherits
** from animal).
******************************************************/
#ifndef Tiger_H
#define Tiger_H

#include <iostream>
#include "Animal.h"
using namespace std;

class Tiger : public Animal{
	public:
		Tiger();
		Tiger(int, int);
		void change_food_cost(float);
};

#endif

