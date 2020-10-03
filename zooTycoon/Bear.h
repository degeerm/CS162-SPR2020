/*****************************************************
** Program Name: Bear.h 
** Author: Miya DeGeer
** Date: 05/10/2020
** Description: Interface file for Bear class (inherits
** from animal).
******************************************************/

#ifndef Bear_H
#define Bear_H

#include <iostream>
#include "Animal.h"
using namespace std;

class Bear : public Animal{
	public:
		Bear();
		Bear(int, int);
		void change_food_cost(float);
};

#endif

