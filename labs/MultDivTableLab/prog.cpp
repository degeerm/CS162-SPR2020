#include "./mult_div.h"
using namespace std;

int main(int argc, char *argv[]){
	char** argument_list = create_blank_2d(3, 5); 
	for (int i = 0; i < (argc); i++){
		for (int j = 0; j < sizeof(argv[i]); j++){
			strcpy(argument_list[i], argv[i]);
		}
	}
	row_col_input(argument_list[1],argument_list[2]);
	int rows = atoi(argument_list[1]);
	int cols = atoi(argument_list[2]);
	prog_run(argument_list, rows, cols);
	run_no_command(argument_list, rows, cols);
	delete_cstring(argument_list, 3);
	return 0;
}
