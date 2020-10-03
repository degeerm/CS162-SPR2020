#ifndef Rectangle_H
#define Rectangle_H

#include "Shape.h"

using namespace std;

class Rectangle : public Shape {
	private:
		float width;
		float height;
	public:
		Rectangle();
		Rectangle(float, float);
		float area() const;
		float get_width();
		float get_height();
		void change_width(float);
		void change_height(float);
		void print_shape_info(Shape &);
		friend bool operator> (const Rectangle &, const Rectangle &);
		friend bool operator< (const Rectangle &, const Rectangle &);
};

#endif
