/******************************************************
 * ** Program: Game.cpp
 * ** Author: Miya DeGeer
 * ** Date: 04/26/2020
 * ** Description: Acts as the implementation file for all
 * ** of the functions in the Game class. Game object
 * ** is a deck, a set of 2 players, a top card, and game
 * ** rank/game suit for ease of use.
 * ******************************************************/



#include "Game.h"

using namespace std;

/*********************************************************************
 * ** Description: Default constructor for the Game class; initializes
 * ** all of the variables, and sets up the deck. 
 * ** Parameters:  None.
 * ** Pre-Conditions: None.
 * ** Post-Conditions: A Game object is constructed.
 * *********************************************************************/
Game::Game(){
	cards = Deck();
	cards.shuffle();
	players[0] = Player("Player");
	players[1] = Player("The Computer");
	Card temp = cards.deal_one();
	top_card=temp;
	game_suit = top_card.get_suit();
	game_rank = top_card.get_rank();	
}

/*********************************************************************
 * ** Description: Introduces the game to the player, and takes in a name
 * ** input to personalize it a bit.
 * ** Parameters: None.
 * ** Pre-Conditions: Game object has been initialized.
 * ** Post-Conditions: introduction printed, player name changed if its
 * ** valid.
 * *********************************************************************/
void Game::player_intro(){
	cout << "Welcome to crazy eights!" << endl;
	cout << "What would you like your name to be?" << endl;
	string input;
	cin >> input;
	if (input != ""){
		players[0].change_name(input);
	}
}

/*********************************************************************
 * ** Description: Initializes the two players hands at the beginning of
 * ** the game (gives them 4 cards off of the deck)
 * ** Parameters: None.
 * ** Pre-Conditions: Game object is initialized (also players).
 * ** Post-Conditions: Players hands now have 7 cards off of the deck.
 * *********************************************************************/
void Game::initialize_hands(){
	for (int i = 0; i < 7; i++){	
		Card temp;
		temp = cards.deal_one();
		players[0].change_card(i, temp);
	}
	for (int i =0; i < 7; i++){
		
		Card temp;
		temp = cards.deal_one();
		players[1].change_card(i, temp);
	}
}

/*********************************************************************
 * ** Description: Serves as the overarching template for the players 
 * ** turn.
 * ** Parameters: none.
 * ** Pre-Conditions: Game object is initialized (also players)
 * ** Post-Conditions: The player turn is fulfilled; cards drawn from deck
 * ** if needed, card from players hand placed on top.
 * *********************************************************************/
bool Game::player_turn(){
	
	cout << "\n-----It's now " << players[0].get_name() << "'s turn!-----" << endl;

		
	if (draw_while(game_suit, game_rank, 0)){
		cout << "This is the top-card info:" << endl;
		print_game_info();
		Card temp = players[0].error_handle_input(game_suit, game_rank);
		top_card = temp;
	
		change_game_values(0);	
	}
	if (overarching_win_condition()){
		return true;
	}
	return false;
}

/*********************************************************************
 * ** Description: Prints the current game info.
 * ** Parameters:  None.
 * ** Pre-Conditions: game object has been initialized.
 * ** Post-Conditions: Prints out the top card, game rank, and the suit 
 * ** (in case of 8 condition where suit is difference)
 * *********************************************************************/
void Game::print_game_info(){
	cout << "\n++++TOP CARD:++++\n+";
	top_card.print_card();
	cout << "\n+GAME RANK: " << players[0].map_rank(game_rank) << "." << endl;
	cout << "\n+GAME SUIT: " << players[0].map_suit(game_suit) << "." << endl;
}

/*********************************************************************
 * ** Description: Changes the games values to a generated suit, if 
 * ** necessary. Otherwise just defaults to top_cad.
 * ** Parameters: int p (the player)
 * ** Pre-Conditions: P has been intiailized, game object is constructed
 * ** Post-Conditions: Game_Suit and Game_rank are updated.
 * *********************************************************************/
void Game::change_game_values(int p){
	if (top_card.get_rank() == 7){
		if (p == 0){
			game_suit = players[p].if_eight();
		}else{
			cout << "\nComputer is changing suit to: ";
			game_suit = players[p].if_eight_AI(game_suit);
			cout <<  players[1].map_suit(game_suit) << "." << endl;
		}
		game_rank = 7;
	}else{
		game_suit = top_card.get_suit();
		game_rank = top_card.get_rank();
	}
}

/*********************************************************************
 * ** Description: Tests all of the possible ending conditions.
 * ** Parameters: None.
 * ** Pre-Conditions: Game object has been initialized.
 * ** Post-Conditions: Win condition printed, returns true if someone
 * ** won, false otherwise.
 * *********************************************************************/
