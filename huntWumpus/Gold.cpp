/******************************************************
 * ** Program Name: Gold.cpp
 * ** Author: Miya DeGeer 
 * ** Date: 05/24/2020
 * ** Description: Implementation file for the gold class.
 * ** Overrides functions from event.
 * *****************************************************/
#include "Gold.h"

using namespace std;

/*********************************************************************
 * ** Description: Default constrcutor for the gold class.  Sets the identifier
 * ** (the event num) to 1.
 * ** Parameters:None.
 * ** Pre-Conditions: None. 
 * ** Post-Conditions: Gold object is created.
 * *********************************************************************/
Gold::Gold(){
	event_num = 1;
}

/*********************************************************************
 * ** Description: Inherited from the event class. Prints out a message
 * ** to the screen when the player is nearby. 
 * ** Parameters: None.
 * ** Pre-Conditions: None. 
 * ** Post-Conditions: Message is printed to the screen.
 * *********************************************************************/
void Gold::percept(){
	cout << "You see a glimmer nearby." << endl;
}

/*********************************************************************
 * ** Description: Alters the boolean value (g) to be true when encounter
 * ** happens; signifies that player has picked up gold.
 * ** Parameters: int&, int&, bool&, int
 * ** Pre-Conditions: gold object + all variables have been declared elsewhere.
 * ** Post-Conditions: g is modified to be true.
 * *********************************************************************/
void Gold::encounter(int& x, int& y, bool& g, int s){
	cout << "You've picked up the gold!!" << endl;
	g = true;
}

/*********************************************************************
 * ** Description: Prints out "G" to the screen, to be used in print board. 
 * ** Parameters: None.
 * ** Pre-Conditions:  Gold object has been declared.
 * ** Post-Conditions: G is printed to the screen.
 * *********************************************************************/
void Gold::print_event(){
	cout << "G";
}
