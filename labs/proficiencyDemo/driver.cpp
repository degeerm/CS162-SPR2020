#include "Dog.h"

using namespace std;

int main(){
	string r;
	int r2;
	Pet p;
	cout << "Enter the name of this pet." << endl;
	cin >> r;
	p.change_name(r);
	cout << "Enter the weight of this pet." << endl;
	cin >> r2;
	p.change_weight(r2);
	cout << "Name: " << p.get_name() << endl;
	cout << "Weight: " << p.get_weight() << endl;
	cout << p.getLifespan() << endl;

	cout << "How many dogs do you want? " << endl;
	cin >> r2;
	Dog* dogArray = new Dog[r2];
	for (int i = 0; i < r2; i++){
		Dog d;
		int r3;
		cout << i << ") Whats the dogs name?" << endl;
		cin >> r;
		d.change_name(r);
		cout << "Weight? " << endl;
		cin >> r3;
		d.change_weight(r3);
		cout << "breed? " << endl;
		cin >> r;
		d.change_breed(r);
		dogArray[i] = d;
	}

	for (int i = 0; i < r2; i++){
		cout << dogArray[i].getLifespan() << endl;
	}

	delete [] dogArray;


	return 0;
}
