/*****************************************************
** Program Name: Zoo.cpp 
** Author: Miya DeGeer
** Date: 05/10/2020
** Description: Implementation file for Zoo class. Has
** functions needed to execute a zoo_tycoon game. Prints
** info about zoo to user, and asks them to execute choices
** until they go bankrupt OR they quit. Has bank, base_cost
** (for food), months_passed, and Arrays of Tigers, Bears,
** and SeaLions.
** Input: int, Tiger, SeaLion, Bear, Array, string
** Output: int, bool, string
******************************************************/
#include "Zoo.h"

using namespace std;
/*********************************************************************
 * ** Description:Default constructor for the zoo class. Initalizes
 * ** bank to 100,000, base cost to 80, and everything else to empty/0. 
 * ** Parameters: None.
 * ** Pre-Conditions: None.
 * ** Post-Conditions: Zoo object is created with above description.
 * *********************************************************************/
Zoo::Zoo(){
	bank = 100000;
	base_cost = 80;
	months_passed = 0;
	food_type  = 0;
	Array<Tiger> t_new (0);
	t = t_new;
	Array<Bear> b_new(0);
	b = b_new;
	Array<SeaLion> s_new (0);
	s = s_new;
}

/*********************************************************************
 * ** Description: Determines if a given string could be converted into
 * ** an integer.
 * ** Parameters: string
 * ** Pre-Conditions: String has been defined elsewhere
 * ** Post-Conditions: True or false is returned, depending on if string 
 * ** is an int or not.
 * *********************************************************************/
