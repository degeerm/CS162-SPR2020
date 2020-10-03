/******************************************************
 * ** Program: Hand.cpp
 * ** Author: Miya DeGeer
 * ** Date: 04/26/2020
 * ** Description: Acts as the implementation file for all
 * ** of the functions in the Hand class. Hand object
 * ** is an array of cards, as well as the number of cards
 * ** in the hand.
 * ******************************************************/

#include "Hand.h"

using namespace std;

/*********************************************************************
 * ** Description: Acts as the default constructor for the hand class.
 * ** Sets n_cards to 7 and creates a new list of cards.
 * ** Parameters: None.
 * ** Pre-Conditions: None.
 * ** Post-Conditions: Hand object created with description above.
 * *********************************************************************/
Hand::Hand(){
	n_cards = 7;
	Card* temp = new Card[n_cards];
	for (int i = 0; i < 7; i++){
		Card c;
		c.init(0,0);
		temp[i] = c;
	}
	cards = temp;	
}

/*********************************************************************
 * ** Description: Destructor for the hand class, gets rid of the list
 * ** of cards on the heap. 
 * ** Parameters: None.
 * ** Pre-Conditions: Object has been created.
 * ** Post-Conditions: Hand is destroyed, cards are taken off the heap.
 * *********************************************************************/
Hand::~Hand(){
	delete[] cards;
}

/*********************************************************************
 * ** Description: Constructor with parameters for hand. Sets the number
 * ** of cards to n, creates a list of cards on the heap.
 * ** Parameters: int
 * ** Pre-Conditions: int has been initialized.
 * ** Post-Conditions: Hand object is created with above description.
 * *********************************************************************/
Hand::Hand(int n){
	n_cards = n;
	Card* temp = new Card[n_cards];
	for (int i = 0; i < n; i++){
		Card c;
		c.init(0,0);
		temp[i] = c;
	}
	cards = temp;	
}

/*********************************************************************
 * ** Description: Assignment operator overload for hand. Copies the contents
 * ** of the old hand to the new one.
 * ** Parameters: const Hand &
 * ** Pre-Conditions: h has been declared elsewhere.
 * ** Post-Conditions: Returns this pointer, which sets the hand object
 * ** equal to the values of the old one.
 * *********************************************************************/
Hand& Hand::operator = (const Hand &h){	
	n_cards = h.n_cards;
	delete[] cards;
	cards = new Card[n_cards];
	for (int i = 0; i < h.n_cards; i++){
		cards[i]=h.cards[i];
	
	}
	return *this;
}

/*********************************************************************
 * ** Description: Copy constructor for hand. Copies the contents of the
 * ** old hand onto a new intialized one.
 * ** Parameters: Hand& old_hand
 * ** Pre-Conditions: The new hand object has not yet been initialized.
 * ** Post-Conditions: Hand object initialized with values of old one.
 * *********************************************************************/
Hand::Hand(Hand& old_hand){
	cards = new Card[old_hand.n_cards];
	for (int i =0; i < old_hand.n_cards;i++){
		cards[i] = old_hand.cards[i];
	}	
	n_cards = old_hand.n_cards;

}

/*********************************************************************
 * ** Description: Adds one card into a hand.
 * ** Parameters: Card temp
 * ** Pre-Conditions: temp has been declared elsewhere, object has been
 * ** declared elsewhere.
 * ** Post-Conditions: temp card is added to hand.
 * *********************************************************************/
void Hand::add_one_card(Card temp){
	
	Card* new_cards = new Card[n_cards+1];
	
	for (int i = 0; i < n_cards; i++){
		new_cards[i] = cards[i];
	}
	new_cards[n_cards] = temp;
	n_cards = n_cards + 1;
	delete[] cards;
	cards = new_cards;
}

/*********************************************************************
 * ** Description: Removes one card from the player's hand.
 * ** Parameters: int 
 * ** Pre-Conditions: int has been declared elsewhere, hand is intialized,
 * ** card exists at index num in cards.
 * ** Post-Conditions: Card is removed from hand at index num, returned.
 * *********************************************************************/
