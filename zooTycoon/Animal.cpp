/*****************************************************
** Program Name: Animal.cpp 
** Author: Miya DeGeer
** Date: 05/10/2020
** Description: Implementation file for Animal class.
** Has constructors, getters/setters, and a few
** that have special functionality (such as change age and
** get sick costs).
** Input: float
** Output: int
******************************************************/
#include "Animal.h"

using namespace std;

/*********************************************************************
 * ** Description: Acts as the default constructor for the animal class.
 * ** Initializes all values to 0, except for the default food cost.
 * ** Parameters: None.
 * ** Pre-Conditions: None.
 * ** Post-Conditions: An animal object is created.
 * *********************************************************************/
Animal::Animal(){
	age = 0;
	cost = 0;
	babies = 0;
	food_cost = 80;
	revenue = 0;
};

/*********************************************************************
 * ** Description: Returns the food cost from animal object. 
 * ** Parameters: None. 
 * ** Pre-Conditions: Animal object is declared elsewhere.
 * ** Post-Conditions: Food cost returned as integer.
 * *********************************************************************/
int Animal::get_food_cost(){
	return food_cost;
}

/*********************************************************************
 * ** Description: Returns the baby amount from animal object. 
 * ** Parameters: None. 
 * ** Pre-Conditions: Animal object is declared elsewhere.
 * ** Post-Conditions: babies returned as integer.
 * *********************************************************************/
int Animal::get_babies(){
	return babies;
}

/*********************************************************************
 * ** Description: Returns the age from animal object. 
 * ** Parameters: None. 
 * ** Pre-Conditions: Animal object is declared elsewhere.
 * ** Post-Conditions: Age returned as integer.
 * *********************************************************************/
int Animal::get_age(){
	return age;
}

/*********************************************************************
 * ** Description: Returns the cost from animal object. 
 * ** Parameters: None. 
 * ** Pre-Conditions: Animal object is declared elsewhere.
 * ** Post-Conditions: Cost returned as integer.
 * *********************************************************************/
int Animal::get_cost(){
	return cost;
}

/*********************************************************************
 * ** Description: Returns the revenue from animal object. 
 * ** Parameters: None. 
 * ** Pre-Conditions: Animal object is declared elsewhere.
 * ** Post-Conditions: Revenue returned as integer.
 * *********************************************************************/
int Animal::get_revenue(){
	return revenue;
}

/*********************************************************************
 * ** Description: Changes the revenue an animal makes (to be used when
 * ** changing the worth of babies) 
 * ** Parameters: None.
 * ** Pre-Conditions: Animal object is declared elsewhere.
 * ** Post-Conditions: Animal object revenue is halved.
 * *********************************************************************/
void Animal::change_revenue(){
	revenue = revenue / 2;
}

/*********************************************************************
 * ** Description: Changes the cost of the animals food. 
 * ** Parameters: float
 * ** Pre-Conditions: float and animal object are both declared elsewhere.
 * ** Post-Conditions: the food_cost is multiplied by the variable n.
 * *********************************************************************/
void Animal::change_food_cost(float n){
	food_cost = food_cost * n;
}

/*********************************************************************
 * ** Description: Ages up the animal.
 * ** Parameters: None.
 * ** Pre-Conditions: Animal object is declared elsewhere.
 * ** Post-Conditions: Animal age increased by 1 month.
 * *********************************************************************/
void Animal::change_age(){
	age++;
}

/*********************************************************************
 * ** Description: Determines what the cost of getting sick is for
 * ** an animal.
 * ** Parameters: None. 
 * ** Pre-Conditions: Animal object is declared elsehere.
 * ** Post-Conditions: Cost of getting sick is returned as integer.
 * *********************************************************************/
int Animal::get_sick_cost(){
	if (age < 6){
		return cost;
	}
	return (cost/2);
}
