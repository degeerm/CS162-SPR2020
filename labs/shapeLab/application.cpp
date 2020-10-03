#include "Rectangle.h"
#include "Circle.h"
#include "Square.h"
#include <vector>
using namespace std;

int main(){	
	cout << "\n\n--Rectangle Test--" << endl;
	Rectangle r1;
	Rectangle r2 = Rectangle(4,5);
	r2.change_name("New Rectangle");
	r2.change_color("Blue");
	cout << "\nDefault Rectangle Information: " << endl;
	r1.print_shape_info(r1);

	cout << "\nNew Rectangle Information: " << endl;
	r2.print_shape_info(r2);
	
	cout << "\nComparing the two: " << endl;
	if (r1 > r2){
		cout << r1.get_name() << " has greater area." << endl;
	}else if (r2 > r1){
		cout << r2.get_name() << " has greater area." << endl;
	}

	cout << "\n\n--Circle Test--" << endl;
	Circle c1;
	Circle c2 = Circle(3);
	c2.change_name("New Circle");
	c2.change_color("Blue");

	cout << "\nDefault circle information: " << endl;
	c1.print_shape_info(c1);

	cout << "\nNew Circle Information: " << endl;
	c2.print_shape_info(c2);
	
	cout << "\n\n--Square Test--" << endl;
	Square s1;
	Square s2 = Square(6);
	s2.change_name("New Square");
	s2.change_color("Green");
	
	cout << "\nDefault Square information: " << endl;
	s1.print_shape_info(s1);
	
	cout << "\nAlternate Square Information " << endl;
	s2.print_shape_info(s2);

	cout << "\nComparing the Two: " << endl;
	if (s1 > s2){
		cout << s1.get_name() <<" has greater area.\n" << endl;
	}else if (s2 > s1){
		cout << s2.get_name() <<" has greater area.\n" << endl;
	}

	cout << "\nError Handling Test: " << endl;
	Rectangle r3 = Rectangle(0,2);
	Circle c3 = Circle(0);
	Square s3 = Square(0);

	cout << "****************************" << endl;
	Shape* rr = new Rectangle(3,4);
	vector<Shape* > v1;
	v1.push_back(rr);
	rr = new Circle(3);
	v1.push_back(rr);
	rr = new Square(6);
	v1.push_back(rr);


	cout << "\nPrint all shape info" << endl;
	for (int i = 0; i < v1.size(); i++){
		v1[i] -> print_shape_info(*v1[i]);	
	}
	return 0;
}