bool Zoo::is_int(string num){
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
int Zoo::get_int(string prompt){
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
 * ** Description: Framework for the special event functionality. Randomly
 * ** chooses/executes no event/baby event/sick event/boom event. 
 * ** Parameters:  None.
 * ** Pre-Conditions: Zoo object has been declared.
 * ** Post-Conditions: Special event executed.
 * *********************************************************************/
bool Zoo::spec_event(){
	srand(time(NULL));
	int r_num = calc_prob();
	if ((t.return_size() == 0 && b.return_size() == 0 && s.return_size() == 0)
	|| (r_num == 7 || r_num ==8)){
		cout << "\nNothing special happened this month." << endl;
	}else if (r_num == 3 || r_num == 4){
		bank+= boom_event();
	}else if (r_num == 5 || r_num == 6){
		baby_event();
	}else if (r_num == 1|| r_num == 2 || r_num ==9 || r_num == 10){
		int n = sick_event();
		if (n != -1){
			bank-= n;
		}
	}
}

/*********************************************************************
 * ** Description: Determines if the user is bankrupt. if so, message
 * ** printed to screen. 
 * ** Parameters: none.
 * ** Pre-Conditions: Zoo object is intialized.
 * ** Post-Conditions: If bank is in the negatives/zero, returns true and
 * ** prints message. Otherwise, return false.
 * *********************************************************************/
bool Zoo::bankruptcy_check(){
	if (bank <= 0){
		cout << "Sorry, you have run out of money! You are now bankrupt. Game over!" << endl;
		return true;
	}
	return false;
}

/*********************************************************************
 * ** Description: Calculates the probability of events based on food type
 * ** for extra credit option. Randomly generates a number between 1 and 8,
 * ** 2 and 8, and 1 and 10 depending on food quality (norm, lux, cheap) 
 * ** Parameters: None.
 * ** Pre-Conditions: Zoo object has been declared.
 * ** Post-Conditions: Returns the random number based on probability.
 * *********************************************************************/
int Zoo::calc_prob(){
	srand(time(NULL));
	int r_num;
	if (food_type == 0){
		r_num =  rand() % 8 + 1;
	}
	else if(food_type == 1){
		r_num = rand() % 8 + 2;
	}else if(food_type == 2){
		r_num=rand() % 10 + 1;
	}
	return r_num;
}

/*********************************************************************
 * ** Description: Framework for the boom event. If the user has sealions,
 * ** determines a random bonus between 150 and 400 per sealion. Adds that
 * ** to bonus, returns that bonus. 
 * ** Parameters: None.
 * ** Pre-Conditions: Zoo object has been declared.
 * ** Post-Conditions: Appropriate bonus returned, if applicable, as int.
 * *********************************************************************/
int Zoo::boom_event(){
	cout << "Its an especially busy day at the zoo today! Seems like people are excited to see the sea lions." << endl;
	int bonus = 0;
	srand(time(NULL));
	int r_num;
	for (int i =0; i < s.return_size(); i++){
		r_num = rand() % 250 + 150;
		bonus+= r_num;
	}
	if (bonus != 0){
		cout << "You got an extra " << bonus << " dollars from your sea lions!" << endl;
	}else{
		cout << "You didn't have any sea lions, no extra revenue." << endl;
	}
	return bonus;
}

/*********************************************************************
 * ** Description: Overarching baby event function. Randomly selects an
 * ** animal type, then randomly selects an animal within that type's
 * ** Array object. That animal, if adult, has a child. 
 * ** Parameters: None.
 * ** Pre-Conditions: Zoo object has been declared elsewhere
 * ** Post-Conditions: Baby animal added to appropriate group/message printed
 * ** but if there are no adults, prints message to screen.
 * *********************************************************************/
void Zoo::baby_event(){
	srand(time(NULL));
	while (true){
		int r_num = rand() % 3;
		if (r_num == 0 && t.count_adults() != 0){	
			t.baby_event(base_cost);	
			cout << "One of your tigers gave birth! You now have " << t.count_babies()<< " baby tigers total!" << endl;
			return;
		}else if(r_num == 1 && s.count_adults() != 0){	
			s.baby_event(base_cost);
			cout << "One of your sea lions gave birth! You now have " << s.count_babies()<< " baby sealions total!" << endl;
			return;
		}else if(r_num == 2 && b.count_adults() != 0){
			b.baby_event(base_cost);
			cout << "One of your bears gave birth! You now have " << b.count_babies()<< " baby bears total!" << endl;
			return;
		}if (t.count_adults() == 0 && s.count_adults() == 0 && b.count_adults() == 0){
			cout << "You would have had a baby, but you don't have any adults!" << endl;
			return;
		}
	}
}

/*********************************************************************
 * ** Description: Overall framework for the sick event. Randomly selects
 * ** an animal type, and then an animal within that type, to get sick. 
 * ** If payable, removed from bank; else, animal dies.
 * ** Parameters: None.
 * ** Pre-Conditions: Zoo object has been declared elsewhere.
 * ** Post-Conditions: Animal get sick; pays if possible, else, animal is
 * ** removed.
 * *********************************************************************/
int Zoo::sick_event(){
	srand(time(NULL));
	int n, r_num;
	int minus = 0;
	while (true){
		r_num = rand() % 3;
		if (r_num == 0 && t.return_size() != 0){
			n = t.sick_overview();
			cout << "Uh oh! One of your tigers is sick! It will cost " << t.get_one_animal(n).get_sick_cost() << " dollars!" << endl;
			return (calculate_sick_costs(t.get_one_animal(n).get_sick_cost(), n, 0));
		}else if (r_num == 1 && s.return_size() != 0){	
			n = s.sick_overview();
			cout << "Uh oh! One of your sealions is sick! It will cost " << s.get_one_animal(n).get_sick_cost() << " dollars!" << endl;
			return (calculate_sick_costs(s.get_one_animal(n).get_sick_cost(), n, 1));
		}else if (r_num == 2 && b.return_size() != 0){
			n = b.sick_overview();
			cout << "Uh oh! One of your bears is sick! It will cost " << b.get_one_animal(n).get_sick_cost() << " dollars!" << endl;
			return (calculate_sick_costs(b.get_one_animal(n).get_sick_cost(), n, 2));
		}
	}

}

/*********************************************************************
 * ** Description: Determines if user can pay for an animal's sick costs.
 * ** If not, -1 is returned (to be used in later testing), otherwise,
 * ** animal is removed and fee is removed from bank. 
 * ** Parameters: int, int, int
 * ** Pre-Conditions: Zoo object has been declared.
 * ** Post-Conditions: Sick costs returned, or -1 is returned if couldn't
 * ** pay. Animal removed if applicable.
 * *********************************************************************/
int Zoo::calculate_sick_costs(int n, int i, int a){
	if (n <= bank){
		cout << "You paid a fee of " << n << " dollars, and your animal is cured!" << endl;
		return n;
	}else if(n > bank){
		cout << "You couldn't pay! Your animal has died." << endl;
		if (a == 0){
			t.remove_one_animal(i);
		}else if(a == 1){
			s.remove_one_animal(i);
		}else if(a== 2){
			b.remove_one_animal(i);
		}
		return -1;
	}

}

/*********************************************************************
 * ** Description: Prints out the monthly info. This prints months_passed,
 * ** and the amount of baby/adult/adolescent bears/tigers/sealions the 
 * ** user has. 
 * ** Parameters: None. 
 * ** Pre-Conditions: Zoo object has been declared elsewhere. 
 * ** Post-Conditions: Description above is printed to the screen.
 * *********************************************************************/
void Zoo::print_monthly_info(){
	cout << "\n\n+-+-+-+  Month: " << months_passed << "   +-+-+-+" << endl;
	cout << "Adult Tigers: " << t.count_adults() << endl;
	cout << "Adolescent Tigers: " << t.return_size() - (t.count_adults() + t.count_babies()) << endl;
	cout << "Baby Tigers: "<< t.count_babies() << endl;
	cout << "Adult SeaLions: " << s.count_adults() << endl;
	cout << "Adolescent SeaLions: " << s.return_size() - (s.count_adults() + s.count_babies()) << endl;
	cout << "Baby Sea Lions: "<< s.count_babies() << endl;
	cout << "Adult Bears: " << b.count_adults() << endl;	
	cout << "Adolescent Bears: " << b.return_size() - (b.count_adults() + b.count_babies()) << endl;
	cout << "Baby Bears: " << b.count_babies() << endl;
}

/*********************************************************************
 * ** Description: Prints out a simple welcome message, to be used
 * ** at beginning of program. 
 * ** Parameters: None.
 * ** Pre-Conditions: Zoo object has been declared.
 * ** Post-Conditions: Basic information given to user.
 * *********************************************************************/
void Zoo::print_welcome_message(){
	cout << "\nWelcome to the Zoo Tycoon!" << endl;
	cout << "In this game, you'll manage a zoo of Sea Lions, Tigers, and Bears." << endl;
	cout << "Each month, there will be special events and decisions to make." << endl;
	cout << "Let's get started!\n" << endl;
}

/*********************************************************************
 * ** Description: Adds the correct amount of revenue to the bank account,
 * ** and prints that information out to the user. 
 * ** Parameters: None.
 * ** Pre-Conditions: Zoo object has been declared.
 * ** Post-Conditions: Correct revenue is added to the bank, printed that
 * ** information to screen.
 * *********************************************************************/
void Zoo::collect_revenue(){
	int o= 0;
	int n= 0;
	n = t.revenue();
	cout << "Your tigers made " << n << " dollars." << endl;
	o += n;
	n = s.revenue();
	cout << "Your sea lions made " << n  << " dollars." << endl;
	o+= n;
	n = b.revenue();
	cout << "Your bears made " << n << " dollars." << endl;
	o+=n;
	bank += o;
	cout << "Your bank balance is now: " << bank << endl;	
}

/*********************************************************************
 * ** Description: Overarching process for aging up each of the animals
 * ** in the zoo. Uses Array functions to add each animal age, and prints
 * ** out message to user. Doesn't print anything if there are 0 animals.
 * ** Parameters: None.
 * ** Pre-Conditions: Zoo object has been declared elsewhere.
 * ** Post-Conditions: Animals aged up/message printed to screen if there
 * ** are animals in the zoo.
 * *********************************************************************/
void Zoo::age_up_animals(){
	if (t.return_size() != 0 || b.return_size() != 0 || s.return_size() != 0){
		t.age_up();
		b.age_up();
		s.age_up();
		cout << "Your animals are now 1 month older." << endl;
	}
}

/*********************************************************************
 * ** Description: Acts as the overall framework for the buying animals
 * ** processes. Oversees responses + uses other functions to shorten
 * ** this function. 
 * ** Parameters: None.
 * ** Pre-Conditions:  Zoo object has been declared elsewhere.
 * ** Post-Conditions: Takes in user responses for buying animals, makes
 * ** appropriate edits.
 * *********************************************************************/
void Zoo::buying_animals(){
	string response1, response2;
	while (true){
		response1 = error_handle_response1();
		if (response1 == "3"){
			cout << "You did not purchase any animals this month." << endl;
			return;
		}else{
			cout << "How many would you like to buy? (enter 0, 1, or 2.)" << endl;
			cin >> response2;
			if (response2 == "0"){
				cout << "You did not purchase any animals this month." << endl;
				return;
			}else if (response2 == "1" || response2 == "2"){
				if (can_afford(response1, get_int(response2))){
					return;
				}
			}else{
				cout << "Error: That's not one of the options. Please enter your selections again." << endl;
			}
		}
	}
}

/*********************************************************************
 * ** Description: Determines if the animal the player selected is affordable.
 * ** if so, goes through the buying process, then subtracts from bank.
 * ** otherwise, returns false to prompt for re-entry. 
 * ** Parameters: string, int
 * ** Pre-Conditions: All paramters and the Zoo object have been declared
 * ** elsewhere.
 * ** Post-Conditions: returns true/goes through buying process if can
 * ** buy selected animals, false otherwise.
 * *********************************************************************/
bool Zoo::can_afford(string r, int n){
	if (r == "0"){
		if ((n*15000) < bank){
			bank-= (t.buying_animals(n,base_cost));
			cout << "You bought " << n << " tiger(s)." << endl;
			return true;
		}
	}else if (r == "1"){
		if ((n*800) < bank){
			bank-= (s.buying_animals(n, base_cost));
			cout << "You bought " << n << " sealion(s)." << endl;
			return true;
		}
	}else if (r == "2"){
		if (n*6000 < bank){
			bank-= (b.buying_animals(n, base_cost));
			cout << "You bought " << n << " bear(s)." << endl;
			return true;
		}
	}
	cout << "Error: You'll go broke if you buy that many animals! Please make your selections again." << endl;
	cout << "\nYour bank balance is: " << bank << endl;
	return false;
}

/*********************************************************************
 * ** Description: Error handles one of the responses for the buying animals
 * ** (the first response where they're deciding what animals they wanna buy)
 * ** Parameters: None.
 * ** Pre-Conditions: Zoo object has been declared elsewhere.
 * ** Post-Conditions: Returns the selection they make, or if they don't have
 * ** money to buy a single sea lion(the cheapest animal), returns stop
 * ** automatically
 * *********************************************************************/
string Zoo::error_handle_response1(){
	string response;
	while (true){
		if (bank >= 800){

			cout << "\nWould you like to buy animals? (0 for tigers";
			cout << ", 1 for sea lions, 2 for bears, 3 for none.)" << endl;
			cin >> response;
			if (response == "0" || response == "1"|| response == "2" || response == "3"){
				return response;
			}else{
				cout << "Error: Please only input 0, 1, 2, or 3." << endl;
			}
		}else{
			cout << "You can't afford any animals!" << endl;
			return ("3");
		}
	}

}

/*********************************************************************
 * ** Description: Calculates the cost of food based on the base_cost
 * ** and an inputted modifier. 
 * ** Parameters: float
 * ** Pre-Conditions: float and Zoo object have been declared elsewhere
 * ** Post-Conditions: Food cost with modifier var is returned.
 * *********************************************************************/
float Zoo::calc_food_costs(float var){
	float cost = 0;

	cost += s.buy_food(var);	
	cost += b.buy_food(var);
	cost += t.buy_food(var);	
	return cost;
}

/*********************************************************************
 * ** Description: Prints out various info regarding the food, including
 * ** the base cost, bank information, and the prices of the 3 different
 * ** kinds of food. 
 * ** Parameters: None.
 * ** Pre-Conditions: Zoo object has been intiailized.
 * ** Post-Conditions: Information about the food is printed.
 * *********************************************************************/
void Zoo::print_food_info(){
	cout << "\n==It's time to buy food for your animals! Please enter the food quality you want.==" << endl;
	cout << "\nThe base cost for this month: " << base_cost;
	cout << "\n\nYour bank balance is: " << bank << endl;
		
	cout << "\nEnter 1 for luxury, which reduces the chance of your animals getting sick by half.";
	cout << "\nCost: " << calc_food_costs(2);

	cout << "\n\nEnter 2 for cheap, which doubles the probability of your animals getting sick.";
	cout << "\nCost: " << calc_food_costs(.5);

	cout << "\n\nEnter 3 for regular, which acts as the normal food.";
	cout << "\nCost: " << calc_food_costs(1) << endl;
}

/*********************************************************************
 * ** Description: Acts as the specific buying process for food. Determines if
 * ** user can even afford the cheapest food, then lets them determine
 * ** from there what type of food they want.
 * ** Parameters: None.
 * ** Pre-Conditions:  Zoo object has been declared elsewhere.
 * ** Post-Conditions: Changes food_type to selected, returns cost of food
 * *********************************************************************/
float Zoo::buying_food(){
	string response;
	while (true){
		if (bank - (calc_food_costs(.5)) <= 0){
			cout << "You cannot afford any food for your animals!" << endl;
			return (-1);		
		}	
		print_food_info();
		cin >> response;	
		if (response == "1" && can_afford_food(2) != -1){
			food_type = 1;
			cout << "You bought luxury food!" << endl;
			return (calc_food_costs(2));
		}else if (response == "2" && can_afford_food(0.5) != -1){
			food_type = 2;
			cout << "You bought cheap food!" << endl;
			return (calc_food_costs(.5));
		}else if (response == "3" && can_afford_food(1) != -1){
			food_type = 0;
			cout << "You bought normal food!" << endl;
			return (calc_food_costs(1));
		}
		cout << "Error: You cannot buy that type of food. Please try again." << endl;
	}
}


/*********************************************************************
 * ** Description: Determines if the user can afford a certain type of
 * ** food. 
 * ** Parameters: int 
 * ** Pre-Conditions: int and Zoo object have been declared elsewhere 
 * ** Post-Conditions: returns the cost of the food if its affordable,
 * ** returns -1 otherwise.
 * *********************************************************************/
float Zoo::can_afford_food(int var){
	if (calc_food_costs(var) <= bank){
		return (calc_food_costs(var));				
	}else{
		cout << "You cannot afford that food!" << endl;
		return -1;
	}
}

/*********************************************************************
 * ** Description: Changes the food costs to a random new probability, that
 * ** can be 80 to 120 percent of original base cost. 
 * ** Parameters: None.
 * ** Pre-Conditions: Zoo object has been intitialized elsewhere
 * ** Post-Conditions: Base cost is changed to new value.
 * *********************************************************************/
void Zoo::change_food_costs(){
	if (months_passed !=0){
		srand(time(NULL));
		float r_num = ((rand() % 40) + 80) * 0.01;	
		base_cost *= r_num;
		s.change_food_costs(r_num);	
		t.change_food_costs(r_num);
		b.change_food_costs(r_num);
	}
	int buy_food = trunc(buying_food());
		
	if (buy_food == -1){
		bank = 0; 
		return;
	}else{
		bank-= buy_food;
	}

	
}

/*********************************************************************
 * ** Description: Acts as the main framework for the tycoon. Prints a
 * ** welcome message, then ages up animals/prints info, generates a 
 * ** special event, collects revenue, goes through buying proccess,
 * ** buys food/checks for bankruptcy, and increases month.
 * ** Parameters: None.
 * ** Pre-Conditions: Zoo object is intialized.
 * ** Post-Conditions: Above tycoon game is executed until user wants to
 * ** stop/goes bankrupt.
 * *********************************************************************/
void Zoo::main_game(){
	print_welcome_message();
	string response;
	while (true){
		age_up_animals();
		print_monthly_info();
		spec_event();
		
		collect_revenue();

		buying_animals();

		change_food_costs();
		if (bankruptcy_check()){
			return;
		}
		cout << "\n+++You made it through month " << months_passed << "! Keep playing? (Enter 0 to quit.)+++" << endl;
		cin >> response;
		if (response == "0"){
			return;
		}

		months_passed++;

	}
}
