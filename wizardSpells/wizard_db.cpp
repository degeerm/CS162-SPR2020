#include "./wizard_db.h"

using namespace std;

/*********************************************************************
 * ** Description: Creates an array of c-strings of the two int dimensions
 * ** given as parameters.
 * ** Parameters: int, int
 * ** Pre-Conditions: int and int have been defined elsewhere
 * ** Post-Conditions: Reference to array of c-strings on heap is returned. 
 * *********************************************************************/
char **create_cstring(int row, int col){
	char **a;
	a = new char*[row];
	for (int i = 0; i < row; i++){
		a[i] = new char [col];
	}
	return a;
}

/*********************************************************************
 * ** Description: Deletes an array of c-strings off the heap.
 * ** Parameters: char**, int
 * ** Pre-Conditions: char** and int have been defined elsewhere.
 * ** Post-Conditions: char** is deleted off of the heap.
 * *********************************************************************/
void delete_cstring(char** arg_list, int rows){
	for (int i = 0; i < rows; i++){
		delete[] arg_list[i];
	}
	delete [] arg_list;
	arg_list = NULL;
}

/*********************************************************************
 * ** Description: Deletes a wider variety of info used throughout the
 * ** program; to be used after successful login and successful file 
 * ** check.
 * ** Parameters: char**, int, int, spellbook*, spell*
 * ** Pre-Conditions: All paramters have been declared elsehwere,
 * ** char**, spellbook*, and spell* are on the heap
 * ** Post-Conditions: Char**, spellbook*, and spell* are all deleted
 * ** off the heap.
 * *********************************************************************/
void delete_info(char** twod_cstring, int cstring_size, int num_b, spellbook* book_list, spell* spell_list){
	for (int i = 0; i < num_b; i++){
		delete[] book_list[i].s;
	}

	delete[] book_list;
	delete[] spell_list;

	delete_cstring(twod_cstring, cstring_size);
}

/*********************************************************************
 * ** Description: Creates an array of spell structs on the heap of size
 * ** int.
 * ** Parameters: int
 * ** Pre-Conditions: int has been defined elsewhere
 * ** Post-Conditions: Reference to spell array on heap is returned.
 * *********************************************************************/
spell* create_spells(int num){
	spell* s = new spell[num];
	return s;
}

/*********************************************************************
 * ** Description: Creates an array of spellbook structs on the heap of
 * ** size int.
 * ** Parameters: int
 * ** Pre-Conditions: int has been defined elsewhere
 * ** Post-Conditions: Reference to spellbook array on heap is returned. 
 * *********************************************************************/
spellbook* create_spellbook(int num){
	spellbook *s = new spellbook[num];
	return s;
}

/*********************************************************************
 * ** Description: Determines if a given string could be converted into
 * ** an integer.
 * ** Parameters: string
 * ** Pre-Conditions: String has been defined elsewhere
 * ** Post-Conditions: True or false is returned, depending on if string 
 * ** is an int or not.
 * *********************************************************************/
