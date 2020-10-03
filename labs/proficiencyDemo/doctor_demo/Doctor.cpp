#include "Doctor.h"

using namespace std;

Doctor::Doctor(){
	speciality = "Doctor";
	n_patients = 0;
	p_list = new Patient[n_patients];
}

Doctor::Doctor(string n, int number){
	speciality = n;
	n_patients = number;
	this->p_list = new Patient[number];
}

Doctor::~Doctor(){
	delete[] p_list;
}

Doctor::Doctor(const Doctor& d){
	this->speciality = d.speciality;
	this->n_patients = d.n_patients;
	p_list = new Patient[n_patients];
	for (int i = 0; i < n_patients; i++){
		p_list[i] = d.p_list[i];
	}
}

Doctor& Doctor::operator= (const Doctor& d){
	this->speciality = d.speciality;
	this->n_patients = d.n_patients;
	p_list = new Patient[n_patients];
	for (int i = 0; i < n_patients; i++){
		p_list[i] = d.p_list[i];
	}

	return *this;
}

int Doctor::get_npatients(){
	return n_patients;
}

void Doctor::add_patient(string n){
	Patient* templist = new Patient[++n_patients];
	for (int i = 0; i < (n_patients-1);i++){
		templist[i] = p_list[i];
	}
	delete[] p_list;
	p_list = templist;
	Patient p(n);
	p_list[n_patients-1] = p;
}

string Doctor::get_speciality(){
	return speciality;
}

void Doctor::change_speciality(string s){
	speciality = s;
}

void Doctor::change_npatients(int n){
	n_patients = n;
}

string Doctor::get_patient_info(int i){
	return p_list[i].get_name();
}
