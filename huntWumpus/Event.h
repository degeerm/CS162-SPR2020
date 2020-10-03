/******************************************************
 * ** Program Name: Event.h
 * ** Author: Miya DeGeer 
 * ** Date: 05/24/2020
 * ** Description: Interface file for the Event class. Has
 * ** virtual methods to be inherited to child classes, 
 * ** as well as a getter that'll be used.
 * ******************************************************/

#ifndef Event_H
#define Event_H
#include <iostream>

using namespace std;

class Event{
	protected:
		int event_num;
	public:
		Event();
		virtual void percept() = 0;
		virtual void encounter(int &,int &,bool &,int) = 0;
		virtual void print_event() = 0;
		int get_event_num();
};

#endif
