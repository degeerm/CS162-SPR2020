#ifndef Dog_H
#define Dog_H

#include "Pet.h"

using namespace std;

class Dog : public Pet{
	private:
		string breed;
	public:
		Dog();
		Dog(string, int, string);
		string get_breed();
		void change_breed(string);
		string getLifespan();
};

#endif
