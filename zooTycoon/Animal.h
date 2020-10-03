#ifndef Animal_H
#define Animal_H
#include <iostream>

using namespace std;

class Animal{
	protected:
		int revenue;
		int cost;
		int babies;
		int food_cost;
		int age;
	public:
		Animal();
		int get_food_cost();
		int get_babies();
		int get_age();
		int get_cost();
		int get_revenue();
		void change_revenue();
		void change_food_cost(float);
		void change_age();
		int get_sick_cost();

};

#endif
