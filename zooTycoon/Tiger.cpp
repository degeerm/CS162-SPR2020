/*****************************************************
** Program Name: Tiger.cpp 
** Author: Miya DeGeer
** Date: 05/10/2020
** Description: Implementation file for Tiger class. Has
** constructors, inherits from Animal class. Has special
** redefinition of changing food cost.
** Input: int, float
** Output: None.
******************************************************/

#include "Tiger.h"
using namespace std;

/*********************************************************************
 * ** Description: Default constructor for the tiger class. Sets things
 * ** to the appropriate values. 
 * ** Parameters: None. 
 * ** Pre-Conditions: None.
 * ** Post-Conditions: Tiger object is created.
 * *********************************************************************/
Tiger::Tiger(){
	cost = 15000;
	babies = 3;
	revenue = 1500;
	food_cost*= 5;
}

/*********************************************************************
 * ** Description: Alternate constructor with paramters for tiger class.
 * ** Sets revenue depending on age, and takes in the current base cost.
 * ** Parameters: int, int
 * ** Pre-Conditions: Both ints have been declared elsewhere
 * ** Post-Conditions: Tiger with above description is created.
 * *********************************************************************/
Tiger::Tiger(int a, int b){
	if (a < 6){
		revenue = 3000;
	}else{
		revenue = 1500;
	}
	cost = 15000;
	babies = 3;
	food_cost =b* 5;
	age = a;

}

/*********************************************************************
 * ** Description: Updates the food cost for the tiger class; reverts
 * ** to base cost, applies changes, and then multiplies. 
 * ** Parameters: float
 * ** Pre-Conditions: float and tiger object have been declared elsewhere.
 * ** Post-Conditions: Food cost is multiplied by float n.
 * *********************************************************************/
void Tiger::change_food_cost(float n){
	
	food_cost = food_cost/5;
	food_cost = food_cost * n;
	food_cost = food_cost*5;
}
