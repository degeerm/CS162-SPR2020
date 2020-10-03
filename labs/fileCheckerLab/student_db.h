#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

struct student{
	int idNum;
	string firstName;
	string lastName;
	string major;
};

student* create_student_db(int);
void get_student_db_info(student*, int, fstream &);
void delete_student_db_info(student*);
string filename_checker();
void sort_by_last_name(student*, int);
void sort_by_id_num(student*, int);
void output_func(student*, int, fstream &);