Card Hand::remove_card(int num){
	Card* new_cards= new Card[n_cards - 1];
	Card temp;
	int j = 0;
	for (int i = 0; i < n_cards; i++){
		if (i != num){
			new_cards[j] = cards[i];
			j++;
		}
		else{
			temp = cards[i];
		}
	}
	n_cards--;
	delete[] cards;
	cards = new_cards;
	return temp;
}

/*********************************************************************
 * ** Description: Changes one of the cards in the hand to an inputted 
 * ** card.
 * ** Parameters: int, Card
 * ** Pre-Conditions: int and Card, and the hand object, have all been
 * ** declared elsewhere.
 * ** Post-Conditions: Card at index num is replaced with new_card.
 * *********************************************************************/
void Hand::change_card(int num, Card new_card){
	cards[num] = new_card;
}

/*********************************************************************
 * ** Description:Checks to see if a certain suit is located within a 
 * ** a hand.
 * ** Parameters: int 
 * ** Pre-Conditions:int and the hand object have been declared elsewhere.
 * ** Post-Conditions: Returns true if the suit s is anywhere in the hand,
 * ** false otherwise.
 * *********************************************************************/
bool Hand::check_suit(int s){	
	for (int i = 0; i < n_cards; i++){
		if (cards[i].get_suit() == s){
		
			return true;
		}
	}
	return false;
}

/*********************************************************************
 * ** Description: Checks to see if a certain rank is located within a
 * ** hand OR if the hand has an 8 card. 
 * ** Parameters: int
 * ** Pre-Conditions: int and the hand object have been declared elsewhere.
 * ** Post-Conditions: Returns true if the conditions above are satisfied,
 * ** false otherwise.
 * *********************************************************************/
bool Hand::check_rank(int r){
	for (int i = 0; i < n_cards; i++){
		if (cards[i].get_rank() == r || cards[i].get_rank() == 7){
			return true;
		}
	}
	return false;
}

/*********************************************************************
 * ** Description: Determines if a certain hand is playable against a given
 * ** suit/rank.
 * ** Parameters: int, int
 * ** Pre-Conditions: Both ints and the hand object have been declared
 * ** elsewhere.
 * ** Post-Conditions: Returns true if the hand has at least one playable
 * ** card, false otherwise.
 * *********************************************************************/
bool Hand::can_play(int s, int r){

	if((r != 7) && (check_rank(r) || check_suit(s))){
		return true;
	}
	if (r == 7 && check_suit(s) || (check_rank(r))){
		return true;
	}else if(r == 7 && !check_suit(s)) {
		return false;
	}return false;
}

/*********************************************************************
 * ** Description: Returns the number of cards in a hand (getter)
 * ** Parameters: None.
 * ** Pre-Conditions: Hand object has been declared
 * ** Post-Conditions: The number of cards in a hand have been returned.
 * *********************************************************************/
int Hand::get_num_cards(){
	return n_cards;
}

/*********************************************************************
 * ** Description: Changes the number of cards in the hand; to be used
 * ** in other functions.
 * ** Parameters:
 * ** Pre-Conditions:
 * ** Post-Conditions:
 * *********************************************************************
void Hand::change_num_cards(int n){
	n_cards = n;
}*/

/*********************************************************************
 * ** Description: Returns the card array located within hand. 
 * ** Parameters: None.
 * ** Pre-Conditions: Object has been declared elsewhere.
 * ** Post-Conditions: The card array inside the hand is returned.
 * *********************************************************************/
Card* Hand::get_card_array(){
	return cards;
}

/*********************************************************************
 * ** Description: Formats the hand out to the screen.
 * ** Parameters: None.
 * ** Pre-Conditions: Object has been initialized.
 * ** Post-Conditions: The hand is printed to the screen.
 * *********************************************************************/
void Hand::print_hand() const{
	for (int i = 0; i < n_cards; i++){
		cout << i << ") ";
		cards[i].print_card();
		cout << endl;
	}
}


