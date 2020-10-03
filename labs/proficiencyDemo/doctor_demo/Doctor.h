#ifndef Doctor_H
#define Doctor_H
#include "Patient.h"
using namespace std;

class Doctor{
	private:
		string speciality;
		int n_patients;
		Patient* p_list;
	public:
		Doctor();
		~Doctor();
		Doctor(const Doctor&);
		Doctor& operator= (const Doctor&);
		Doctor(string, int);
		int get_npatients();
		string get_speciality();
		void change_speciality(string);
		void change_npatients(int);
		void add_patient(string);
		string get_patient_info(int);
};


#endif
