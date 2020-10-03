/******************************************************
 * ** Program Name: Gold.h
 * ** Author: Miya DeGeer 
 * ** Date: 05/24/2020
 * ** Description: Interface file for the gold class.
 * ** Inherits from event class.
 * *****************************************************/

#ifndef Gold_H
#define Gold_H

#include "Event.h"

using namespace std;

class Gold : public Event{
	public:
		Gold();
		void percept();
		void encounter(int&, int&, bool&, int);
		void print_event();
};

#endif
