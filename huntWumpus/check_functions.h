/******************************************************
 * ** Program Name: check_functions.h
 * ** Author: Miya DeGeer 
 * ** Date: 05/24/2020
 * ** Description: Interface file for check_functions. Has
 * ** functions for checking strings, some of the user arguments
 * ** for hunt_wumpus, and integers.
 * ******************************************************/

#ifndef check_functions_H
#define check_functions_H

#include <iostream>
#include <cmath>
#include <string>

using namespace std;
	string to_lower(string);
	int size_input_checker(string);
	bool debug_input_checker(string);
	bool is_int(string);
	int get_int(string);


#endif
