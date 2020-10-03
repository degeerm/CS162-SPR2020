#include "Shape.h"

using namespace std;

Shape::Shape(){
	color = "Clear";
	name = "Generic Shape";
}

Shape::Shape(string c, string n){
	color = c;
	name = n;
}


/*void Shape::print_shape_info(Shape &a){
	cout << "Shape name: " << name  << endl;
	cout << "Shape color: " << color << endl;
	cout << "Shape area: " << area() << endl;
}*/

string Shape::get_color(){
	return color;
}

string Shape::get_name(){
	return name;
}

void Shape::change_color(string c){
	color = c;
}

void Shape::change_name(string n){
	name = n;
}
