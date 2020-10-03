#include "arrayFunc.h"

using namespace std;

int main(){
	//size input checker + array creation
	int n = check_input_array();
	int* n_array = create_array(n);

	//filling array with random numbers b/w 1 and 100
	fill_array(n, n_array);
	cout << "\nUnsorted Array: " << endl;
	print_array(n, n_array);
	
	cout << "\nSorted Array: " << endl;

	//sorting first array(insertion sort)
	int* sorted_array = sort_array(n, n_array);
	print_array(n, sorted_array);	

	//print primes
	print_prime(n, sorted_array);

	//deleting arrays
	delete_array(n_array);
	delete_array(sorted_array);
	return 0;
}
