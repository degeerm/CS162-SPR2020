#include "Date.h"

using namespace std;

int main(){
	Date d;
	cout << "DEFAULT CONSTRUCTOR " << endl;
	d.print_date_short();
	d.print_date_long();
	
	cout << "\nCONSTRUCTOR WITH PARAMETERS " << endl;
	Date d2(12,25,20123);
	d2.print_date_short();
	d2.print_date_long();
	return 0;
}
