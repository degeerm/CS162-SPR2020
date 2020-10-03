/*****************************************************
** Program Name: SeaLion.h 
** Author: Miya DeGeer
** Date: 05/10/2020
** Description: Interface file for SeaLion class (inherits
** from Animal class).
******************************************************/

#ifndef SeaLion_H
#define SeaLion_H

#include <iostream>
#include "Animal.h"
using namespace std;

class SeaLion : public Animal{
	public:
		SeaLion();
		SeaLion(int,int);
};

#endif

