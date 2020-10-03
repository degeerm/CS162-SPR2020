/******************************************************
 * ** Program Name: Game.cpp
 * ** Author: Miya DeGeer 
 * ** Date: 05/24/2020
 * ** Description: Implementation file for the game class. 
 * ** Has various functions for carrying out Hunt the Wumpus,
 * ** including checkers/main game/shooting events/etc.
 * ******************************************************/


#include "Game.h"

using namespace std;

/*********************************************************************
 * ** Description: Default constructor for the Game class. Creates a
 * ** 4 by 4 vector of rooms, generates events, sets has_gold/debug to false,
 * ** an number of arrows to 3. 
 * ** Parameters: None.
 * ** Pre-Conditions:  None.
 * ** Post-Conditions: Game object is created.
 * *********************************************************************/
Game::Game(){
	vector<Room> v(4);	
	vector<vector<Room> > v2(4, v);	
	rooms = v2;
	generate_events();
	has_gold = false;
	debug = false;
	num_arrows = 3;
}

/*********************************************************************
 * ** Description: Default constructor for the Game class. Creates a
 * ** n by n vector of rooms, generates events, sets has_gold to false, 
 * ** debug to d, and number of arrows to 3. 
 * ** Parameters: None.
 * ** Pre-Conditions:  None.
 * ** Post-Conditions: Game object is created.
 * *********************************************************************/
Game::Game(int n,bool d){	
	vector<Room> v(n);	
	vector<vector<Room> > v2(n, v);	
	rooms = v2;
	generate_events();
	has_gold = false;
	debug = d;
	num_arrows = 3;
}

/*********************************************************************
 * ** Description: Randomly generates events for the dungeon. Creates 2
 * ** pit events, 2 bat events, a gold event, a wumpus event, and places
 * ** the adventurer. 
 * ** Parameters: None.
 * ** Pre-Conditions:  Game object has been declared elsewhere.
 * ** Post-Conditions: Above events are added to dungeon (rooms vector)
 * *********************************************************************/
void Game::generate_events(){
	srand(time(NULL));
	int rnum1, rnum2;
	rnum1 = rand() % rooms.size();
	rnum2 = rand() % rooms.size();
	rooms[rnum1][rnum2].set_starting_room(); 
	add_events(2,2);	
	add_events(2,3);
	add_events(1, 0);
	add_events(1, 1);
}

/*********************************************************************
 * ** Description: Adds in the specified number of a certain event, which
 * ** is also specified by user.
 * ** Parameters: int, int
 * ** Pre-Conditions:  Game object + int objects have been declared elsewhere.
 * ** Post-Conditions: n events of type e are added to rooms vector.
 * *********************************************************************/
void Game::add_events(int n, int e){
	int r_num1, r_num2;
	int i  = 0;
	srand(time(NULL));	
	while (i < n){
		r_num1 = rand() % rooms.size();
		r_num2 = rand() % rooms.size();
		if (rooms[r_num1][r_num2].get_eptr() == NULL && !rooms[r_num1][r_num2].check_adventurer()){
			rooms[r_num1][r_num2].set_event(e);
			i++;
		}
	}

}

/*********************************************************************
 * ** Description: Prints out the game (originally had two seperate functions
 * ** hence the name)
 * ** Parameters: bool
 * ** Pre-Conditions: bool & game object have been declared elsewhere 
 * ** Post-Conditions: Game is printed to screen (with all events if d is true,
 * ** only with adventurer if d is false)
 * *********************************************************************/
void Game::print_game_debug(bool d){
	print_header();
	for (int i = 0; i < rooms.size(); i++){
		cout << "|";
		for (int j = 0; j < rooms[i].size(); j++){	
			if (rooms[i][j].check_adventurer()){
				cout << " * ";
			}
			else if (rooms[i][j].get_eptr() == NULL || !d){
				cout << "   ";
			}
			else{
		 		cout << " ";
				(rooms[i][j].get_eptr()) -> print_event();
				cout << " ";
			}
		       	cout << "|";
		}
		cout << endl;
	}	
	print_header();
}

