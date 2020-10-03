#include "Pet.h"


using namespace std;


Pet::Pet(){
	name = "Pet";
	weight = 0;
}

Pet::Pet(string n, int w){
	name = n;
	weight = w;
}

string Pet::get_name(){
	return name;
}

int Pet::get_weight(){
	return weight;
}

void Pet::change_name(string n){
	name = n;
}

void Pet::change_weight(int w){
	weight = w;
}

string Pet::getLifespan(){
	return ("Unknown Lifespan");
}
