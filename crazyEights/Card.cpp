/******************************************************
 * ** Program: Card.cpp
 * ** Author: Miya DeGeer
 * ** Date: 04/26/2020
 * ** Description: Acts as the implementation file for all
 * ** of the functions in the Card class. Card object
 * ** has a suit and a rank.
 * ******************************************************/

#include "Card.h"

using namespace std;

/*********************************************************************
 * ** Description: Default constructor for card class. Initializes suit
 * ** and rank to 0.
 * ** Parameters: None.
 * ** Pre-Conditions: None.
 * ** Post-Conditions:  Card object with above description constructed.
 * *********************************************************************/
Card::Card(){
	init(0,0);
}

/*********************************************************************
 * ** Description: Sets the values of a Card object to inputted ints.
 * ** Parameters: int, int
 * ** Pre-Conditions: Both ints and the card object have been declared
 * ** elsewhere.
 * ** Post-Conditions: Card object has a suit of a, rank of b.
 * *********************************************************************/
void Card::init(int a, int b){
	suit = a;
	rank = b;
}

/*********************************************************************
 * ** Description: Accessor: Returns the rank.
 * ** Parameters:   None.
 * ** Pre-Conditions: Card object has been declared elsewhere.
 * ** Post-Conditions: Integer rank is returned.
 * *********************************************************************/
int Card::get_rank(){	
	return rank;
}

/*********************************************************************
 * ** Description: Accessor: Returns the suit.
 * ** Parameters:   None.
 * ** Pre-Conditions: Card object has been declared elsewhere.
 * ** Post-Conditions: Integer suit is returned.
 * *********************************************************************/
int Card::get_suit(){
	return suit;
}

/*********************************************************************
 * ** Description: Maps the rank to a more user friendly version for the
 * ** user, returns string of that.
 * ** Parameters:  None.
 * ** Pre-Conditions: Card object has been declared elsewhere.
 * ** Post-Conditions: String version of rank returned.
 * *********************************************************************/
string Card::map_rank(){
	if (get_rank() >= 1 && get_rank() <= 9){
		string str = to_string(get_rank() + 1);
		return str;
	}
	else if (get_rank() == 0){
		return "Ace";
	}
	else if (get_rank() == 10){
		return "Jack";
	} 
	else if (get_rank() == 11){
		return "Queen";
	}
	else if (get_rank() == 12){
		return "King";
	}
}

/*********************************************************************
 * ** Description: Maps the suit to a more user friendly version for the
 * ** user, returns string of that.
 * ** Parameters:  None.
 * ** Pre-Conditions: Card object has been declared elsewhere.
 * ** Post-Conditions: String version of suit returned.
 * *********************************************************************/
string Card::map_suit(){
	if (suit == 0){
		return "Spades";
	}else if (suit == 1){
		return "Hearts";
	}else if (suit == 2){
		return "Diamonds";
	}else if (suit == 3){
		return "Clubs";
	}
}

/*********************************************************************
 * ** Description: Prints the card to the screen in a user-friendly format.
 * ** Parameters:  None.
 * ** Pre-Conditions: Card object has been declared elsewhere.
 * ** Post-Conditions: Card is printed to the screen.
 * *********************************************************************/
void Card::print_card(){
	cout << map_rank() << " of " << map_suit();
	cout << endl;
}

/*********************************************************************
 * ** Description: Determines if a particular card is playable, given 
 * ** an inputted suit and rank.
 * ** Parameters:  int, int
 * ** Pre-Conditions: Both ints and the card object have been declared
 * ** elsewhere.
 * ** Post-Conditions: Returns true if a card is playable, false otherwise.
 * *********************************************************************/
bool Card::can_play(int s, int r){
	if (rank == 7){
		return true;
	}
	else if (r == 7 && suit == s){
		return true;
	}
	else if (r == 7 && suit != s){
		return false;
	}
	else if (suit == s || rank == r){
		return true;
	}
	return false;
}
