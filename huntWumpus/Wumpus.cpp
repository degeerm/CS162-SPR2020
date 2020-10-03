/******************************************************
 * ** Program Name: Wumpus.cpp
 * ** Author: Miya DeGeer 
 * ** Date: 05/24/2020
 * ** Description: Implementation file for the Wumpus class.
 * ** Overrides functions from the event class.
 * ******************************************************/
#include "Wumpus.h"

using namespace std;

/*********************************************************************
 * ** Description: Default constructor for wumpus event. Sets event num
 * ** to 0. 
 * ** Parameters:None.
 * ** Pre-Conditions: None. 
 * ** Post-Conditions: Wumpus object is created.
 * *********************************************************************/
Wumpus::Wumpus(){
	event_num = 0;	
}

/*********************************************************************
 * ** Description: Inherited from the event class. Prints out message to
 * ** the screen.
 * ** Parameters: None.
 * ** Pre-Conditions:  Wumpus object is created elsewhere.
 * ** Post-Conditions: Message printed to the screen.
 * *********************************************************************/
void Wumpus::percept(){
	cout << "You smell a terrible stench." << endl;
}

/*********************************************************************
 * ** Description: Edits the coordinates to be -1, to be used for tetsing
 * ** (implies that the user has died) 
 * ** Parameters: int&, int&, bool&, int
 * ** Pre-Conditions: All variables + wumpus object has been declared
 * ** elsewhere.
 * ** Post-Conditions: coordinates edited as described above
 * *********************************************************************/
void Wumpus::encounter(int &x, int &y, bool &g, int s){
	cout << "\n*+*+*+*Oh no! You've entered the Wumpus's room and you've been eaten!*+*+*+*" << endl;
	x = -1;
	y = -1;
}

/*********************************************************************
 * ** Description: Prints out a "w", to be used when printing the board 
 * ** Parameters: None.
 * ** Pre-Conditions: Wumpus object has been declared elsewhere. 
 * ** Post-Conditions: W printed to screen.
 * *********************************************************************/
void Wumpus::print_event(){
	cout << "W";
}
