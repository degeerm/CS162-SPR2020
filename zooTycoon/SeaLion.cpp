/*****************************************************
** Program Name: SeaLion.cpp 
** Author: Miya DeGeer
** Date: 05/10/2020
** Description: Implementation file for the SeaLion
** class. Has constructors, inherits from Animal.
** Input: int
** Output: None
******************************************************/
#include "SeaLion.h"
using namespace std;

/*********************************************************************
 * ** Description: Default constructor for the sea lion class. Initializes
 * ** all values to SeaLion specific ones.
 * ** Parameters: None.
 * ** Pre-Conditions: None. 
 * ** Post-Conditions: SeaLion object is created.
 * *********************************************************************/
SeaLion::SeaLion(){
	cost = 800;
	babies = 1;
	revenue = 120;
}

/*********************************************************************
 * ** Description: Alternate constructor for sea lion class. Initializes
 * ** all values to SeaLion specific ones, takes in age/base cost. 
 * ** Parameters: int, int
 * ** Pre-Conditions: Both integers have been declared elsewhere
 * ** Post-Conditions: SeaLion object created with above description.
 * *********************************************************************/
SeaLion::SeaLion(int a, int b){
	cost = 800;
	babies = 1;
	if (a < 6){
		revenue = 240;
	}else{
		revenue = 120;
	}
	age = a;
	food_cost = b;
}