/*********************************************************************
 * ** Description: Prints out a decorative piece for board layout 
 * ** Parameters: None.
 * ** Pre-Conditions: Game object has been declared elsewhere
 * ** Post-Conditions: Appropriate sized header printed out based on
 * ** rooms.size()
 * *********************************************************************/
void Game::print_header(){
	for (int i = 0; i < rooms.size(); i++){
		cout << "+ = ";
	}
	cout << "+\n";
}

/*********************************************************************
 * ** Description: Finds the y-coordinate of the adventurer. 
 * ** Parameters: None.
 * ** Pre-Conditions: Game object has been declared elsewhere, adventurer
 * ** is somewhere in vector
 * ** Post-Conditions: Coordinate is returned as int.
 * *********************************************************************/
int Game::find_ad_y(){
	for (int i = 0; i < rooms.size(); i++){
		for (int j =0; j < rooms.size();j++){
			if (rooms[i][j].check_adventurer()){
				return j;
			}
		}

	}
}

/*********************************************************************
 * ** Description: Finds the x-coordinate of the adventurer. 
 * ** Parameters: None.
 * ** Pre-Conditions: Game object has been declared elsewhere, adventurer
 * ** is somewhere in vector
 * ** Post-Conditions: Coordinate is returned as int.
 * *********************************************************************/
int Game::find_ad_x(){
	for (int i = 0; i < rooms.size(); i++){
		for (int j =0; j < rooms.size();j++){
			if (rooms[i][j].check_adventurer()){
				return i;
			}
		}

	}
}

/*********************************************************************
 * ** Description: Prints out ending options and accepts user input
 * ** until user gives correct input (play with same, play different,
 * ** end game)
 * ** Parameters: None.
 * ** Pre-Conditions:  Game object has been declared.
 * ** Post-Conditions: "0", "1", or "2" is returned.
 * *********************************************************************/
string Game::ending_options(){
	string response;
	while (true){
		cout << "Would you like to: Play with same specifications (enter 0)";
		cout << ", play with a new dungeon (enter 1), or quit (enter 2)?" << endl;
		cin >> response;
		cin.ignore();
		if (response == "0" || response == "1" || response == "2"){
			return response;
		}else{
			cout << "Error: That's not one of the options. Please try again." << endl;
		}
	}

}

/*********************************************************************
 * ** Description: Does the percept for each surrounding event around the
 * ** adventurer (up, down, left, right)
 * ** Parameters: None.
 * ** Pre-Conditions:  Game object has been declared elsewhere.
 * ** Post-Conditions: Percept messages, if applicable, are printed to
 * ** the screen.
 * *********************************************************************/
void Game::do_percept(){
	if (find_ad_y()-1 >= 0 && rooms[find_ad_x()][find_ad_y()-1].get_eptr()!= NULL){
		rooms[find_ad_x()][find_ad_y()-1].get_eptr() -> percept();
	}
	if (find_ad_x() +1 < rooms.size() && rooms[find_ad_x()+1][find_ad_y()].get_eptr() != NULL) {
		rooms[find_ad_x()+1][find_ad_y()].get_eptr() -> percept();
	}
	if (find_ad_y() + 1 < rooms.size()&&rooms[find_ad_x()][find_ad_y()+1].get_eptr() !=NULL){
		rooms[find_ad_x()][find_ad_y()+1].get_eptr() -> percept();
	}
	if (find_ad_x() - 1 >= 0 && rooms[find_ad_x()-1][find_ad_y()].get_eptr() != NULL){
		rooms[find_ad_x()-1][find_ad_y()].get_eptr() -> percept();
	}
}

/*********************************************************************
 * ** Description: Main game for Hunt the Wumpus. Runs through doing the event,
 * ** then percepts, prints out information, moves/shoots, checks for win
 * ** conditions. If satisfied/if player dies, play again options printed.
 * ** Parameters: bool
 * ** Pre-Conditions: Game and bool have been declared elsewhere
 * ** Post-Conditions: Returns the string of whether or not the player
 * ** wants to play again, to be used in main
 * *********************************************************************/
