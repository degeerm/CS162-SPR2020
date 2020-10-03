/******************************************************
 * ** Program Name: Linked_List.cpp
 * ** Author: Miya DeGeer 
 * ** Date: 06/07/2020
 * ** Description: Implementation file for the Linked_List class.
 * ** An object stores the length of the list, and the 
 * ** location of the head node. Has accessors, mutators,
 * ** sorting and printing functions, as well as a few for
 * ** checking input.
 * ******************************************************/
#include "Linked_List.h"

using namespace std;

/********************************************************************
** Function: to_lower
** Description: changes all uppercase letters to lowercase
** Parameters: string sentence
** Pre-Conditions: Correct string given into to_lower
** Post-Conditions: Returns sentence with all lowercase + other chars
*********************************************************************/
string Linked_List::to_lower(string sentence){
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
 * ** an signed integer.
 * ** Parameters: string
 * ** Pre-Conditions: String has been defined elsewhere
 * ** Post-Conditions: True or false is returned, depending on if string 
 * ** is an int or not.
 * *********************************************************************/
bool Linked_List::is_int(string num){
	int minus_counter = 0;
	for (int i = 0; i < num.length(); i++){
		if ((int)num.at(i) < 48 or (int)num.at(i) > 57){
			if (num.at(i) == '-' && minus_counter <= 0 && i==0){
				minus_counter++;
			}else{
				return false;
			}
		}
	}
	return true;
}

/*********************************************************************
 * ** Description: Takes in a string prompt, and if it is an integer,
 * ** returns the integer version of it.
 * ** Parameters: string
 * ** Pre-Conditions: String has been defined elsewhere.
 * ** Post-Conditions: integer version of string returned
 *********************************************************************/
int Linked_List::get_int(string prompt){
	int sum = 0;
	int minus_counter = 0;
	int len = prompt.length();
		if (prompt.find('-') != -1){
			len = len - 1;
			prompt.erase(0,1);
			minus_counter = 1;	
		}
	if (is_int(prompt)){
		for (int i = len-1; i >= 0; i--){
			char current = (int)prompt.at(i) - 48;
			sum += (current * pow(10,((len-1)-i)));
		}
	}
		if (minus_counter == 1)
			sum *=-1;
	return sum;
}

/*********************************************************************
 * ** Description: Default constructor for the linked list. Sets the length
 * ** to zero, and the head node to NULL. 
 * ** Parameters: None.
 * ** Pre-Conditions: None.
 * ** Post-Conditions: Linked List with above description is created.
 * *********************************************************************/
Linked_List::Linked_List(){
	length = 0;
	head = NULL;
}

/*********************************************************************
 * ** Description: Gets the length of the linked list.
 * ** Parameters: None.
 * ** Pre-Conditions: Linked List has been created elsewhere.
 * ** Post-Conditions: length of Linked List returned as an integer.
 * *********************************************************************/
int Linked_List::get_length(){
	return length;
}

/*********************************************************************
 * ** Description: Deletes all of the nodes (since they're dynamically
 * ** allocated) off the stack, sets the length to zero.
 * ** Parameters: None.
 * ** Pre-Conditions: Linked List has been created elsewhere.
 * ** Post-Conditions: All memory taken off heap, length set to zero.
 * *********************************************************************/
void Linked_List::clear(){
	Node* current = head;
	for (int i = 0; i < length; i++){
		Node* temp = current;
		current = temp-> next;
		delete temp;
	}
	length = 0;
}

/*********************************************************************
 * ** Description: Pushes an element to the back of the linked list- iterates
 * ** until it reaches the current last element, sets that next value to a
 * ** new node. Increases length by 1, returns length. 
 * ** Parameters: int
 * ** Pre-Conditions: int & linkedlist has been declared elsewhere.  
 * ** Post-Conditions: New length is returned. 
 * *********************************************************************/
unsigned int Linked_List::push_back(int v){	
	Node* temp = new Node(v);
	if (head == NULL){
		head = temp;
		head ->next = NULL;
	}
	Node* current = head;
	
	if (length !=0){	
		while (current && current->next){
			current = current->next;
		}
		current -> next = temp;
		temp -> next = NULL;
	}
	length++;
	return (length);
 
}

/*********************************************************************
 * ** Description: Puts a node at the front of list; sets the head of
 * ** the linked list to the new value, and sets next to old head. Increases
 * ** length by one, returns length.
 * ** Parameters: int
 * ** Pre-Conditions: int & linked list has been declared elsewhere  
 * ** Post-Conditions: New length is returned
 * *********************************************************************/
unsigned int Linked_List::push_front(int v){
	Node* temp = new Node(v);
	if (head == NULL){
		head = temp;
		head->next = NULL;
	}
	Node* temp_one = head;
	head = temp;
	head->next = temp_one;
	length++;
	return length;
}

/*********************************************************************
 * ** Description: Displays the contents of a linked list for the user
 * ** directly to the screen.
 * ** Parameters: None.
 * ** Pre-Conditions:  Linked List has been declared elsewhere.
 * ** Post-Conditions: Contents of linked list printed to screen.
 * *********************************************************************/
void Linked_List::print(){
	Node* current = head;
	for (int i = 0; i < length; i++){
		cout << "Element at " << i << ":  " << current->val << endl;
		current = current->next;

	}

}

/*********************************************************************
 * ** Description: Inserts a value at a given index. Checks to see if
 * ** its beginning/end. If not, iterates up until new points and resets
 * ** surroudning values. Returns new length.
 * ** Parameters: int, unsigned int
 * ** Pre-Conditions: both ints and linked list have been declared
 * ** elsewhere
 * ** Post-Conditions: New length is returned
 * *********************************************************************/
unsigned int Linked_List::insert(int val, unsigned int index){
	int l;
	if (index == 0){
		return (push_front(val));	
	}else if (index == length-1){
		return (push_back(val));
	}
	Node* current = head;
	Node* prev;
	for (int i = 0; i < length; i++){
		if (i == index){
			Node* temp = new Node(val);
			temp->next = current;
			prev ->next = temp;
		}else{
			prev = current;
			current = current->next;
		}
	}
	return (++length);

}

/*********************************************************************
 * ** Description: Counts the number of prime numbers in a linked list.
 * ** Returns that value.
 * ** Parameters: None.
 * ** Pre-Conditions:  Linked List has been declared elsewhere.
 * ** Post-Conditions: Number of prime numbers is returned.
 * *********************************************************************/
int Linked_List::count_prime(){
	int num_prime = 0;
	Node* current = head;
	for (int i =0;i < length; i++){
		for (int j = 2; j <= current-> val; j++){
			if (j == current-> val){
				num_prime++;
				break;
			}else if (current->val % j == 0){
				break;
			}
		}
		current = current->next;
	}
	return num_prime;
}

/*********************************************************************
 * ** Description: Copies the values of an old linked list into this one.
 * ** Parameters: Linked_List
 * ** Pre-Conditions: Linked List has been declared elsewhere.
 * ** Post-Conditions: Values are copied over into this lists.
 * *********************************************************************/
void Linked_List::copy_list(Linked_List l){
	Node* current = l.head;
	for (int i = 0; i<l.length; i++){
		this->push_back(current->val);
		current= current->next;
	}
}

/*********************************************************************
 * ** Description: Framework for the list looping function. Continues
 * ** cylcing through user input accepting numbers. Error handles number
 * ** inputs and choice inputs.
 * ** Parameters: None.
 * ** Pre-Conditions: Linked List has been declared elsewhere
 * ** Post-Conditions: Numbers are added to a Linked List until user wants
 * ** to stop.
 * *********************************************************************/
void Linked_List::list_loop(){
	string r;
	while (true){
		cout << "Please enter a number." << endl;
		cin >> r;
		if (is_int(r)){
			push_back(get_int(r));
		}else{
			cout << "Error: Please only enter an integer number." << endl;
			continue;
		}	
		while (true){
			cout << "Would you like to enter another number? (y or n)" << endl;
			cin >> r;
			if (to_lower(r) == "n"){
				return;
			}else if (to_lower(r) != "y"){
				cout << "Error: Please only enter y or n. Please enter again." << endl;
			}else{
				break;
			}
		}
	}
}

/*********************************************************************
 * ** Description: Sorts the list in an ascending order. Calls a recursive
 * ** sort function.
 * ** Parameters: None.
 * ** Pre-Conditions: Linked List has been declared elsewhere.
 * ** Post-Conditions: Head is set to sorted list done by main sort.
 * *********************************************************************/
void Linked_List::sort_ascending(){
	head = main_sort(head, true);
}

/*********************************************************************
 * ** Description: Sorts the list in an descending order. Calls a recursive
 * ** sort function.
 * ** Parameters: None.
 * ** Pre-Conditions: Linked List has been declared elsewhere.
 * ** Post-Conditions: Head is set to sorted list done by main sort.
 * *********************************************************************/
void Linked_List::sort_descending(){
	head = main_sort(head, false);
}

/*********************************************************************
 * ** Description: Main sorting algorithm. Base case: If head OR
 * ** head-> next is NULL (tiny lists). Splits list down the middle and sorts both
 * ** sides of the list seperately. If choice is true, calls ascending
 * ** merge_lists_function. Otherwise, does descending.
 * ** Parameters: Node*, bool
 * ** Pre-Conditions: Node*, bool, and Linked List have all been declared.
 * ** Post-Conditions: Returns the sorted head of the list.
 * *********************************************************************/
Node* Linked_List::main_sort(Node* source, bool choice){
	Node* sorted;
	if (source == NULL || source ->next == NULL){
		return source;
	}

	Node* middle_node = find_middle(source);
	Node* next_to_middle = middle_node->next;
	middle_node->next = NULL;

	Node* left_list = main_sort(source, choice);
	Node* right_list = main_sort(next_to_middle, choice);
	if(choice){
		sorted = merge_lists_a(left_list, right_list);
	}else{
		sorted = merge_lists_d(left_list, right_list);
	}
	return sorted;

}

/*********************************************************************
 * ** Description: Does the majority of the actual "sorting". Takes in two
 * ** nodes, base case is if either is NULL. Checks to see which one is
 * ** smaller, and returns that node to be added to the list. Calls it
 * ** again. The last smallest (IE, the biggest) will be added last.
 * ** DONE FOR THE ASCENDING CASE
 * ** Parameters: Node*, Node*
 * ** Pre-Conditions: Both Node pointers and the Linked List have been
 * ** declared.
 * ** Post-Conditions: Returns the head of the sorted list.
 * *********************************************************************/
Node* Linked_List::merge_lists_a(Node* one, Node* two){
	Node* return_node = NULL;
	if (one == NULL){
		return two;
	}if (two == NULL){
		return one;
	}
	if (two->val >= one->val){
		return_node = one;
		return_node->next = merge_lists_a(one->next, two);
	}else{
		return_node = two;
		return_node->next = merge_lists_a(one, two->next);
	}
	return return_node;
}

/*********************************************************************
 * ** Description: Does the majority of the actual "sorting". Takes in two
 * ** nodes, base case is if either is NULL. Checks to see which one is
 * ** bigger, and returns that node to be added to the list. Calls it
 * ** again. The last biggest (IE, the smallest) will be added last.
 * ** DONE FOR THE DESCENDING CASE
 * ** Parameters: Node*, Node*
 * ** Pre-Conditions: Both Node pointers and the Linked List have been
 * ** declared.
 * ** Post-Conditions: Returns the head of the sorted list.
 * *********************************************************************/
Node* Linked_List::merge_lists_d(Node* one, Node* two){
	Node* return_node = NULL;
	if (one == NULL){
		return two;
	}if (two == NULL){
		return one;
	}
	if (two->val <= one->val){
		return_node = one;
		return_node->next = merge_lists_d(one->next, two);
	}else{
		return_node = two;
		return_node->next = merge_lists_d(one, two->next);
	}
	return return_node;
}

/*********************************************************************
 * ** Description: Finds the middle of a list. Iterates through with
 * ** one being the slower node and two being the faster node. Everytime
 * ** the slower node advances one, the faster node advances two. Does this
 * ** until it reaches the end, and one will be halfway point.
 * ** Parameters: Node*
 * ** Pre-Conditions: Node* 
 * ** Post-Conditions: Returns the location of the middle node in the list.
 * *********************************************************************/
Node* Linked_List::find_middle(Node* source){
	if (source == NULL){
		return source;
	}

	Node* one = source;
       	Node* two = source;
	while (two->next != NULL && two->next->next != NULL){
		one = one->next;
		two = two->next->next;
	}
	
	return one;

}

/*********************************************************************
 * ** Description: Acts as the main frameowrk for the loop. Goes through 
 * ** and accepts input for list until user wants to stop, makes sorting
 * ** choice selection, then asks if they want to go again. Clears all memory.
 * ** Parameters: None.
 * ** Pre-Conditions: Linked List has been created elsewhere.
 * ** Post-Conditions: All memory cleared off heap.
 * *********************************************************************/
void Linked_List::main_loop(){
	string r;
	while (true){
		Linked_List sorted, unsorted;
		unsorted.list_loop();
		unsorted.print();
		sorted.copy_list(unsorted);
		bool choice = sort_options();
		if (choice){
			sorted.sort_ascending();
		}else{
			sorted.sort_descending();
		}
		sorted.print();
		cout << "You have " << sorted.count_prime() << " prime numbers in your list." << endl;	
		unsorted.clear();
		sorted.clear();
		while (true){
			cout << "Would you like to do this again? (y/n)" << endl;
			cin >> r;
			if (to_lower(r) == "n"){
				return;
			}else if (to_lower(r) != "y"){
				cout << "Error: Please only enter yes or no." << endl;
			}else{	
				break;
			}
		}

	}

}

/*********************************************************************
 * ** Description: Offers sorting options to the user: Returns true if
 * ** they want to sort ascending, false if they want to sort descending.
 * ** Error handles too, keeps asking input until good input given. 
 * ** Parameters: None.
 * ** Pre-Conditions: Linked List has been delared elsewhere.
 * ** Post-Conditions: Returns true if sorting ascending, false otherwise.
 * *********************************************************************/
bool Linked_List::sort_options(){
	string response;
	while (true){
		cout << "Sort ascending (a) or descending (d)?" << endl;
		cin >> response;
		if (to_lower(response) == "a"){
			return true;
		}else if (to_lower(response) == "d"){
			return false;
		}else{
			cout << "Error: Please only select a or d." << endl;
		}
	}
}
