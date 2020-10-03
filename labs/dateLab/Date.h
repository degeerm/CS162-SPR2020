#ifndef Date_H
#define Date_H

#include <iostream>
#include <string>
using namespace std;

class Date{
	private:
		int month;
		int day;
		int year;
	public:
		Date();
		Date(int,int,int);
		void print_date_short();
		void print_date_short_test();
		void print_date_long();
};

#endif
