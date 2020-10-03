#include "Pit.h"

using namespace std;

/*********************************************************************
 * ** Description: Default constrcutor for the pit object. 
 * ** Parameters: None.
 * ** Pre-Conditions:  None.
 * ** Post-Conditions: Pit object is created with event num 3.
 * *********************************************************************/
Pit::Pit(){
	event_num = 3;	
}

/*********************************************************************
 * ** Description: Prints out a message to the screen to signify that
 * ** player is near a bat. 
 * ** Parameters: None.
 * ** Pre-Conditions: Pit object has been declared elsewhere.
 * ** Post-Conditions: Message is printed to the screen.
 * *********************************************************************/
void Pit::percept(){
	cout << "You feel a breeze." << endl;
}

/*********************************************************************
 * ** Description: Returns -1 for both coordinates to be used in testing
 * ** (implies that the user has died) 
 * ** Parameters: int&, int&, bool&, int
 * ** Pre-Conditions:  All variables + pit object have been declared elsewhere.
 * ** Post-Conditions: Above description is carried out, variables modified.
 * *********************************************************************/
void Pit::encounter(int& x, int& y, bool& g, int){
	cout << "\n*+*+*+*Oh no! You've fallen into a bottomless pit!*+*+*+*" << endl;
	x = -1;
	y = -1;
}

/*********************************************************************
 * ** Description: Prints out a "P" to the screen, to be used when
 * ** printing the board. 
 * ** Parameters:None.
 * ** Pre-Conditions: Pit object has been declared elsewhere. 
 * ** Post-Conditions: P is printed to screen.
 * *********************************************************************/
void Pit::print_event(){
	cout << "P";
}
