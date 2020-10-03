/******************************************************
 * ** Program Name: Event.cpp
 * ** Author: Miya DeGeer 
 * ** Date: 05/24/2020
 * ** Description: Implementation file for the Event class. 
 * ** Has a default constructor (which isnt used) and a getter
 * ** for an identifier.
 * ******************************************************/
#include "Event.h"

using namespace std;


/*********************************************************************
 * ** Description: Default constructor for the event class. Sets the event
 * ** num (which is the identifier to be used elsewhere) to a null value. 
 * ** Parameters: None.
 * ** Pre-Conditions:  None.
 * ** Post-Conditions: Event object is created.
 * *********************************************************************/
Event::Event(){
	event_num = 4;	
}

/*********************************************************************
 * ** Description: Returns the event num, to be used as an identifier.
 * ** 0 is wumpus, 1 is gold, 2 is bat, 3 is pit, 4 is null.
 * ** Parameters: None.
 * ** Pre-Conditions:  Event object has been intiailized elsewhere.
 * ** Post-Conditions: event num (as an int) is returned.
 * *********************************************************************/
int Event::get_event_num(){
	return event_num;
}
