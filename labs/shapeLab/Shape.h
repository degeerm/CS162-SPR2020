#ifndef Shape_H
#define Shape_H
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
class Shape {
	private:
		string name;
		string color;
	public:
		Shape();
		Shape(string, string);
		virtual float area() const = 0;
		string get_name();
		void change_name(string);
		string get_color();
		void change_color(string);
		virtual void print_shape_info(Shape &) = 0;
};

#endif
