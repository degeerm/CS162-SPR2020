#include "./student_db.h"
using namespace std;
student* create_student_db(int num){
		student* sList =new student[num];
		return sList;
}

void get_student_db_info(student* slist, int num, fstream &f){
	for (int i = 0;i < num; i++){
		f >> slist[i].idNum;
		f >> slist[i].firstName;
		f >> slist[i].lastName;
		f >> slist[i].major;
	}
}

void delete_student_db_info(student* sList){
		delete[] sList;
}

string filename_checker(){
	string filename;
	while (true){
		cout << "Please enter a filename to input from." << endl;
		cin >> filename;
		ifstream ifile;
		ifile.open(filename.c_str());
		bool file_exists = ifile;
		if (!file_exists){
				cout << "Error: Please enter a valid filename." << endl;
		}else{
			ifile.close();
			return filename;
		}
	}
}

void sort_by_last_name(student* sList, int num){
	for (int i = 0; i < num-1; i++){
		for (int j=0; j < num-i-1; j++){
			if (sList[j].lastName > (sList[j+1].lastName) > 0){
				student temp = sList[j];
				sList[j] = sList[j+1];
				sList[j+1] = temp;
			}
		}
	}
}


void sort_by_id_num(student* sList, int num){
	for (int i = 0; i < num-1; i++){
		for (int j=0; j < num-i-1; j++){
			if (sList[j].idNum > sList[j+1].idNum){
				student temp = sList[j];
				sList[j] = sList[j+1];
				sList[j+1] = temp;
			}
		}
	}
}

void output_func(student* sList, int num, fstream &f){
	for (int i = 0; i < num; i++){
		f << sList[i].idNum << " ";
		f << sList[i].firstName << " ";
		f << sList[i].lastName << " ";
		f << sList[i].major << " ";
		f << endl;
	}
}

