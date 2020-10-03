#include "check_functions.h"
#include "Game.h"
using namespace std;

/*********************************************************************
 * ** Description: Main function. Checks to make sure arguments are okay.
 * ** Creates a saved game and current game. Each run through the loop, it
 * ** runs the current game. If player wants to play a different dungeon, 
 * ** the saved game is changed. If player wants to quit, program ends. Each
 * ** time loop runs, current game is set to saved game. 
 * ** Parameters: int, char* 
 * ** Pre-Conditions: None.
 * ** Post-Conditions: Game is run until user wants to stop.
 * *********************************************************************/
int main(int argc, char *argv[]){	
	int n;
	bool debug;
	if (argc == 3){
		n = size_input_checker(string(argv[1]));
		debug = debug_input_checker(string(argv[2]));
	}else{
		cout << "Incorrect number of arguments given. Please enter both arguments again." << endl;
		n = size_input_checker("flagger");
		debug = debug_input_checker("flagger");
	}
	
	Game saved_game(n, debug);
	Game current_game (n, debug);
	string r;
	while (r != "2"){
		current_game = saved_game;
		r = current_game.main_game(debug);
		if(r == "1"){
			saved_game = Game(n, debug);
		}else if (r== "2"){
			return 0;
		}
	}
	return 0;
}
