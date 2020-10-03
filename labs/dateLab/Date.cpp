#include "Date.h"

using namespace std;

Date::Date(){
	month = 1;
	day = 1;
	year = 2001;
}

Date::Date(int m,int d,int y){
	month = m;
	day = d;
	year = y;

}

void Date::print_date_short_test(){
	//string year_string = to_string(year);
	//cout << month << "/" << day << "/" << year_string.at(year_string.length()-2);
	//cout << year_string.at(year_string.length()-1) << endl;
}

void Date::print_date_short(){
	int digit_one = year % 10;
	int a = year - digit_one;
	int b = a  % 100;
	int digit_two = b/10;

	cout << month << "/" << day << "/" << digit_two << digit_one << endl;

}

void Date::print_date_long(){
	string months;
	if (month == 1){
		months = "January";
	}else if(month == 2){
		months = "February";
	}else if (month ==3){
		months = "March";
	}else if(month == 4){
		months = "April";
	}else if(month == 5){
		months = "May";
	}else if(month == 6){
		months = "June";
	}else if (month == 7){
		months = "July";
	}else if (month ==8){
		months = "August";
	}else if (month == 9){
		months = "September";
	}else if (month == 10){
		months = "October";
	}else if (month == 11){
		months = "November";
	}else if (month == 12){
		months = "December";
	}
	cout << months << " " << day << ", " << year << endl;

}
