/******************************************************
 * ** Program Name: Bat.cpp
 * ** Author: Miya DeGeer 
 * ** Date: 05/24/2020
 * ** Description: Implementation file for the bat class.
 * ** Overrides event functions.
 * ******************************************************/

#include "Bat.h"

using namespace std;

/*********************************************************************
 * ** Description: Default constrcutor for the bat class. Sets the event
 * ** num to 2. 
 * ** Parameters: None.
 * ** Pre-Conditions: None.
 * ** Post-Conditions: Creates a bat object.
 * *********************************************************************/
Bat::Bat(){
	event_num = 2;
}

/*********************************************************************
 * ** Description: Inherited from event class. Prints out the appropriate
 * ** method for the bat class.  
 * ** Parameters: None.
 * ** Pre-Conditions:  Bat object has been created elsewhere.
 * ** Post-Conditions: Message printed to the screen.
 * *********************************************************************/
void Bat::percept(){
	cout << "You hear the flapping of wings." << endl;
}

/*********************************************************************
 * ** Description: Inherited from event class. Randomly selects two numbers
 * ** within the size limit, s, and assigns those to x and y.
 * ** Parameters: int&, int&, bool&, int
 * ** Pre-Conditions:  All variables + bat object have been declared 
 * ** elsewhere.
 * ** Post-Conditions: x and y are altered appropriately.
 * *********************************************************************/
void Bat::encounter(int &x, int &y, bool &g, int s){
	srand(time(NULL));
	x = rand() % s;	
	y = rand() % s;
}

/*********************************************************************
 * ** Description: To be used when printing things to the board. 
 * ** Parameters: None.
 * ** Pre-Conditions: Bat object has been declared elsewhere.
 * ** Post-Conditions: B is printed to the screen.
 * *********************************************************************/
void Bat::print_event(){
	cout << "B";
}