string Game::main_game(bool d){
	string response;
	debug =  d;
	while(true){
		if (!do_event()){
			return (ending_options());
		}
		print_game_debug(debug);		
		do_percept();
		cout << "You have " << num_arrows << " arrows left." << endl;
		move_shoot();	
		if (rooms[find_ad_x()][find_ad_y()].check_starting() && has_gold){
			cout << "You've gotten the gold and safely escaped! You win!" << endl;
			return (ending_options());
		}
	}
}

/*********************************************************************
 * ** Description: Acts as the overarching move function. Checks if response
 * ** is equal to any move paramters. If so, tries to move, if not, returns
 * ** false.
 * ** Parameters: string
 * ** Pre-Conditions: Both string and Game object have been declared elsewhere
 * ** Post-Conditions: Returns true if player moved, false otherwise.
 * *********************************************************************/
bool Game::move_overview(string response){
	if (response=="w"|| response == "W"){
		if (move_player(-1,0)){
			return true;
		}
	}else if (response == "A" || response == "a"){
		if (move_player(0,-1)){
			return true;
		}
	}else if (response == "S" || response == "s"){
		if (move_player(1,0)){
			return true;
		}
	}else if (response == "D" || response == "d"){
		if(move_player(0,1)){
			return true;
		}
	}	
	return false;
}

/*********************************************************************
 * ** Description: Overview for the move/shoot function. Takes in a response,
 * ** then checks that for condition and fulfills moving/shooting.
 * ** Parameters: None.
 * ** Pre-Conditions:  Game object has been declared elsewhere.
 * ** Post-Conditions: The player is moved OR the player shoots (if they still
 * ** have arrows)
 * *********************************************************************/
void Game::move_shoot(){
	string response;
	while (true){	
		cout << "Would you like to move(WASD) or shoot (space,then WASD)?" << endl;
		getline(cin,response);	
		if(move_overview(response)){
			return;
		}else if (to_lower(response) == " w" || to_lower(response) == " a" || to_lower(response) == " s"
		|| to_lower(response) == " d" ){
			if (num_arrows != 0 && shoot_arrow(to_lower(response))){
				return;
			}else{
				cout << "You cannot shoot, you have no arrows left." << endl;
				continue;
			}
		}
		cout << "Error: Your selection is not possible. Please try again." << endl;
	}

}

/*********************************************************************
 * ** Description: Moves the adventurer to the given adjustments, passed
 * ** in by the function
 * ** Parameters: int, int
 * ** Pre-Conditions: Both ints and Game have been declared
 * ** Post-Conditions: Returns true if player was moved, false otherwise
 * *********************************************************************/
bool Game::move_player(int x, int y){
	if (find_ad_x() + x < rooms.size() && find_ad_x()+x >= 0 &&
	(find_ad_y() + y < rooms.size() && find_ad_y() + y >= 0)){
		move_adventurer(find_ad_x() + x,find_ad_y() + y);
		return true;	
	}
		return false;
}

/*********************************************************************
 * ** Description: Moves the player to the indexes given in (removes them
 * ** from current position as well)
 * ** Parameters: int, int
 * ** Pre-Conditions: Both ints have been declared, as is Game
 * ** Post-Conditions: adventurer is moved to x, y
 * *********************************************************************/
void Game::move_adventurer(int x, int y){
	rooms[find_ad_x()][find_ad_y()].move_adventurer(false);
	rooms[x][y].move_adventurer(true);
}

/*********************************************************************
 * ** Description: Shoots an arrow a given direction(d right, a left, w up,
 * ** s down)
 * ** Parameters: string
 * ** Pre-Conditions: string and Game have been decalerd
 * ** Post-Conditions: Returns true if response matches one of the given 
 * ** ones, false otherwise
 * *********************************************************************/
bool Game::shoot_arrow(string r){
	if (r == " w"){
		shoot_up();
		return true;	
	}else if (r == " a"){
		shoot_left();
		return true;
	}else if (r == " s"){
		shoot_down();
		return true;
	}else if (r == " d"){
		shoot_right();
		return true;
	}
	return false;
}

/*********************************************************************
 * ** Description: Shoots an arrow up, checks for wall conditions, startles
 * ** the wumpus, or flies three spaces without hitting anything.
 * ** Parameters: none.
 * ** Pre-Conditions: Game object has been declared, player has at least 1
 * ** arrow. 
 * ** Post-Conditions: Arrow is shot.
 * *********************************************************************/
