/******************************************************
 * ** Program: PLayer.cpp
 * ** Author: Miya DeGeer
 * ** Date: 04/26/2020
 * ** Description: Acts as the implementation file for all
 * ** of the functions in the Player class. Contains a hand
 * ** object, and the name of the player/
 * ******************************************************/



#include "Player.h"

using namespace std;

/*********************************************************************
 * ** Description: Default constructor for player class. Defaults to a
 * ** default hand, and a name of "Player".
 * ** Parameters: None.
 * ** Pre-Conditions:None. 
 * ** Post-Conditions: Player object is constructed with above description.
 * *********************************************************************/
Player::Player(){
	Hand h;
	hand = h;
	name = "Player";
}

/*********************************************************************
 * ** Description: Constructor with name paramater for player class. 
 * ** Default hand, and the name of the string given in.
 * ** Parameters: string
 * ** Pre-Conditions: string has been declared elsewhere
 * ** Post-Conditions: Player object is constructed with above description.
 * *********************************************************************/
Player::Player(string new_name){
	Hand h;
	hand = h;
	name = new_name;
}

/*********************************************************************
 * ** Description: Determines if a given string could be converted into
 * ** an integer.
 * ** Parameters: string
 * ** Pre-Conditions: String has been defined elsewhere
 * ** Post-Conditions: True or false is returned, depending on if string 
 * ** is an int or not.
 * *********************************************************************/
bool Player::is_int(string num){
	if (num.length() == 0){
		return false;
	}
	for (int i = 0; i < num.length(); i++){
		if ((int)num.at(i) < 48 or (int)num.at(i) > 57){
			return false;
		}
	}
	return true;
}

/*********************************************************************
 * ** Description: Takes in a string prompt, and if it is an integer,
 * ** returns the integer version of it. (Does not work for negative
 * ** integers)
 * ** Parameters: string
 * ** Pre-Conditions: String has been defined elsewhere.
 * ** Post-Conditions: Integer version of string is returned, -1 otherwise.
 * *********************************************************************/
int Player::get_int(string prompt){
	int sum = 0;
	int len = prompt.length();
	if (is_int(prompt)){
		for (int i = len-1; i >= 0; i--){
			char current = (int)prompt.at(i) - 48;
			sum += (current * pow(10,((len-1)-i)));
		}
	}else{
		return -1;
	}
	return sum;
}

/*********************************************************************
 * ** Description: Changes one of the cards within the hand of the player.
 * ** Parameters: int, Card
 * ** Pre-Conditions: int and Card have been declared elsewhere.
 * ** Post-Conditions: The card at index num is replaced with new_card.
 * *********************************************************************/
void Player::change_card(int num, Card new_card){
	hand.change_card(num, new_card);
}

/*********************************************************************
 * ** Description: Prints the player's hand.
 * ** Parameters: None.
 * ** Pre-Conditions: Hand has at least one card in it.
 * ** Post-Conditions: The cards in the players hand are formatted and
 * ** printed to the screen.
 * *********************************************************************/
void Player::print_hand(){
	hand.print_hand();
}

/*********************************************************************
 * ** Description: Determines if a players hand is playable with
 * ** a suit and rank.
 * ** Parameters: int, int
 * ** Pre-Conditions: int s and r have been declared elsewhere,
 * ** players hand is declared.
 * ** Post-Conditions: Returns true if the hand is playable, false
 * ** otherwise.
 * *********************************************************************/
bool Player::can_play(int s, int r){
	return (hand.can_play(s, r));
}


/*********************************************************************
 * ** Description: Adds one card to the player's hand.
 * ** Parameters: Card
 * ** Pre-Conditions: Temp has been declared elsewhere
 * ** Post-Conditions: One card is added to the player's hand
 * *********************************************************************/
void Player::add_one_card(Card temp){
	hand.add_one_card(temp);
}

/*********************************************************************
 * ** Description: Removes on card from the player's hand
 * ** Parameters:  int num
 * ** Pre-Conditions: num has been declared elsewhere
 * ** Post-Conditions: Card at index num is removed from the array, this
 * ** card is returned.
 * *********************************************************************/
Card Player::remove_card(int num){
	return (hand.remove_card(num));
}

/*********************************************************************
 * ** Description: Returns the number of cards on 
 * ** Parameters: None.
 * ** Pre-Conditions: The hand being referred to has been declared
 * ** Post-Conditions: Returns the number of card in the hand
 * *********************************************************************/
int Player::get_num_cards(){
	return (hand.get_num_cards());
}


/*********************************************************************
 * ** Description: Runs through the behavior needed if the player 
 * ** puts down an eight card.
 * ** Parameters: None.
 * ** Pre-Conditions: None.
 * ** Post-Conditions: Returns an int of the players choice to be the
 * ** new suit.
 * *********************************************************************/
