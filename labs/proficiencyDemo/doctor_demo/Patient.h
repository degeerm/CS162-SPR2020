#ifndef Patient_H
#define Patient_H

#include <iostream>
#include <string>
using namespace std;

class Patient{
	private:
		string name;
	public:
		Patient();
		Patient(string);
		void change_name(string);
		string get_name();





};
#endif