void Game::shoot_up(){
	bool wumpus_moved = arrow_event(find_ad_x(), find_ad_y(), "u");
	num_arrows--;
	for (int j = find_ad_x() -1; j >= find_ad_x() -3; j--){
		if (j < 0){
			cout << "You've hit a wall!" << endl;
			return;
		}else if (rooms[j][find_ad_y()].get_eptr() != NULL &&
		rooms[j][find_ad_y()].get_eptr() -> get_event_num() == 0){
			cout << "Congratulations! You've hit and killed the wumpus!" << endl;
			rooms[j][find_ad_y()].set_event(4);
			return;
		}
		if (!wumpus_moved){
			wumpus_moved = arrow_event(j,find_ad_y(), "u");
		}
	}	
	cout << "Your arrow flew three spaces without hitting anything." << endl;
	return;
}

/*********************************************************************
 * ** Description: Shoots an arrow down, checks for wall conditions, startles
 * ** the wumpus, or flies three spaces without hitting anything.
 * ** Parameters: none.
 * ** Pre-Conditions: Game object has been declared, player has at least 1
 * ** arrow. 
 * ** Post-Conditions: Arrow is shot.
 * *********************************************************************/
void Game::shoot_down(){
	bool wumpus_moved = arrow_event(find_ad_x(), find_ad_y(),"d");
	num_arrows--;	
	for (int j = find_ad_x() + 1; j <= find_ad_x() +3; j++){
		if (j >= rooms.size()){
			cout << "You've hit a wall!" << endl;
			return;
		}else if (rooms[j][find_ad_y()].get_eptr() != NULL &&
		rooms[j][find_ad_y()].get_eptr() -> get_event_num() == 0){
			cout << "congratulations! you've hit and killed the wumpus!" << endl;
			rooms[j][find_ad_y()].set_event(4);
			return;
		}
		if (!wumpus_moved){
			wumpus_moved = arrow_event(j,find_ad_y(), "d");
		}
	}
	cout << "Your arrow flew three spaces without hitting anything." << endl;
	return;
}

/*********************************************************************
 * ** Description: Shoots an arrow left, checks for wall conditions, startles
 * ** the wumpus, or flies three spaces without hitting anything.
 * ** Parameters: none.
 * ** Pre-Conditions: Game object has been declared, player has at least 1
 * ** arrow. 
 * ** Post-Conditions: Arrow is shot.
 * *********************************************************************/
void Game::shoot_left(){
	bool wumpus_moved =
	arrow_event(find_ad_x(), find_ad_y(),"l"); 
	num_arrows--;
	for (int j = find_ad_y() -1; j >= find_ad_y() -3; j--){
		if (j < 0){
			cout << "You've hit a wall!" << endl;
			return;
		}else if (rooms[find_ad_x()][j].get_eptr() != NULL &&
		rooms[find_ad_x()][j].get_eptr() -> get_event_num() == 0){
			cout << "Congratulations! You've hit and killed the wumpus!" << endl;
			rooms[find_ad_x()][j].set_event(4);
			return;
		}
		if (!wumpus_moved){
			wumpus_moved = arrow_event(find_ad_x(),j, "l");
		}
	}	
	cout << "Your arrow flew three spaces without hitting anything." << endl;
	return;
}

/*********************************************************************
 * ** Description: Shoots an arrow right, checks for wall conditions, startles
 * ** the wumpus, or flies three spaces without hitting anything.
 * ** Parameters: none.
 * ** Pre-Conditions: Game object has been declared, player has at least 1
 * ** arrow. 
 * ** Post-Conditions: Arrow is shot.
 * *********************************************************************/
void Game::shoot_right(){
	bool wumpus_moved = wumpus_moved = arrow_event(find_ad_x(), find_ad_y(),"r");
	num_arrows--;	
	for (int j = find_ad_y() + 1; j <= find_ad_y() +3; j++){
		if (j >= rooms.size()){
			cout << "You've hit a wall!" << endl;
			return;
		}else if (rooms[find_ad_x()][j].get_eptr() != NULL &&
		rooms[find_ad_x()][j].get_eptr() -> get_event_num() == 0){
			cout << "Congratulations! You've hit and killed the wumpus!" << endl;
			rooms[find_ad_x()][j].set_event(4);
			return;
		}
		if (!wumpus_moved){
			wumpus_moved = arrow_event(find_ad_x(), j, "r");	
		}
		
	}	
	cout << "Your arrow flew three spaces without hitting anything." << endl;
	return;
}

