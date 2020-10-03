#include "Rectangle.h"

using namespace std;
Rectangle::Rectangle(){
	width = 1;
	height = 1;
	change_name("Generic Rectangle");
}

Rectangle::Rectangle(float w, float h){
	try{
		width = w;
		height = h;
		change_name("Generic Rectangle");
		if (w <=0 || h <= 0){
			throw invalid_argument("Invalid constructor argument");
		}
	}catch (exception &x){
		cout << "An exception was raised! " << endl;
		cout << "It was caught! " << endl;
		cout << "What() message: " << x.what() << endl;
	}
}
		
float Rectangle::area() const{
	return (width * height);
}

float Rectangle::get_width(){
	return (width);
}

float Rectangle::get_height(){
	return (height);
}

void Rectangle::change_width(float w){
	width = w;
}

void Rectangle::change_height(float h){
	height = h;
}

bool operator> (const Rectangle& r1, const Rectangle& r2){
	if ((r1.area()) > (r2.area())){	
		return true;
	}
	return false;
}

void Rectangle::print_shape_info(Shape &){
	cout << "Name: " << get_name() << endl;
	cout << "Width: " << width << endl;
	cout << "Height: " << height << endl;
	cout << "Area: " << area() << endl;

}

bool operator< (const Rectangle& r1, const Rectangle& r2){
	if ((r1.area()) < (r2.area())){
		return true;
	}
	return false;
}

