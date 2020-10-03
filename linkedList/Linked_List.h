/******************************************************
 * ** Program Name: Linked_List.h
 * ** Author: Miya DeGeer 
 * ** Date: 06/07/2020
 * ** Description: Interface file for the Linked_List class.
 * ** An object stores the length of the list, and the 
 * ** location of the head node. Has accessors, mutators,
 * ** sorting and printing functions, as well as a few for
 * ** checking input.
 * ******************************************************/

#ifndef Linked_List_H
#define Linked_List_H
#include "Node.h"
using namespace std;

class Linked_List{
	private:
		unsigned int length;
		Node* head;
	public:
		string to_lower(string);
		bool is_int(string);
		int get_int(string);
		Linked_List();
		int get_length();
		void print();
		void clear();
		unsigned int push_back(int);
		unsigned int push_front(int);
		unsigned int insert(int, unsigned int);
		bool sort_options();
		void sort_ascending();
		void sort_descending();
		Node* merge_lists_a(Node*, Node*);
		Node* merge_lists_d(Node*, Node*);
		void split(Node*, Node**, Node**);
		Node* find_middle(Node* source);
		Node* main_sort(Node*, bool);
		int count_prime();
		void main_loop();
		void list_loop();
		void copy_list(const Linked_List);


};

#endif
