/******************************************************
 * ** Program Name: check_functions.cpp
 * ** Author: Miya DeGeer 
 * ** Date: 05/24/2020
 * ** Description: Implementation file for check_functions.
 * ** Has functions for checking inputs, altering strings,
 * ** and getting integers.
 * ** Input: string, int
 * ** Output: String, bool, int
 * ******************************************************/

#include "check_functions.h"

using namespace std;

/********************************************************************
** Function: to_lower
** Description: changes all uppercase letters to lowercase
** Parameters: string sentence
** Pre-Conditions: Correct string given into to_lower
** Post-Conditions: Returns sentence with all lowercase + other chars
*********************************************************************/
string to_lower(string sentence){
	string return_sentence;
	for (int i = 0; i < sentence.length(); i++){
		if ((int)sentence.at(i) >= 65 
		and (int)sentence.at(i) <= 90){
			return_sentence += (char)((int)sentence.at(i) + 32);
		}
		else{
			return_sentence += sentence.at(i);
		}
	}
	
	return return_sentence;
}

/*********************************************************************
 * ** Description: Determines if a given string could be converted into
 * ** an integer.
 * ** Parameters: string
 * ** Pre-Conditions: String has been defined elsewhere
 * ** Post-Conditions: True or false is returned, depending on if string 
 * ** is an int or not.
 * *********************************************************************/
bool is_int(string num){
	if (num.length() == 0){
		return false;
	}
	for (int i = 0; i < num.length(); i++){
		if ((int)num.at(i) < 48 or (int)num.at(i) > 57){
			return false;
		}
	}
	return true;
}

/*********************************************************************
 * ** Description: Takes in a string prompt, and if it is an integer,
 * ** returns the integer version of it. (Does not work for negative
 * ** integers)
 * ** Parameters: string
 * ** Pre-Conditions: String has been defined elsewhere.
 * ** Post-Conditions: Integer version of string is returned, -1 otherwise.
 * *********************************************************************/
int get_int(string prompt){
	int sum = 0;
	int len = prompt.length();
	if (is_int(prompt)){
		for (int i = len-1; i >= 0; i--){
			char current = (int)prompt.at(i) - 48;
			sum += (current * pow(10,((len-1)-i)));
		}
	}else{
		return -1;
	}
	return sum;
}

/*********************************************************************
 * ** Description: To be used with the command line inputs; makes sure
 * ** the numbers are integers and greater than 4. If flagger is passed
 * ** in, doesn't give error (bc error's been given earlier) 
 * ** Parameters: string
 * ** Pre-Conditions: string has been declared elsewhere
 * ** Post-Conditions: integer size is returned once its correct
 * *********************************************************************/
int size_input_checker(string s){
	while (true){
		if (s == "flagger"){
			cout << "Please enter your size." << endl;
			cin >> s;
			cin.ignore();
		}
		else if (is_int(s)){
			if (get_int(s) >= 4){
				return (get_int(s));
			}else{
				cout << "Error: Size can be no less than 4. Please re-enter your size." << endl;
				cin >> s;
				cin.ignore();
			}
		}else{
			cout << "Error: Integers greater than/equal to 4 only. Please re-enter your size." << endl;
			cin >> s;
			cin.ignore();
		}
	}

}

/*********************************************************************
 * ** Description: Determines if string passed in is true or false, otherwise
 * ** goes through reentering protocols. if flagger is passed in, doesn't
 * ** give error (as its been given earlier)
 * ** Parameters: string
 * ** Pre-Conditions:  string is declared elsewhere
 * ** Post-Conditions: Boolean version of debug mode is returned.
 * *********************************************************************/
bool debug_input_checker(string s){
	while (true){
		s = to_lower(s);
		if (s == "flagger"){
			cout << "Please enter true if you want debug mode, false otherwise." << endl;
			cin >> s;
			cin.ignore();
		}else if(s == "true"){
			return true;
		}else if (s == "false"){
			return false;
		}else{
			cout << "Error: Please only enter 'true' or 'false'. Please re-enter debug mode choice." << endl;
			cin >> s;
			cin.ignore();
		}
	}
}
