#ifndef Square_H
#define Square_H
#include "Rectangle.h"

using namespace std;

class Square : public Rectangle {
	public:
		Square();
		Square(int);
		float area();
		void print_shape_info(Shape &);
};

#endif
