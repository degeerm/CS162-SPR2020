#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <string>
struct mult_div_values{
	int mult;
	float div;
};

bool is_valid_dimensions(char *, char *);
char **create_blank_2d(int, int);
mult_div_values** create_table(int, int);
void delete_table(mult_div_values**, int);
void delete_cstring(char **, int);
void reentering(char *, std::string);
void row_col_input(char *, char *);
void set_mult_values(mult_div_values **, int, int);
void set_div_values(mult_div_values **, int, int);
void print_table(mult_div_values **, int, int);
void prog_run(char **, int, int);
void array_copy(char *, char *);
void input_not_beginning(char **);
void run_no_command(char **, int, int);
