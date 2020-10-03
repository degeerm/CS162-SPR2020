/******************************************************
 * ** Program: Deck.cpp
 * ** Author: Miya DeGeer
 * ** Date: 04/26/2020
 * ** Description: Acts as the implementation file for all
 * ** of the functions in the Deck class. Deck object
 * ** is an array of cards, as well as the number of cards
 * ** in the deck.
 * ******************************************************/



#include "Deck.h"
using namespace std;

/*********************************************************************
 * ** Description: Default constructor for the deck class. Initializes
 * ** the deck with a set of 52 cards (correct ranks/suits), then sets
 * ** n_cards to 52.
 * ** Parameters: None.
 * ** Pre-Conditions: None.
 * ** Post-Conditions: Deck object is constructed with above description.
 * *********************************************************************/
Deck::Deck(){
	Card temp;
	int i = 0;
	for (int j = 0; j < 4; j++){
		for (int k = 0; k < 13; k++){
			temp.init(j,k);
			cards[i] = temp;
			i++;	
			
		}
	}
	n_cards = 52;
}

/*********************************************************************
 * ** Description: Swaps two cards within the deck.
 * ** Parameters: int, int
 * ** Pre-Conditions: Both ints and the deck have been declared elsewhere.
 * ** Post-Conditions: The cards at the two indexes are swapped.
 * *********************************************************************/
void Deck::swap(int num1, int num2){
	Card card_temp = cards[num1];
	cards[num1] = cards[num2];
	cards[num2] = card_temp;
}

/*********************************************************************
 * ** Description: Shuffles the deck.
 * ** Parameters: None.
 * ** Pre-Conditions: Deck object has been initialized.
 * ** Post-Conditions: All of the cards within the deck have been shuffled.
 * *********************************************************************/
void Deck::shuffle(){
	srand(time(NULL));
	for (int i = 0; i < 52; i++){
		while (true){
			int r_num = rand() % 52;
			if (r_num != i){
				swap(i, r_num);
				break;
			}
		}
	}
}

/*********************************************************************
 * ** Description: Returns the number of cards left in the deck.
 * ** Parameters: None.
 * ** Pre-Conditions: Deck object has been declared elsewhere
 * ** Post-Conditions: n_cards is returned
 * *********************************************************************/
int Deck::get_cards_left(){
	return n_cards;
}

/*********************************************************************
 * ** Description: Deals one card from the cardlist.
 * ** Parameters: None.
 * ** Pre-Conditions: Deck object has been declared elsewhere.
 * ** Post-Conditions: The card at the top of the deck is returned, placed
 * ** at back of deck for safe keeping
 * *********************************************************************/
Card Deck::deal_one(){	
	Card temp = cards[0];
	
	for (int i = 1; i < 52; i++){
		cards[i-1] = cards[i];
	}

	cards[51] = temp;
	n_cards--;

	return temp;
}

/*********************************************************************
 * ** Description: Checks if there is a tie (IE, that no cards are left)
 * ** Parameters: None.
 * ** Pre-Conditions: Deck object has been declared elsewhere.
 * ** Post-Conditions: Returns true if there are zero cards left, 
 * ** false otherwise.
 * *********************************************************************/
bool Deck::check_tie(){
	if (n_cards == 0){
		return true;
	}
	return false;
}


