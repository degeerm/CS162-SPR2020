#include "Square.h"

using namespace std;

Square::Square(){
	change_width(1);
	change_height(1);
	change_name("Generic Square");
}

Square::Square(int b){
	try{
		change_height(b);
		change_width(b);
		change_name("Generic Square");
		if (b == 0){
			throw invalid_argument("Invalid constructor argument");
		}
	}catch (exception &x){
		cout << "An exception was raised! " << endl;
		cout << "It was caught! " << endl;
		cout << "What() message: " << x.what() << endl;
	}

}

void Square::print_shape_info(Shape &s){
	cout << "Name: " << get_name() << endl;
	cout << "Sides: " << get_width() << endl;

}
