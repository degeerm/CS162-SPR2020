/*****************************************************
** Program Name: Bear.cpp 
** Author: Miya DeGeer
** Date: 05/10/2020
** Description: Implementation file for the Bear class. Has
** constructors, and special function for changing food costs.
** Inherits from Animal.
** Input: int, float
** Output: None.
******************************************************/

#include "Bear.h"
using namespace std;

/*********************************************************************
 * ** Description: Default constructor for the bear class. Sets all
 * ** member variables to appropriate values. 
 * ** Parameters: None.
 * ** Pre-Conditions: None.
 * ** Post-Conditions: Bear object is created.
 * *********************************************************************/
Bear::Bear(){
	cost = 6000;
	babies = 2;
	revenue = 600;
	food_cost*=3;
}

/*********************************************************************
 * ** Description: Alternate constructor for bear class. Sets age to a,
 * ** calculates revenue based on a, and takes in b for base cost. 
 * ** Parameters: int, int
 * ** Pre-Conditions: None.
 * ** Post-Conditions: Bear object is created with above description.
 * *********************************************************************/
Bear::Bear(int a, int b){
	babies = 2;
	if (a <6){
		revenue = 1200;
	}else{
		revenue = 600;
	}
	food_cost = b * 3;
	age = a;
	cost = 6000;
}

/*********************************************************************
 * ** Description: Updates the food cost for the bear class. 
 * ** Parameters: float
 * ** Pre-Conditions: float and Bear object have been declared elsewhere
 * ** Post-Conditions: Food cost is multiplied by n.
 * *********************************************************************/
void Bear::change_food_cost(float n){
	food_cost = food_cost /3;
	food_cost = food_cost * n;
	food_cost = food_cost * 3;
}
