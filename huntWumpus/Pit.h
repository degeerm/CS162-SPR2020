/******************************************************
 * ** Program Name: Pit.h
 * ** Author: Miya DeGeer 
 * ** Date: 05/24/2020
 * ** Description: Interface file for the pit class. Overrides
 * ** from the event class.
 * ******************************************************/

#ifndef Pit_H
#define Pit_H

#include "Event.h"

using namespace std;

class Pit : public Event{
	public:
		Pit();
		void percept();
		void encounter(int&, int&, bool&, int);
		void print_event();
};

#endif
