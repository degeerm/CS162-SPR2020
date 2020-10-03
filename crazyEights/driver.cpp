/******************************************************
 * ** Program: driver.cpp 
 * ** Author: Miya DeGeer
 * ** Date: 04/26/2020
 * ** Description: Acts as the main function for calling
 * ** the game object. Keeps cycling through a game of
 * ** crazy-eights until the user wants to stop.
 * ******************************************************/



#include "Game.h"
using namespace std;

/*The main function simply calls the game function. It
/ cycles through the game by creating a game object, and then
/ using the return value of game_main() (which returns whether or
/ not user wants to continue), and then breaks once user wants
/ to stop. Returns 0 upon succesful completion of program.*/
int main(){
	while (true){

		Game g;
		if (!g.game_main()){
			break;
		}
	}
	return 0;
}
