#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <cmath>

using namespace std;
struct wizard {
  string name;
  int id;
  string password;
  string position_title; 
  float beard_length;
};

struct spellbook {
  string title;
  string author;
  int num_pages;
  int edition;
  int num_spells;
  float avg_success_rate;
  struct spell *s;
};

struct spell {
  string name;
  float success_rate;
  string effect; 
};

/*********************************************************************
 * ** Description: Creates an array of c-strings of the two int dimensions
 * ** given as parameters.
 * ** Parameters: int, int
 * ** Pre-Conditions: int and int have been defined elsewhere
 * ** Post-Conditions: Reference to array of c-strings on heap is returned. 
 * *********************************************************************/
char** create_cstring(int, int);

/*********************************************************************
 * ** Description: Creates an array of spell structs on the heap of size
 * ** int.
 * ** Parameters: int
 * ** Pre-Conditions: int has been defined elsewhere
 * ** Post-Conditions: Reference to spell array on heap is returned.
 * *********************************************************************/
spell* create_spells(int);

/*********************************************************************
 * ** Description: Creates an array of spellbook structs on the heap of
 * ** size int.
 * ** Parameters: int
 * ** Pre-Conditions: int has been defined elsewhere
 * ** Post-Conditions: Reference to spellbook array on heap is returned. 
 * *********************************************************************/
spellbook* create_spellbook(int);

/*********************************************************************
 * ** Description: Deletes an array of c-strings off the heap.
 * ** Parameters: char**, int
 * ** Pre-Conditions: char** and int have been defined elsewhere.
 * ** Post-Conditions: char** is deleted off of the heap.
 * *********************************************************************/
void delete_cstring(char** ,int);

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
void delete_info(char**, int, int, spellbook*, spell*);

/*********************************************************************
 * ** Description: Determines if a given string could be converted into
 * ** an integer.
 * ** Parameters: string
 * ** Pre-Conditions: String has been defined elsewhere
 * ** Post-Conditions: True or false is returned, depending on if string 
 * ** is an int or not.
 * *********************************************************************/
bool is_int(string);

/*********************************************************************
 * ** Description: Takes in a string prompt, and if it is an integer,
 * ** returns the integer version of it. (Does not work for negative
 * ** integers)
 * ** Parameters: string
 * ** Pre-Conditions: String has been defined elsewhere.
 * ** Post-Conditions: Integer version of string is returned, -1 otherwise.
 * *********************************************************************/
int get_int(string);

/*********************************************************************
 * ** Description: Input-checks the user's integer ID num. If it is a
 * ** valid input (integer), returns the integer version of that string
 * ** input. If not, prompts until it is.
 * ** Parameters: None.
 * ** Pre-Conditions: None.
 * ** Post-Conditions: Integer version of user ID is returned.
 * *********************************************************************/
int input_user();

/*********************************************************************
 * ** Description: Swaps two spellbooks, to be used in the sorting
 * ** functions.
 * ** Parameters: spellbook*, spellbook*
 * ** Pre-Conditions: Both spellbooks have been defined elsewhere.
 * ** Post-Conditions: Values of spellbook1 and spellbook2 are swapped.
 * *********************************************************************/
void swap_spellbook(spellbook*, spellbook*);

/*********************************************************************
 * ** Description: Prints out the various bits of information about the
 * ** wizard user, including name, ID, position title, and beard length.
 * ** Parameters: wizard
 * ** Pre-Conditions: wizard has been defined elsewhere.
 * ** Post-Conditions: Information about wizard is printed to screen.
 * *********************************************************************/
void print_wizard_info(wizard);

/*********************************************************************
 * ** Description: Prints out the options that the user can choose
 * ** for sorting.
 * ** Parameters: None.
 * ** Pre-Conditions: None.
 * ** Post-Conditions: The 4 options for sorting the user's data are
 * ** printed to the screen.
 * *********************************************************************/
void list_sorting_options();

/*********************************************************************
 * ** Description: Prints out the options that the user can choose for
 * ** outputting their information.
 * ** Parameters: None.
 * ** Pre-Conditions: None.
 * ** Post-Conditions: Options for dislaying information are printed to
 * ** the screen.
 * *********************************************************************/
