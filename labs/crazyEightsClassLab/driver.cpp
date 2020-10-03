#include "Hand.h"

using namespace std;

int main(){
	//ASSIGNMENT OPERATOR COPY HAND
	Hand h1;
	Hand h2;
	
	cout << "\n------ASSIGNMENT OPERATOR COPY HAND---------" << endl;
	h2 = Hand(3);

	Card c;
	c.init(3,3);
	h2.change_card(2, c);
	cout << "BEFORE ASSIGNMENT: \nh1" << endl;
	h1.print_hand();
	cout << "\nH2"<< endl;
	h2.print_hand();

	cout << "AFTER ASSIGNMENT: \nh1" << endl;
	h1 = h2;
	h1.print_hand();
	cout << "\nh2" <<endl;
	h2.print_hand();
	
	//COPY CONSTRUCTOR HAND
	cout << "\n\n\n-----------COPY CONSTRUCTOR HAND----------" << endl;
	cout << "\nBEFORE ASSIGNMENT: \nh2" << endl;
	h2.print_hand();
	
	cout << "AFTER ASSIGNMENT \nh2" << endl;
	Hand h3 = h2;
	h2.print_hand();
	cout << "\nh3(NEW)" << endl;
	h3.print_hand();

}