/*********************************************************************
 * ** Description: Goes through to determine if startling the wumpus
 * ** is a possibility, based on coordinates/where arrow is pointing. 
 * ** Parameters: int, int, string
 * ** Pre-Conditions: All variables + Game have been declared elsewhere.
 * ** Post-Conditions: returns true if wumpus was startled, false otherwise.
 * *********************************************************************/
bool Game::arrow_event(int x, int y, string d){
	bool b = false;
	if (y -1 >=0 && rooms[x][y -1].get_eptr() != NULL
	&& rooms[x][y -1].get_eptr() -> get_event_num() == 0 && d != "l"){
		b = (move_wumpus(x, y-1));
	}else if (x -1 >= 0 && rooms[x-1][y].get_eptr() != NULL
	&& rooms[x-1][y].get_eptr() -> get_event_num() == 0 && d != "u"){
		b = (move_wumpus(x-1, y));
	}else if (x + 1 <rooms.size() && rooms[x+1][y].get_eptr() != NULL
	&& rooms[x+1][y].get_eptr() -> get_event_num() == 0 && d != "d"){
		b = (move_wumpus(x+1, y));
	}else if (y +1 < rooms.size() && rooms[x][y+1].get_eptr() != NULL
	&& rooms[x][y+1].get_eptr() -> get_event_num() == 0 && d != "r"){
		b = (move_wumpus(x, y+1));
	}
	return b;
}

/*********************************************************************
 * ** Description: 75 percent chance wumpus will get startled. If so,
 * ** chooses a random empty index to move it to and return true. 
 * ** otherwise, return false.
 * ** Parameters: int, int
 * ** Pre-Conditions: Both variables + game have been declared elsewhere.
 * ** Post-Conditions: If wumpus is startled, successfully moves it and returns
 * ** true. Returns false otherwise.
 * *********************************************************************/
bool Game::move_wumpus(int x, int y){
	srand(time(NULL));
	int rnum = rand() % 4;
	if (rnum != 0){
		while (true){
			int rnum1 = rand() % rooms.size();
			int rnum2 = rand() % rooms.size();
			if (rooms[rnum1][rnum2].get_eptr() == NULL && !rooms[rnum1][rnum2].check_adventurer()){
				cout << "You've startled the wumpus! It is now moving!" << endl;
				rooms[x][y].set_event(4);
				rooms[rnum1][rnum2].set_event(0);
				return true;
			}
		}
	}else{
		return false;
	}
}

/*********************************************************************
 * ** Description: Main function for carrying out events. Passes in an integer,
 * ** two integer references, and a bool reference to encounter. If x/y is -1,
 * ** player has died (return false). If g is altered, player now has gold,
 * ** returns true. If x/y is not equal to original, bat has moved them. 
 * ** Restart loop.
 * ** Parameters: None.
 * ** Pre-Conditions: Game object has been declared elsewhere.
 * ** Post-Conditions: Above description determines whether function returns
 * ** true/false.
 * *********************************************************************/
bool Game::do_event(){	
	int x, y;
	bool g;
	while (true){
		x= find_ad_x();
		y = find_ad_y();
		g = has_gold;
		if (rooms[find_ad_x()][find_ad_y()].get_eptr() != NULL){
			rooms[find_ad_x()][find_ad_y()].get_eptr() -> encounter(x, y, g, rooms.size());
		}else
			return true;
		if(x == -1){
			print_game_debug(debug);
			return false;
		}else if (g != has_gold){
			has_gold = g;
			rooms[find_ad_x()][find_ad_y()].set_event(4);
			return true;
		}else{
			if (rooms[x][y].get_eptr() == NULL || rooms[x][y].get_eptr()->get_event_num() != 2){
				cout << "You've entered a bat room and been sent to a random room!" << endl;
				move_adventurer(x,y);
			}
		}
	}
}
