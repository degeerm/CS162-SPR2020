#include "./student_db.h"

using namespace std;

int main(){
	int num_of_students;
	string filename = filename_checker();
	fstream f;
	f.open(filename.c_str());
	f >> num_of_students;
	student* sList = create_student_db(num_of_students);
	get_student_db_info(sList, num_of_students, f);
	f.close();
	fstream mf;
	mf.open("outputs.txt");
	mf << "SOR TBY LAST NAME RESULTS" << endl;
	sort_by_last_name(sList, num_of_students);
	output_func(sList, num_of_students,mf);
	mf << "SORT BY ID NUM RESULTS" <<endl;
	sort_by_id_num(sList, num_of_students);
	output_func(sList, num_of_students,mf);
	mf.close();
	
	delete_student_db_info(sList);
	return 0;
}
