#ifndef Circle_H
#define Circle_H
#include "Shape.h"

using namespace std;
class Circle : public Shape {
	private:
		float radius;
	public:
		Circle();
		Circle(float);
		float area() const;
		float get_radius();
		void print_shape_info(Shape &);
};

#endif
