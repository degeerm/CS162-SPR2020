#include "./mult_div.h"

using namespace std;

bool is_valid_dimensions(char *m, char *n){	
	int rows = atoi(m);
	int cols = atoi(n);
	if (rows == 0 or cols == 0){
		return false;
	}
	return true;
}

char **create_blank_2d(int row, int col){
	char **a;
	a = new char*[row];
	for (int i = 0; i < row; i++){
		a[i] = new char [col];
	}
	return a;
}

void delete_table(mult_div_values** table, int rows){
	for (int i = 0; i < rows; i++){
		delete[] table[i];
	}
	delete[] table;
	table = NULL;
}

void delete_cstring(char** arg_list, int rows){
	for (int i = 0; i < rows; i++){
		delete[] arg_list[i];
	}
	delete [] arg_list;
	arg_list = NULL;
}

void reentering(char *c, string type){
	while (true){
		cin.clear();
		cout << "Please re-enter your " << type << endl;
		cin.getline(c, 255);
		if (atoi(c) != 0){
			return;
		}
	}
}

void row_col_input(char *m, char *n){
	if (!is_valid_dimensions(m,n)){
		if (atoi(m) == 0){
			reentering(m, "rows");
		}
	
		if (atoi(n) == 0){
			reentering(n, "columns");
		}
	}
}

mult_div_values** create_table(int m, int n){
	mult_div_values** table = new mult_div_values*[m];
	for (int i = 0; i < m; i++){
		table[i] = new mult_div_values[n];
	}
	return table;
}

void set_mult_values(mult_div_values **table, int m, int n){
	for (int r = 0; r < m; r++){
		for (int c = 0; c < n; c++){
			table[r][c].mult = (r+1)*(c+1);
		}
	}
}

void set_div_values(mult_div_values **table, int m, int n){
	for (int r = 0; r < m; r++){
		for (int c = 0; c < n; c++){
			table[r][c].div = ((r+1)*1.0)/(c+1);
		}
	}
}

void print_table(mult_div_values **table, int m, int n){
	cout << "Multiplication Table" << endl;
	for (int r = 0; r < m; r++){
		for (int c = 0; c < n; c++){
			cout << table[r][c].mult << "\t";
		}
		cout << endl;
	}

	cout << "Division Table" << endl;
	for (int r = 0; r < m; r++){
		for (int c = 0; c < n; c++){
			printf("%.2f", table[r][c].div);
			cout << "\t";
		}
		cout << endl;
	}
}

void prog_run(char ** argument_list, int rows, int cols){
	mult_div_values** table = create_table(rows,cols);
	set_mult_values(table, rows, cols);
	set_div_values(table, rows, cols);
	print_table(table, rows, cols);
	delete_table(table, rows);
}

void array_copy(char* og, char *ne){
	for (int i = 0; i < (sizeof(ne)); i++){
		og[i] = ne[i];
	}
}

void input_not_beginning(char** argument_list){
	char string1[5], string2[5];
	cin.ignore();
	cout << "Please enter your rows." << endl;
	cin.getline(string1, 5);
	cout << "Please enter your columns." << endl;
	cin.getline(string2,5);
	row_col_input(string1,string2);
	array_copy(argument_list[1], string1);
	array_copy(argument_list[2],string2);
}

void run_no_command(char ** argument_list, int rows, int cols){
	string user_response = "1";
	while (user_response.compare("1") == 0){
		cout << "\nWould you like to see another table? (1 for yes)" << endl;
		cin >> user_response;
		if (user_response == "1"){
			input_not_beginning(argument_list);
			int rows = atoi(argument_list[1]);
			int cols = atoi(argument_list[2]);
			prog_run(argument_list, rows, cols);	
		}
		else{
			return;
		}
	}
}

/*int main(int argc, char *argv[]){
	char** argument_list = create_blank_2d(3, 5); 
	for (int i = 0; i < (argc); i++){
		for (int j = 0; j < sizeof(argv[i]); j++){
			argument_list[i][j] = argv[i][j];
		}
	}
	row_col_input(argument_list[1],argument_list[2]);
	int rows = atoi(argument_list[1]);
	int cols = atoi(argument_list[2]);
	prog_run(argument_list, rows, cols);
	run_no_command(argument_list, rows, cols);
	delete_cstring(argument_list, rows);
	return 0;
}*/