bool is_int(string num){
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
int get_int(string prompt){
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
 * ** Description: Input-checks the user's integer ID num. If it is a
 * ** valid input (integer), returns the integer version of that string
 * ** input. If not, prompts until it is.
 * ** Parameters: None.
 * ** Pre-Conditions: None.
 * ** Post-Conditions: Integer version of user ID is returned.
 * *********************************************************************/
int input_user(){
	string temp_input;
	while (true){
		cout << "\nEnter your ID number: ";
		cin >> temp_input;

		if (is_int(temp_input)){
			return get_int(temp_input);
		}else{
			cout << "\nError: Enter an ID number with integers only.";
			cout << " Please input again." << endl;
		}
	}

}

/*********************************************************************
 * ** Description: Swaps two spellbooks, to be used in the sorting
 * ** functions.
 * ** Parameters: spellbook*, spellbook*
 * ** Pre-Conditions: Both spellbooks have been defined elsewhere.
 * ** Post-Conditions: Values of spellbook1 and spellbook2 are swapped.
 * *********************************************************************/
void swap_spellbook(spellbook* book1, spellbook* book2){
	spellbook temp = *book1;
	*book1 = *book2;
	*book2 = temp;
	
}

/*********************************************************************
 * ** Description: Prints out the various bits of information about the
 * ** wizard user, including name, ID, position title, and beard length.
 * ** Parameters: wizard
 * ** Pre-Conditions: wizard has been defined elsewhere.
 * ** Post-Conditions: Information about wizard is printed to screen.
 * *********************************************************************/
void print_wizard_info(wizard w){
	cout << "\nWelcome " << w.name << "!" << endl;
	cout << "ID: " << w.id << endl;
	cout << "Status: " << w.position_title << endl;	
	cout << "Beard Length: " << w.beard_length << endl;

}

/*********************************************************************
 * ** Description: Prints out the options that the user can choose
 * ** for sorting.
 * ** Parameters: None.
 * ** Pre-Conditions: None.
 * ** Post-Conditions: The 4 options for sorting the user's data are
 * ** printed to the screen.
 * *********************************************************************/
void list_sorting_options(){
	cout << "\nWhich option would you like to choose?" << endl;
	cout << "Sort spellbooks by their pages (press 1)"<< endl;
	cout << "Group spells by their effect (press 2)"<< endl;
	cout << "Sort spellbooks by average success rate (press 3)" << endl;
	cout << "Quit (press 4)"<< endl;
}

/*********************************************************************
 * ** Description: Prints out the options that the user can choose for
 * ** outputting their information.
 * ** Parameters: None.
 * ** Pre-Conditions: None.
 * ** Post-Conditions: Options for dislaying information are printed to
 * ** the screen.
 * *********************************************************************/
void print_output_options(){
	cout << "\nHow would you like your information displayed?" << endl;
	cout << "Print directly to screen (press 1)" << endl;
	cout << "Print to an output file (press 2)" << endl;
}

/*********************************************************************
 * ** Description: Checks to see if a given userID and password matches
 * ** any of the wizard information in a given textfile. If so, returns
 * ** true. false otherwise. 
 * ** Parameters: int, string, ifstream &
 * ** Pre-Conditions: File has been opened, int and string have been
 * ** defined elsewhere.
 * ** Post-Conditions: Returns true if wizard information matches anything
 * ** in text file, false otherwise.
 * *********************************************************************/
bool check_credentials(int user, string pass, ifstream &f){
	wizard currentWizard;
	string dummyString;

	getline(f, dummyString);
	while (!f.eof()){

		f >> currentWizard.name;
		f >> currentWizard.id;
		f >> currentWizard.password;
		f >> currentWizard.position_title;
		f >> currentWizard.beard_length;
		if (user == currentWizard.id){
			if (pass.compare(currentWizard.password) == 0){
				print_wizard_info(currentWizard);
				return true;
			}
		}
	}
	return false;
}

/*********************************************************************
 * ** Description: Takes information from the input file and stores it
 * ** inside of an object of wizard class, returns that wizard
 * ** Parameters: int, string, ifstream &
 * ** Pre-Conditions: File has been opened, int and string have been
 * ** defined elsewhere.
 * ** Post-Conditions: Returns information from the file in a wizard
 * ** struct.
 * *********************************************************************/
wizard return_wizard(char** arg_list, ifstream &f, int user, string pass){
	f.close();
	f.open(arg_list[1]);
	wizard currentWizard;
	string dummyString;
	getline(f, dummyString);
	while (!f.eof()){
		f >> currentWizard.name;
		f >> currentWizard.id;
		f >> currentWizard.password;
		f >> currentWizard.position_title;
		f >> currentWizard.beard_length;
		if (user == currentWizard.id){
			if (pass.compare(currentWizard.password) == 0){
				return (currentWizard);
			}
		}
	}
}

/*********************************************************************
 * ** Description: Initializes a wizard to some base values if login fails,
 * ** to be used while the program running to check if login was
 * ** successful.
 * ** Parameters: None.
 * ** Pre-Conditions: None.
 * ** Post-Conditions: Returns a wizard with name "", id -1, password "",
 * ** beard length -1, and position title "failed".
 * *********************************************************************/
wizard login_failed(){
	wizard user;
	user.name = "";
	user.id = -1;
	user.password = "";
	user.beard_length - -1;
	user.position_title = "failed";
	return user;
}

/*********************************************************************
 * ** Description: Checks to see if a file exists by opening and closing
 * ** it, then returning that value as a bool.
 * ** Parameters: string
 * ** Pre-Conditions: string has been defined elsewhere
 * ** Post-Conditions: Returns true if its a valid filename, false
 * ** otherwise.
 * *********************************************************************/
wizard log_in_main(char** arg_list, int argc, ifstream &f){	
	//variable setup 
	int idNum;
	string passWord;

	for (int i =0; i < 3; i++){
		//ID/password entering
		idNum = input_user();
		cout << "\nEnter your password: ";
		cin >> passWord;
		//if credentials are right
		if (check_credentials(idNum, passWord, f)){
			f.close();
			return return_wizard(arg_list, f, idNum, passWord);

		//if credentials are wrong
		}if (!check_credentials(idNum, passWord,f) && i != 3){
			cout << "\nError: Username or password incorrect. Please try again." << endl;
			f.close();
			f.open(arg_list[1]);
			cin.clear();
		}
	}
	//Too many attempts
	cout << "\nError: Too many attempts (3). Exiting program." << endl;
	return login_failed();
}

/*********************************************************************
 * ** Description: Checks to see if a file exists by opening and closing
 * ** it, then returning that value as a bool.
 * ** Parameters: string
 * ** Pre-Conditions: string has been defined elsewhere
 * ** Post-Conditions: Returns true if its a valid filename, false
 * ** otherwise.
 * *********************************************************************/
bool file_exists(string filename){
	ifstream ifile;
	ifile.open(filename.c_str());
	bool return_value = ifile;
	ifile.close();
	return return_value;
}

/*********************************************************************
 * ** Description: Takes in string for a file output within function,
 * ** then returns that string (originally used to check if file existed
 * ** which is why its its own function)
 * ** Parameters: None. 
 * ** Pre-Conditions: None.
 * ** Post-Conditions: A string is returned to be used as an output
 * ** filename.
 * *********************************************************************/
string file_output_checker(){
	string tempstring;
	while (true){
		cout << "Please enter the desired filename." << endl;
		cin >> tempstring;
		return tempstring;
	}
}

/*********************************************************************
 * ** Description: Takes in 2 cstrings from an array within a function,
 * ** and if both of those strings are filenames, returns true (they can
 * ** later be converted to cstrings and used as filenames)
 * ** Parameters: int, char**
 * ** Pre-Conditions: int and char** have been defined elsewhere.
 * ** Post-Conditions: Returns true if both cstrings are valid filenames,
 * ** false otherwise.
 * *********************************************************************/
bool file_input_checker(int arg, char **arglist){
 	string tempstring;
	if (arg != 3){
		cout << "Error: Incorrect number of arguments entered. Exiting program."<<endl;
		delete_cstring(arglist, arg);

		return false;
	}

	for (int a  = 1; a < arg; a++){
		tempstring = "";
		for (int c = 0; c < 256; c++){
			tempstring = tempstring + arglist[a][c];
		}
		if (!file_exists(tempstring)){
			cout << "\nError: One of your filenames does not exist. Exiting program." << endl;
			delete_cstring(arglist, arg);
			return false;
		}
	}
	return true;
}

/*********************************************************************
 * ** Description: Acts as the main framework for getting wizard info,
 * ** hosts the login process and returns the wizar.
 * ** Parameters: char**, int
 * ** Pre-Conditions: char** and int have been defined elsewhere.
 * ** Post-Conditions: Wizard with corresponding information (or failed
 * ** information) is returned.
 * *********************************************************************/
wizard get_wizard_info(char** arg_list, int argc){
	wizard user;
	ifstream f(arg_list[1]);
	user = log_in_main(arg_list,argc, f);
	f.close();
	return user;
}

/*********************************************************************
 * ** Description: Goes through and, using the spellbooks input file, 
 * ** filles a spell array with spells (this function is used in the
 * ** get_spellbook_data function)
 * ** Parameters:spell*, int, ifstream&
 * ** Pre-Conditions: Spell* and int have been defined elsewhere, file
 * ** is open
 * ** Post-Conditions: The spell array passed in is now filled with info
 * ** rom the input file.
 * *********************************************************************/
void get_spell_data(spell* spell_array, int num_of_spells, ifstream &f){
	for (int i = 0; i < num_of_spells; i++){
		f >> spell_array[i].name;
		f >> spell_array[i].success_rate;
		f >> spell_array[i].effect;
	}
}

/*********************************************************************
 * ** Description: Goes through all of the spells in a spellbook and 
 * ** uses those to calculate the average success rate of the spellbook.
 * ** Parameters: spellbook
 * ** Pre-Conditions: Spellbook has been defined elsewhere
 * ** Post-Conditions: The average success rate is returned, to be assigned
 * ** to its corresponding value in the spellbook.
 * *********************************************************************/
float calculate_success(spellbook spellbook_a){
	float avg = 0.0;
	int total_num = 0;
	for (int j =0; j < spellbook_a.num_spells; j++){
		//for each spell in book, add its rate to avg, and 1 to total num.
		avg += spellbook_a.s[j].success_rate;
		total_num++;			
	}
	if (total_num == 0){
		total_num = 1;
	}
	return (avg/(1.0*total_num));
}

/*********************************************************************
 * ** Description: Populates an array of spellbooks with information
 * ** from the file. 
 * ** Parameters: spellbook*, int, ifstream &
 * ** Pre-Conditions: spellbook* and int have been defined elsewhere,
 * ** file is open.
 * ** Post-Conditions: spellbook* is filled with all of the information
 * ** from the file.
 * *********************************************************************/
void get_spellbook_data(spellbook* spellbook_array,int num_of_spellbooks, ifstream &f){
	string dummyString;
	getline(f, dummyString);
	for (int i = 0; i < num_of_spellbooks; i++){
		//basic info
		f >> spellbook_array[i].title;
		f >> spellbook_array[i].author;
		f >> spellbook_array[i].num_pages;
		f >> spellbook_array[i].edition;
		f >> spellbook_array[i].num_spells;
		
		//spellist related info
		spell * s = create_spells(spellbook_array[i].num_spells);
		spellbook_array[i].s = s;
		get_spell_data(s, spellbook_array[i].num_spells, f); 
		spellbook_array[i].avg_success_rate = calculate_success(spellbook_array[i]);
	}
}

/*********************************************************************
 * ** Description: Populates an array of spells with information from
 * ** all of the spellbooks.
 * ** Parameters: spell*, spellbook*, int
 * ** Pre-Conditions: spell*, spellbook*, and int have been defined 
 * ** elsewhere.
 * ** is open.
 * ** Post-Conditions: spell* is filled with all of the spells from a
 * ** spellbooks.
 * *********************************************************************/
void spell_master_list(spellbook* book_list, spell* spell_list, int num){
	int k =0;
	for (int i =0; i <num; i++){
		for (int j = 0; j < book_list[i].num_spells; j++){
			spell_list[k]= book_list[i].s[j];
			k++;
		}
	}
}

/*********************************************************************
 * ** Description: If the user is a student, removes all of the poision
 * ** and death spellbooks from the list.
 * ** Parameters: spellbook*, int &, string
 * ** Pre-Conditions: spellbook*, int &, and string have all been defined
 * ** elsewhere.
 * ** Post-Conditions: All spellbooks with poision and death are removed
 * ** from spellbook*.
 * *********************************************************************/
void make_spellbook_friendly(spellbook* book_list, int& num, string title){
	//if title is student, remove all books with death/poison
	if (title.compare("Student")==0 || title.compare("student") == 0){
		for (int i = 0; i < num; i++){
			for (int j = 0; j < book_list[i].num_spells; j++){
				string current_effect = book_list[i].s[j].effect;
				if (current_effect.compare("death")==0 ||current_effect.compare("poison") == 0){
					//if book has death/poison spell, delete that book's heap spellist.
					//REmove it from list.
					delete[] book_list[i].s;
					(num--);
					for (int k = i; k < num; k++){
						book_list[k]=book_list[k+1];
					}
					i--;

				}
			}
		}
	
	}

}

/*********************************************************************
 * ** Description: If the user is a student, removes all of the posion
 * ** and death spells from a list of spells.
 * ** Parameters: spell*, int &, string
 * ** Pre-Conditions: spell*, int &, and string have all been defined
 * ** elsewhere.
 * ** Post-Conditions: All spells with poison and death are removed from
 * ** spell*. 
 * *********************************************************************/
void make_spelllist_friendly(spell* spell_list, int &num, string title){
	//if their title is "Student", remove all death/poison spells
	if (title.compare("Student")==0 || title.compare("student") == 0){
		for (int i = 0; i < num; i++){
			string current_effect = spell_list[i].effect;
			if (current_effect.compare("death")==0 ||current_effect.compare("poison") == 0){
				//if spell is found, remove it from list AND reduce list size by one.
				(num--);
				for (int k = i; k < num; k++){
					spell_list[k]=spell_list[k+1];
				}
				i--;
			}
		}
	}	
}

/*********************************************************************
 * ** Description: Sorts a list of spellbooks by their pages using a 
 * ** bubble sort.
 * ** Parameters: spellbook*, int
 * ** Pre-Conditions: spellbook* and int have been defined elsewhere.
 * ** Post-Conditions: spellbook* is now sorted, lowest to highest, by
 * ** number of pages.
 * *********************************************************************/
void sort_num_pages(spellbook* book_list, int num_of_books){
	
	//i loops through books, j loops from last book analyzed (bubble sort)
	for (int i = 0; i < (num_of_books)-1; i++){
		for (int j = 0; j < (num_of_books) -i -1; j++){
			if (book_list[j].num_pages > book_list[j+1].num_pages){
				swap_spellbook(&book_list[j], &book_list[j+1]);
			}
		}
	}
}

/*********************************************************************
 * ** Description: Sorts a list of spellbooks by their average success
 * ** rate. 
 * ** Parameters: spellbook*, int
 * ** Pre-Conditions: spellbook* and int have been defined elsewhere.
 * ** Post-Conditions: spellbook* is now sorted, lowest to highest, by
 * ** average success rate.
 * *********************************************************************/
void sort_avg_rate(spellbook* book_list, int num_of_books){
	
	//i loops through books, j loops from last book analyzed (bubble sort)
	for (int i = 0; i < (num_of_books)-1; i++){
		for (int j = 0; j < (num_of_books) -i -1; j++){
			if (book_list[j].avg_success_rate > book_list[j+1].avg_success_rate){
				swap_spellbook(&book_list[j], &book_list[j+1]);
			}
		}
	}
}

/*********************************************************************
 * ** Description: Sorts a list of spells by their effects.
 * ** Parameters: spell*, int
 * ** Pre-Conditions: spell* and int have been defined elsewhere.
 * ** Post-Conditions: spell* is now sorted by effect in this order:
 * ** bubble, memory loss, fire, poison, death
 * *********************************************************************/
void sort_by_effect(spell* spell_list, int num_spells){
	/*i is looping through each effect, j loops through each spell.
	l acts as a placeholder to make sure the spells print in order
	of the books they're in (IE, a bubble spell in spellbook 1 will
	appear before a bubble spell in spellbook 2)*/
	string effects[5] = {"bubble", "memory_loss", "fire", "poison", "death"};
	for (int i = 4; i >= 0; i--){
		int l = 0;	
		for (int j = 0; j < num_spells; j++){
			if (spell_list[j].effect == effects[i]){
				spell temp = spell_list[j];
				for (int k = j; k>l; k--){
					spell_list[k] = spell_list[k-1];
				}
				spell_list[l] = temp;
				l++;
			}
		}
	}	
}

/*********************************************************************
 * ** Description: Lets the user decide if they wanna output their sort-
 * ** by pages to the screen or to a file.
 * ** Parameters: spellbook*, int
 * ** Pre-Conditions: spellbook* and int have been declared elsewhere.
 * ** Post-Conditions: Sorted list of spellbooks is either printed to a
 * ** chosen file, or printed to the screen.
 * *********************************************************************/
void output_format_pages(spellbook* book_list, int num_books){
	string temp;
	while (true){
		print_output_options();
		cin >> temp;
		//output to screen option
		if (temp == "1"){
			for (int i =0; i < (num_books); i++){
				cout << book_list[i].title << "  " << book_list[i].num_pages << endl;
			}
			return;
		//Output to a file option
		}else if (temp == "2"){	
			string filename = file_output_checker();
			fstream outf(filename.c_str(), std::fstream::out|std::fstream::in|std::fstream::app);
			for (int i =0; i < (num_books); i++){
				outf << book_list[i].title << "  " << book_list[i].num_pages << endl;
			}
			cout << "Information appended to desired file." << endl;
			outf.close();
			return;

		}
		//If user is wrong in input	
		else if(temp !="1" && temp != "2"){
			cout << "Error: Please only input 1 or 2." << endl;	
		}
	}
}

/*********************************************************************
 * ** Description: Lets the user decide if they wanna output their sort-
 * ** by effect to the screen or to a file.
 * ** Parameters: spell*, int
 * ** Pre-Conditions: spell* and int have been declared elsewhere.
 * ** Post-Conditions: Sorted list of spells is either printed to a
 * ** chosen file, or printed to the screen.
 * *********************************************************************/
void output_format_effect(spell* spell_list, int num_spells){
	string temp;
	while (true){
		print_output_options();
		cin >> temp;
		//output to screen option
		if (temp == "1"){
			for (int i =0; i < (num_spells); i++){
				cout << spell_list[i].name << "  " << spell_list[i].effect << endl;
			}
			return;
		//Output to a file option
		}else if (temp == "2"){	
			string filename = file_output_checker();
			fstream outf(filename.c_str(), std::fstream::out|std::fstream::in|std::fstream::app);
			for (int i =0; i < (num_spells); i++){
				outf << spell_list[i].name << "  " << spell_list[i].effect << endl;
			}
			cout << "Information appended to desired file." << endl;
			outf.close();
			return;
		}
		//If user is wrong in input	
		else if(temp !="1" && temp != "2"){
			cout << "Error: Please only input 1 or 2." << endl;	
		}
	}
}

/*********************************************************************
 * ** Description: Lets the user decide if they wanna output their sort-
 * ** by avg success rate to the screen or to a file.
 * ** Parameters: spellbook*, int
 * ** Pre-Conditions: spellbook* and int have been declared elsewhere.
 * ** Post-Conditions: Sorted list of spellbooks is either printed to a
 * ** chosen file, or printed to the screen.
 * *********************************************************************/
void output_format_rate(spellbook* book_list, int num_books){
	string temp;
	while (true){
		print_output_options();
		cin >> temp;
		//output to screen option
		if (temp == "1"){
			for (int i =0; i < (num_books); i++){
				cout << book_list[i].title << "  " << book_list[i].avg_success_rate << endl;
			}
			return;
		//Output to a file option
		}else if (temp == "2"){	
			string filename = file_output_checker();
			fstream outf(filename.c_str(), std::fstream::out|std::fstream::in|std::fstream::app);
			for (int i =0; i < (num_books); i++){
				outf << book_list[i].title << "  " << book_list[i].avg_success_rate << endl;
			}
			cout << "Information appended to desired file." << endl;
			outf.close();
			return;

		}
		//If user is wrong in input	
		else if(temp !="1" && temp != "2"){
			cout << "Error: Please only input 1 or 2." << endl;	
		}
	}

}

/*********************************************************************
 * ** Description: Lets the user choose which sorting option they want to
 * ** do, then calls the output format for that.
 * ** Parameters: spellbook*, spell*, int, int
 * ** Pre-Conditions: All above paramaters have been defined elsewhere.
 * ** Post-Conditions: Options are printed to the screen, user selects an
 * ** option for sorting/printing until they quit.
 * *********************************************************************/
void listing_choose_option(spellbook* book_list, spell* spell_list, int num_book, int num_spell){
	string temp;
	while (true){	
		list_sorting_options();
		cin >> temp;
		if (temp == "1"){
			sort_num_pages(book_list, num_book);
			output_format_pages(book_list, num_book);
		}
		else if (temp == "2"){
			sort_by_effect(spell_list, num_spell);
			output_format_effect(spell_list, num_spell);
		}
		else if (temp == "3"){
			sort_avg_rate(book_list, num_book);
			output_format_rate(book_list, num_book);
		}
		else if (temp == "4"){
			return;
		}
		else if (temp != "1" && temp != "2" && temp != "3" && temp != "4"){
			cout << "Error: Please select either 1, 2, or 3."<< endl;
		}
		cin.ignore();
		
	}
}

/*********************************************************************
 * ** Description: Acts as main program base; sets up all of the major
 * ** arrays and opens the necessary files, then calls the listing_choose
 * ** option in order to actually cycle through (w/ a while loop)
 * ** Parameters: char**, int, char*
 * ** Pre-Conditions: char**, int, char* have all been defined elsewhere.
 * ** Post-Conditions: Program runs through until incorrect input in login,
 * ** or until user quits.
 * *********************************************************************/
bool prog_run(char **argument_list, int argc, char* spellbook_file){
	int num_of_books = 0, numspells = 0;
	wizard user = get_wizard_info(argument_list, argc);
	//checks if login failed
	if (user.position_title == "failed"){
		return false;
	}
	//setting up ifstream
	ifstream f(spellbook_file);
	
	//spellbook data
	f >> num_of_books;
	spellbook * book_list = create_spellbook(num_of_books);
	get_spellbook_data(book_list, num_of_books, f);
	//spell data	
	for (int i =0; i <num_of_books; i++){
		numspells+= book_list[i].num_spells;
	}
	spell* spell_list = create_spells(numspells);
	spell_master_list(book_list,spell_list, num_of_books);

	//makes student friendly if applicable
	make_spellbook_friendly(book_list, num_of_books,user.position_title);
	make_spelllist_friendly(spell_list,numspells, user.position_title);
	
	//loop
	listing_choose_option(book_list,spell_list, num_of_books, numspells);		

	//cleanup
	f.close();
	delete_info(argument_list, argc,num_of_books, book_list, spell_list);
	return true;
}
