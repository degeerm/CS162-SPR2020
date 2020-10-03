/******************************************************
 * ** Program Name: driver.cpp
 * ** Author: Miya DeGeer 
 * ** Date: 06/07/2020
 * ** Description: Driver file. Has a program for entering,
 * ** accessing, sorting, and printing values of a linked
 * ** list. Then, has a small program for implementing function
 * ** that I didn't use during the first program. 
 * ******************************************************/

#include "Linked_List.h"
using namespace std;


/*********************************************************************
 * ** Description: Runs through the entering/sorting elements program
 * ** outlined in the assignment (described in more detail in linked List
 * ** file). Also includes an optional little demo for the insert and
 * ** get_length functions, just to prove they work since i didn't use
 * ** them during the program.
 * ** Parameters: None.
 * ** Pre-Conditions: None.
 * ** Post-Conditions: Runs through above description. When that ends,
 * ** program ends.
 * *********************************************************************/
int main(){
	//main program demonstration
	Linked_List l1;
	l1.main_loop();

	//other functionality demo (utilizes insert and get_length, not used in original
	// program, to show that they work)
	/*l1.push_back(3);
	l1.push_back(5);
	l1.push_back(6);
	l1.push_back(7);
	l1.push_back(8);
	l1.push_front(2);
	l1.push_front(1);

	cout << "\n\n+-+-+-+-OTHER FUNCTIONALITY DEMO-+-+-+-+" << endl;
	cout << "\nOriginal Demo List: " << endl;
	l1.print();
	cout << "Length: " << l1.get_length() << endl;
	cout << "\nInserting at beginning: " << endl;
	l1.insert(0, 0);
	l1.print();
	cout << "Length: " << l1.get_length() << endl;
	cout << "\nInserting at end: " << endl;
	l1.insert(9, 7);
	l1.print();
	cout << "Length: " << l1.get_length() << endl;
	cout << "\nInserting Elsewhere " << endl;
	l1.insert(4, 4);
	l1.print();
	cout << "Length: " << l1.get_length() << endl;
	l1.clear();
	*/	
	return 0;
}
