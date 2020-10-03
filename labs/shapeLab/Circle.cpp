#include "Circle.h"

using namespace std;

Circle::Circle(){
	radius = 1;
	change_name("Generic Circle");
}
	

Circle::Circle(float r){
	try{
		radius = r;
		change_name("Generic Circle");
		if (r == 0){
			throw invalid_argument("Invalid constructor argument");
		}
	}catch (exception &x){
		cout << "An exception was raised! " << endl;
		cout << "It was caught! " << endl;
		cout << "What() message: " << x.what() << endl;
	}
}

float Circle::area() const{
	return (3.14 * (radius*radius));
}

float Circle::get_radius(){
	return radius;
}

void Circle::print_shape_info(Shape &){
	cout << "Name: " << get_name() << endl;
	cout << "Radius: " << radius << endl;
	cout << "Area: " << area() << endl;
}