void print_output_options();

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
bool check_credentials(int, string, ifstream &);

/*********************************************************************
 * ** Description: Takes information from the input file and stores it
 * ** inside of an object of wizard class, returns that wizard
 * ** Parameters: int, string, ifstream &
 * ** Pre-Conditions: File has been opened, int and string have been
 * ** defined elsewhere.
 * ** Post-Conditions: Returns information from the file in a wizard
 * ** struct.
 * *********************************************************************/
wizard return_wizard(char**, int, string);

/*********************************************************************
 * ** Description: Initializes a wizard to some base values if login fails,
 * ** to be used while the program running to check if login was
 * ** successful.
 * ** Parameters: None.
 * ** Pre-Conditions: None.
 * ** Post-Conditions: Returns a wizard with name "", id -1, password "",
 * ** beard length -1, and position title "failed".
 * *********************************************************************/
wizard login_failed();

/*********************************************************************
 * ** Description: Acts as the main login function, cycles through
 * ** username/password input three times or until log in is successful.
 * ** Parameters: char**, int, ifstream &
 * ** Pre-Conditions: File is open, int and char** are defined elsewhere.
 * ** Post-Conditions: Either the wizard is logged in, or the program
 * ** ends (if three attempts are reached)
 * *********************************************************************/
wizard log_in_main(char**, int, ifstream&);

/*********************************************************************
 * ** Description: Checks to see if a file exists by opening and closing
 * ** it, then returning that value as a bool.
 * ** Parameters: string
 * ** Pre-Conditions: string has been defined elsewhere
 * ** Post-Conditions: Returns true if its a valid filename, false
 * ** otherwise.
 * *********************************************************************/
bool file_exists(string);

/*********************************************************************
 * ** Description: Takes in string for a file output within function,
 * ** then returns that string (originally used to check if file existed
 * ** which is why its its own function)
 * ** Parameters: None. 
 * ** Pre-Conditions: None.
 * ** Post-Conditions: A string is returned to be used as an output
 * ** filename.
 * *********************************************************************/
string file_output_checker();

/*********************************************************************
 * ** Description: Takes in 2 cstrings from an array within a function,
 * ** and if both of those strings are filenames, returns true (they can
 * ** later be converted to cstrings and used as filenames)
 * ** Parameters: int, char**
 * ** Pre-Conditions: int and char** have been defined elsewhere.
 * ** Post-Conditions: Returns true if both cstrings are valid filenames,
 * ** false otherwise.
 * *********************************************************************/
bool file_input_checker(int, char**);

/*********************************************************************
 * ** Description: Goes through all of the spells in a spellbook and 
 * ** uses those to calculate the average success rate of the spellbook.
 * ** Parameters: spellbook
 * ** Pre-Conditions: Spellbook has been defined elsewhere
 * ** Post-Conditions: The average success rate is returned, to be assigned
 * ** to its corresponding value in the spellbook.
 * *********************************************************************/
float calculate_success(spellbook);

/*********************************************************************
 * ** Description: Acts as the main framework for getting wizard info,
 * ** hosts the login process and returns the wizar.
 * ** Parameters: char**, int
 * ** Pre-Conditions: char** and int have been defined elsewhere.
 * ** Post-Conditions: Wizard with corresponding information (or failed
 * ** information) is returned.
 * *********************************************************************/
wizard get_wizard_info(char**, int);

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
void get_spell_data(spell*, int, ifstream &);

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
void spell_master_list(spellbook*, spell*, int);

/*********************************************************************
 * ** Description: Populates an array of spellbooks with information
 * ** from the file. 
 * ** Parameters: spellbook*, int, ifstream &
 * ** Pre-Conditions: spellbook* and int have been defined elsewhere,
 * ** file is open.
 * ** Post-Conditions: spellbook* is filled with all of the information
 * ** from the file.
 * *********************************************************************/
void get_spellbook_data(spellbook*, int, ifstream &);

/*********************************************************************
 * ** Description: If the user is a student, removes all of the poision
 * ** and death spellbooks from the list.
 * ** Parameters: spellbook*, int &, string
 * ** Pre-Conditions: spellbook*, int &, and string have all been defined
 * ** elsewhere.
 * ** Post-Conditions: All spellbooks with poision and death are removed
 * ** from spellbook*.
 * *********************************************************************/