bool Game::overarching_win_condition(){
	if (players[0].get_num_cards() == 0){
		cout << "Congrats! " << players[0].get_name() << " wins the game!" << endl;
		return true;
	}else if (players[1].get_num_cards() == 0){
		cout << "The computer has played all their cards and won!" << endl;
		return true;
	}if (cards.get_cards_left() <= 0){
		tie_win_condition();
	       return true;	
	}
	return false;
}

/*********************************************************************
 * ** Description: Function that tests for a tie/determines who wins.
 * ** Parameters:  None.
 * ** Pre-Conditions: Game object is initialized
 * ** Post-Conditions: Prints the win condition if theres a tie.
 * *********************************************************************/
void Game::tie_win_condition(){
	cout << "The cards have run out! Calculating the winner..." << endl;
	cout << players[0].get_name() << "'s cards left: " << players[0].get_num_cards();
	cout << "\nThe computer's cards left: " << players[1].get_num_cards() << endl;
	if (players[0].get_num_cards() == players[1].get_num_cards()){
		cout << "It's a tie! No one wins!"<< endl;
	}else if (players[0].get_num_cards() < players[1].get_num_cards()){
		cout << players[0].get_name() << " wins! Congratulations!" << endl;
	}else if (players[1].get_num_cards() < players[0].get_num_cards()){
		cout << "The computer wins!" << endl;
	}
}

/*********************************************************************
 * ** Description: Acts as the overarching function for the computer's
 * ** turn.
 * ** Parameters:  None.
 * ** Pre-Conditions: Game object has been initialized.
 * ** Post-Conditions: Computer turn is carried out (card drawn if needed),
 * ** card placed, etc.
 * *********************************************************************/
bool Game::comp_turn(){
	cout << "\n----It is now the computer's turn!----" << endl;	

	if(draw_while(game_suit, game_rank, 1)){
		Card temp = players[1].select_card_AI(game_suit, game_rank); 
		cout << "\nComputer placed this card: " << endl;
		top_card = temp;
		top_card.print_card();	
		change_game_values(1);
	}
	if (overarching_win_condition()){
		return true;
	}
	return false;

}

/*********************************************************************
 * ** Description: Draws one card from the deck, for the player.
 * ** Parameters: None.
 * ** Pre-Conditions: Game object has been initialized.
 * ** Post-Conditions: One card is drawn from the deck and dealt to
 * ** the player.
 * *********************************************************************/
void Game::draw_one_player(){
	
	Card temp;
	cout << "\nYou don't have a card you can play! Drawing one now."<< endl;
	cout << "\nYou drew: " << endl;	
	temp = cards.deal_one();
	players[0].add_one_card(temp);
	temp.print_card();

}

/*********************************************************************
 * ** Description: Draws one from the deck, for the computer.
 * ** Parameters:  None.
 * ** Pre-Conditions: Game object has been initialized.
 * ** Post-Conditions: One card is drawn from the deck and dealt to the 
 * ** player.
 * *********************************************************************/
void Game::draw_one_AI(){
	
	Card temp;
	cout << "\nComputer is drawing a card..." << endl;	
	temp = cards.deal_one();
	players[1].add_one_card(temp);
}

/*********************************************************************
 * ** Description: Continues to draw for while the computer/player does
 * ** not have a playable card.
 * ** Parameters:  int, int, int
 * ** Pre-Conditions: All variables/game object have been declared
 * ** elsewhere. 
 * ** Post-Conditions: Player/Computer gets cards (gets messages if player)
 * ** until they get a playable card, returns (false) if game needs to go
 * ** to tie condition, true otherwise.
 * *********************************************************************/
bool Game::draw_while(int s, int r, int p){
	if (players[p].can_play(s,r)){
		return true;
	}
	
	if (cards.get_cards_left() <= 0){
		return false;
	}
	if (p == 0){
		cout << "\n+Your hand:\n" << endl;
		players[0].print_hand();
	}
	while(true){
		if (cards.get_cards_left() <= 0){
			return false;
		}
		if (!players[p].can_play(s, r)){
			if (p !=1){
				draw_one_player();				
			}else{
				draw_one_AI();
			}
		}else{
			return true;
		}
	}
}

/*********************************************************************
 * ** Description: Acts as the main framework for the game.
 * ** Parameters:  None.
 * ** Pre-Conditions: game object has been initialized elsewhere.
 * ** Post-Conditions: Player is introduced and hands are intitialized. 
 * ** cycles through player/computer turns until someone wins, then prompts
 * ** for a play again. Returns false if they dont wanna play again,
 * ** true otherwise.
 * *********************************************************************/
bool Game::game_main(){
	player_intro();
	initialize_hands();

	while (true){
		if (player_turn()){
			break;
		}

		if (comp_turn()){
			break;
		}
	}
	string response;
	cout << "Would you like to play again? (enter 0 for no.)" << endl;
	cin >> response;
	if (response == "0"){
		return false;
	}
	return true;
}


