#include "arrayFunc.h"

using namespace std;

bool is_int(string num){
	if (num.length() == 0){
		return false;
	}
	for (int i = 0; i < num.length(); i++){
		if ((int)num.at(i) < 48 or (int)num.at(i) > 57){
			return false;
		}
	}
	return true;
}


int get_int(string prompt){
	int sum = 0;
	int len = prompt.length();
	if (is_int(prompt)){
		for (int i = len-1; i >= 0; i--){
			char current = (int)prompt.at(i) - 48;
			sum += (current * pow(10,((len-1)-i)));
		}
	}else{
		return -1;
	}
	return sum;
}

int check_input_array(){
	string n;
	while (true){
		cout << "Please enter a number between 0 and 25 for your array size." << endl;
		cin >> n;
		if (is_int(n)){
			if (get_int(n) > 0 && get_int(n) <= 25){
				return get_int(n);
			}else{
				cout << "Error: Size can only be greater than 0 or less than/equal to 25." << endl;
			}
		}else{
			cout << "Error: Please only enter an integer." << endl;
		}	
	}
}

int* create_array(int n){
	int* array_new = new int[n];
	return array_new;
}

void delete_array(int* a){
	delete[] a;
}

int* create_copy(int s, const int* old_a){
	int* array_new = create_array(s);
	for (int i = 0; i < s; i++){
		array_new[i] = old_a[i];
	}
	return array_new;
}

void fill_array(int s, int* a){
	srand(time(NULL));
	int n;
	for (int i = 0; i < s; i++){
		n = rand() % 100 + 1;
		a[i] = n;	
	}
}

void print_array(int s, int* a){
	for (int i = 0; i < s; i++){
		cout << "Element " << i << ": " << a[i] << endl;
	}
}

int* sort_array(int s, const int* old_a){
	int* new_a = create_copy(s, old_a);
	int current;
	for (int i = 1; i < s; i++){
		current = new_a[i];
		int j = i - 1;
		while (j >= 0 && new_a[j] > current){
			new_a[j+1] = new_a[j];
			j--;
		}
		new_a[j+1] = current;
		
	}
	return new_a;
}

void print_prime(int s, int* a){
	for (int i = 0; i < s; i++){
		for (int j = 2; j <= a[i]; j++){
			if (j == a[i]){
				cout << "Prime number at spot " << i << ": " << a[i] << endl;
				break;
			}else if (a[i]%j == 0){
				break;
			}
		}
	}	
}
