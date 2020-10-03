/******************************************************
 * ** Program Name: Node.cpp
 * ** Author: Miya DeGeer 
 * ** Date: 06/07/2020
 * ** Description: Implementation file for the Node class. A Node
 * ** object stores a signed integer value, as well as the
 * ** address of the next node in the list. Contains constructors.
 * ******************************************************/
#include "Node.h"

using namespace std;
/*********************************************************************
 * ** Description: 
 * ** Parameters:
 * ** Pre-Conditions:  
 * ** Post-Conditions: 
 * *********************************************************************/


/*********************************************************************
 * ** Description: Default constructor for the node class. Sets the value to
 * ** zero, and the value of next to NULL. 
 * ** Parameters: None.
 * ** Pre-Conditions: None.
 * ** Post-Conditions: Node object with above description is created.
 * *********************************************************************/
Node::Node(){
	val= 0;
	next = NULL;
}

/*********************************************************************
 * ** Description: Alternate constructor for the node class. Sets the value
 * ** to v, and the value of next to NULL. 
 * ** Parameters: int
 * ** Pre-Conditions: int has been declared elsewhere.  
 * ** Post-Conditions: Node object with above description is created.
 * *********************************************************************/
Node::Node(int v){
	val = v;
	next = NULL;
}
