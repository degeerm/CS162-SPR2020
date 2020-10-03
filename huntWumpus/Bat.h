/******************************************************
 * ** Program Name: Bat.h
 * ** Author: Miya DeGeer 
 * ** Date: 05/24/2020
 * ** Description: Interface file for the bat class.
 * ** Overrides functions from the Event class. 
 * ******************************************************/

#ifndef Bat_H
#define Bat_H

#include "Event.h"
#include <stdlib.h>
#include <ctime>
using namespace std;

class Bat : public Event{
	public:
		Bat();
		void percept();
		void encounter(int&,int&,bool&,int);
		void print_event();

};

#endif
