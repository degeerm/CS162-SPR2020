#include "./vector.hpp"
#include <vector>
#include <iostream>

//We do not want to include either statement. We wouldn't be able to compare our vector template to the Standard
//using namespace std;
//using std::vector;
using std::cout;
using std::endl;

int main (){
	vector<int> v(2);   //Our vector class
	std::vector<int> stdv; //Standard vector

	//Compare operation of our vector to std
	v.push_back(23);
	stdv.push_back(23);

	cout << "Our vector size: " << v.size() << endl;
	cout << "STL vector size: " << stdv.size() << endl;
	
	//copy constructor
	vector<int> v1 = v;

	cout << "\nCopy constructed vector size: " << v1.size() << endl;
	
	//assignment_operator_overload
	vector<int> v2(3);
	v2.push_back(3);
	v2.push_back(12);
	v2.push_back(5);
	cout << "\nOriginal vector size: " << v1.size() << endl;
	v1 = v2;
	cout << "After overload size: " << v1.size() << endl;

	//checking accessors
	v2.push_back(3);
	v2.push_back(7);
	v2.push_back(34);
	cout << "\nThird element (brackets): " << v2[2] << endl; 
	cout << "Second Element (at function): " << v2.at(1) << endl;
	cout << "50th Element (out of bounds): " << v2.at(50) << endl;

	vector<int>v3(4);
	
	cout << "\nOG Capacity: " << v3.get_capacity() << endl;
	cout << "OG Size: " << v3.size() << endl;
	v3.push_back(6);
	v3.push_back(7);
	v3.push_back(8);
	v3.push_back(9);
	v3.push_back(10);
	cout << "New Capcity: " << v3.get_capacity() << endl;
	cout << "New Size: " << v3.size() << endl;
	
	v3.resize(2);
	cout << "\nv3 resized size: " << v3.size() << endl;
	cout << "v3 resized capacity " << v3.get_capacity() << endl;
	cout << endl;
	return 0;
}
