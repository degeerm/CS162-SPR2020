/******************************************************
 * ** Program Name: Wumpus.h
 * ** Author: Miya DeGeer 
 * ** Date: 05/24/2020
 * ** Description: Interface file for the wumpus class. 
 * ** Overrides the percept, encounter, and print_event
 * ** function. 
 * ******************************************************/

#ifndef Wumpus_H
#define Wumpus_H

#include "Event.h"

using namespace std;


class Wumpus : public Event{
	public:
		Wumpus();
		void percept();
		void encounter(int &, int &, bool &,int);
		void print_event();
};

#endif
