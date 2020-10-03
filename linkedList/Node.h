/******************************************************
 * ** Program Name: Node.h 
 * ** Author: Miya DeGeer 
 * ** Date: 06/07/2020
 * ** Description: Interface file for the Node class. A Node
 * ** object stores a signed integer value, as well as the
 * ** address of the next node in the list. Contains constructors.
 * ******************************************************/

#ifndef Node_H
#define Node_H

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Node{
	public:
		int val;
		Node* next;

		Node();
		Node(int);
};

#endif