int Player::if_eight(){
	string suit;
	while (true){
		cout << "What do you want the new suit to be?";
		cout << " (0 for spades, 1 for hearts, 2 for diamonds, 3 for clubs.)";
		cin >> suit;
		if (suit == "1"|| suit == "2"|| suit == "3" || suit =="0"){
			return(get_int(suit));
		}
		else{
			cout << "Error: Please only enter 0-3." << endl;
		}
	}
}

/*********************************************************************
 * ** Description: Changes the player's name to whatever n is.
 * ** Parameters: string
 * ** Pre-Conditions: n has been declared elsewhere, the player has
 * ** already been constructed
 * ** Post-Conditions: The name in the player object is changed to n.
 * *********************************************************************/
void Player::change_name(string n){
	name = n;
}

/*********************************************************************
 * ** Description: Goes through the behavior needed if the computer picks
 * ** an eight card (doesnt choose suit thats currently in place)
 * ** Parameters: int
 * ** Pre-Conditions: int has been declared elsewhere
 * ** Post-Conditions: Returns the new suit of the computer's choosing.
 * *********************************************************************/
int Player::if_eight_AI(int r){
	int r_num;
	srand(time(NULL));
	while (true){
		r_num = rand() % 4;
		if (r_num != r){		
			return r_num;
		}
	}
}

/*********************************************************************
 * ** Description: Maps the rank out to a more user-friendly string.
 * ** Parameters: int
 * ** Pre-Conditions: game_rank has been declared elsewhere.
 * ** Post-Conditions: A string version of the game rank is returned.
 * *********************************************************************/
string Player::map_rank(int game_rank){
	if (game_rank >= 1 && game_rank <= 9){
		string str = to_string(game_rank + 1);
		return str;
	}
	else if (game_rank == 0){
		return "Ace";
	}
	else if (game_rank == 10){
		return "Jack";
	} 
	else if (game_rank == 11){
		return "Queen";
	}
	else if (game_rank == 12){
		return "King";
	}
}

/*********************************************************************
 * ** Description: Maps the suit to a more user-friendly string.
 * ** Parameters: int
 * ** Pre-Conditions: game_suit has been declared elsewhere.
 * ** Post-Conditions: A string version of the game suit is returned.
 * *********************************************************************/
string Player::map_suit(int game_suit){
	if (game_suit == 0){
		return "Spades";
	}else if (game_suit == 1){
		return "Hearts";
	}else if (game_suit == 2){
		return "Diamonds";
	}else if (game_suit == 3){
		return "Clubs";
	}

}

/*********************************************************************
 * ** Description: Returns the name of a player-object.
 * ** Parameters: None.
 * ** Pre-Conditions: Player object has been declared.
 * ** Post-Conditions: String (player name) is returned.
 * *********************************************************************/
string Player::get_name(){
	return (name);
}

/*********************************************************************
 * ** Description: Handles the card selection process to make sure 
 * ** picks a card they can actually play.
 * ** Parameters: int, int
 * ** Pre-Conditions: int and int have been declared elsewhere.
 * ** Post-Conditions: A card is returned once the player actually chooses
 * ** a good card. 
 * *********************************************************************/
Card Player::error_handle_input(int s, int r){
	string input;
	while (true){
		cout << "\nThis is your hand: " << endl;
		print_hand();
		cout << "Select a card to play: " << endl;
		cin >> input;
		if (is_int(input) && get_int(input) >= 0 && get_int(input) < get_num_cards()){
			if (hand.get_card_array()[get_int(input)].can_play(s,r)){  
				return (remove_card(get_int(input)));
			}else{
				cout << "\nERROR: This card doesn't match requirements.";
				cout << " Select a different one." << endl;
			}
		}else if (!is_int(input) || get_int(input) <0 || get_int(input) >= get_num_cards()){
			cout << "\nERROR: Please only input a number between ";
			cout << "0 and " << get_num_cards()-1 << ". " << endl;
		}
		cout << "The rank is: " << map_rank(r) << endl;
		cout << "The suit is: " << map_suit(s) << endl;
	}
}


/*********************************************************************
 * ** Description: Goes through the card selection process for picking 
 * ** a card from the computer.
 * ** Parameters: int, int
 * ** Pre-Conditions: Both ints have been declared elsewhere.
 * ** Post-Conditions: A card from the AI's hand is returned.
 * *********************************************************************/
Card Player::select_card_AI(int s, int r){
	for (int i =0; i < hand.get_num_cards(); i++){
		if (hand.get_card_array()[i].can_play(s,r)){	
			return (hand.remove_card(i));
		}
	}
}
