#include "Hand.h"


using namespace std;

Hand::Hand(){
	cout << "+++DEFAULT CONSTRUCTOR CALLED+++" << endl;
	n_cards = 7;
	Card* temp = new Card[n_cards];
	cards = temp;
}


Hand::~Hand(){
	delete[] cards;
	cout << "+++DESTRUCTOR CALLED+++" << endl;
}

Hand::Hand(int n){
	cout << "+++CONSTRUCTOR WITH PARAMATERS CALLED+++" << endl;
	n_cards = n;
	Card* temp = new Card[n_cards];
	cards = temp;
}

Hand& Hand::operator = (const Hand &h){
	cout << "+++ASSIGNMENT OPERATOR CALLED+++" << endl;
	if (this != &h){
		n_cards = h.n_cards;
		delete[] cards;
		cards = new Card[n_cards];
		for (int i = 0; i < h.n_cards; i++){
			cards[i]=h.cards[i];
	
		}
	}
	return *this;
}

Hand::Hand(const Hand& old_hand){
	cout << "+++COPY CONSTRUCTOR CALLED++++" << endl;
	n_cards = old_hand.n_cards;
	cards = new Card[n_cards];
	for (int i =0; i < old_hand.n_cards;i++){
		cards[i] = old_hand.cards[i];
	}	

}

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

void Hand::change_card(int num, Card new_card){
	cards[num] = new_card;
}

bool Hand::check_suit(int s){	
	for (int i = 0; i < n_cards; i++){
		if (cards[i].get_suit() == s){
		
			return true;
		}
	}
	return false;
}

void Hand::print_hand() const{
	for (int i = 0; i < n_cards; i++){
		cout << i << ") ";
		cards[i].print_card();
		cout << endl;
	}
}


