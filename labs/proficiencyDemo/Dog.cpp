#include "Dog.h"

using namespace std;

Dog::Dog(){
	name = "Dog";
	weight = 0;
	breed = "Golden Retriever";
}

Dog::Dog(string n, int w, string b){
	name = n;
	weight = w;
	breed = b;
}

string Dog::get_breed(){
	return breed;
}

void Dog::change_breed(string b){
	breed = b;
}

string Dog::getLifespan(){
	if (weight >= 100){
		return ("Approximately 7 years.");
	}else{
		return ("Approximately 13 years.");
	}
}
