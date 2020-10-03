#include "Doctor.h"

using namespace std;

void printDocInfo(Doctor d){
	cout << "Doctor Speciality: " << d.get_speciality() << endl;
	cout << "Number of patients: " << d.get_npatients() << endl;
	cout << "Patient List: " << endl;
	for (int i = 0; i < d.get_npatients(); i++){
		cout << "Patient " << i << ": " << d.get_patient_info(i) << endl;
	}
}

int main(){
	Doctor d;
	string r;
	int n;
	cout << "What is this doctor's speciality?" << endl;
	cin >> r;
	d.change_speciality(r);
	cout << "How many patients does this doctor have?" << endl;
	cin >> n;
	for (int i =0; i < n; i++){
		cout << "For patient " << i << ", what is their name?" << endl;
		cin >> r;
		d.add_patient(r);
	}

	printDocInfo(d);
	return 0;
}
