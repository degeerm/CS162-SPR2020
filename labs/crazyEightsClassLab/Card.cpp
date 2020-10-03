#include "Card.h"

using namespace std;

Card::Card(){
	init(0,0);
}

void Card::init(int a, int b){
	suit = a;
	rank = b;
}

int Card::get_rank(){	
	return rank;
}

int Card::get_suit(){
	return suit;
}

Card::~Card(){
	cout << "CARD DESTRUCTOR CALLED ++++++" << endl;
}



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

void Card::print_card(){
	cout << map_rank() << " of " << map_suit();
	cout << endl;
}
