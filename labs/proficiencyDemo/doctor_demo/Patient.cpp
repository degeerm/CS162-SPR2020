#include "Patient.h"

using namespace std;

Patient::Patient(){
	name = "Default";
}

Patient::Patient(string n){
	name = n;
}

void Patient::change_name(string n){
	name = n;
}

string Patient::get_name(){
	return name;
}