void make_spellbook_friendly(spellbook*, int &, string);

/*********************************************************************
 * ** Description: If the user is a student, removes all of the posion
 * ** and death spells from a list of spells.
 * ** Parameters: spell*, int &, string
 * ** Pre-Conditions: spell*, int &, and string have all been defined
 * ** elsewhere.
 * ** Post-Conditions: All spells with poison and death are removed from
 * ** spell*. 
 * *********************************************************************/
void make_spelllist_friendly(spell*, int &, string);

/*********************************************************************
 * ** Description: Sorts a list of spellbooks by their pages using a 
 * ** bubble sort.
 * ** Parameters: spellbook*, int
 * ** Pre-Conditions: spellbook* and int have been defined elsewhere.
 * ** Post-Conditions: spellbook* is now sorted, lowest to highest, by
 * ** number of pages.
 * *********************************************************************/
void sort_num_pages(spellbook*, int);

/*********************************************************************
 * ** Description: Sorts a list of spellbooks by their average success
 * ** rate. 
 * ** Parameters: spellbook*, int
 * ** Pre-Conditions: spellbook* and int have been defined elsewhere.
 * ** Post-Conditions: spellbook* is now sorted, lowest to highest, by
 * ** average success rate.
 * *********************************************************************/
void sort_avg_rate(spellbook*, int);

/*********************************************************************
 * ** Description: Sorts a list of spells by their effects.
 * ** Parameters: spell*, int
 * ** Pre-Conditions: spell* and int have been defined elsewhere.
 * ** Post-Conditions: spell* is now sorted by effect in this order:
 * ** bubble, memory loss, fire, poison, death
 * *********************************************************************/
void sort_by_effect(spell*, int);

/*********************************************************************
 * ** Description: Lets the user decide if they wanna output their sort-
 * ** by pages to the screen or to a file.
 * ** Parameters: spellbook*, int
 * ** Pre-Conditions: spellbook* and int have been declared elsewhere.
 * ** Post-Conditions: Sorted list of spellbooks is either printed to a
 * ** chosen file, or printed to the screen.
 * *********************************************************************/
void output_format_pages(spellbook*, int);

/*********************************************************************
 * ** Description: Lets the user decide if they wanna output their sort-
 * ** by effect to the screen or to a file.
 * ** Parameters: spell*, int
 * ** Pre-Conditions: spell* and int have been declared elsewhere.
 * ** Post-Conditions: Sorted list of spells is either printed to a
 * ** chosen file, or printed to the screen.
 * *********************************************************************/
void output_format_effect(spell*, int);

/*********************************************************************
 * ** Description: Lets the user decide if they wanna output their sort-
 * ** by avg success rate to the screen or to a file.
 * ** Parameters: spellbook*, int
 * ** Pre-Conditions: spellbook* and int have been declared elsewhere.
 * ** Post-Conditions: Sorted list of spellbooks is either printed to a
 * ** chosen file, or printed to the screen.
 * *********************************************************************/
void output_format_rate(spellbook*, int);

/*********************************************************************
 * ** Description: Lets the user choose which sorting option they want to
 * ** do, then calls the output format for that.
 * ** Parameters: spellbook*, spell*, int, int
 * ** Pre-Conditions: All above paramaters have been defined elsewhere.
 * ** Post-Conditions: Options are printed to the screen, user selects an
 * ** option for sorting/printing until they quit.
 * *********************************************************************/
void listing_choose_option(spellbook*, spell*, int, int);

/*********************************************************************
 * ** Description: Acts as main program base; sets up all of the major
 * ** arrays and opens the necessary files, then calls the listing_choose
 * ** option in order to actually cycle through (w/ a while loop)
 * ** Parameters: char**, int, char*
 * ** Pre-Conditions: char**, int, char* have all been defined elsewhere.
 * ** Post-Conditions: Program runs through until incorrect input in login,
 * ** or until user quits.
 * *********************************************************************/
bool prog_run(char**, int, char*);

