#ifndef Pet_H
#define Pet_H

#include <iostream>
#include <string>
using namespace std;

class Pet{
	protected:
		string name;
		int weight;
	public:
		Pet();
		Pet(string, int);
		string get_name();
		int get_weight();
		void change_name(string);
		void change_weight(int);
		virtual string getLifespan();



};

#endif
