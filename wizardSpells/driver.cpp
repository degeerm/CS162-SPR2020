#include "./wizard_db.h"

using namespace std;

//Main function: takes in two paramters (the wizard file and the
//spellbooks file). Does the conversions on those, then runs the
//program using prog_run.
int main(int argc, char *argv[]){	
	char** argument_list = create_cstring(argc, 256); 
	for (int i = 0; i < (argc); i++){
		for (int j = 0; j < sizeof(argv[i]); j++){
			strcpy(argument_list[i], argv[i]);
		}
	}
	if (!file_input_checker(argc, argument_list)){
		return 0;
	}
	char wizard_file[strlen(argument_list[1])];
	char spellbook_file[strlen(argument_list[2])];
	strcpy(wizard_file, argument_list[1]);
	strcpy(spellbook_file, argument_list[2]);
	if(!prog_run(argument_list, argc, spellbook_file)){
		delete_cstring(argument_list, argc);
	}

	return 0;
}
