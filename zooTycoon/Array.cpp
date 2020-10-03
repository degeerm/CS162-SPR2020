/*****************************************************
** Program Name: Array.cpp
** Author: Miya DeGeer
** Date: 05/10/2020
** Description: Template class to be used with SeaLion,
** Bear, and Tiger classes. Has functions for adding/removing
** elements, the big three, aging up animals, feeding animals,
** etc. Allows for same functions to be done on different animal
** lists because they all inherit from Animal.
** Input: int, type T, string
** Output: bool, int, float
******************************************************/

#include "Array.h"

using namespace std;

/*********************************************************************
 * ** Description: Default constructor for the Array<T> class. Sets size
 * ** to zero, and creates an array on the heap.
 * ** Parameters:  None.
 * ** Pre-Conditions: None.
 * ** Post-Conditions: An Array object is created.
 * *********************************************************************/
template <class T>
Array<T>::Array(){
	size = 0;
	array_ = new T[size];
}

/*********************************************************************
 * ** Description: Alternate constructor for Array<T> class. Sets size to
 * ** an inputted value, creates array on heap. 
 * ** Parameters: int
 * ** Pre-Conditions: int has been declared elsewhere. 
 * ** Post-Conditions:  An Array object with an array of size s is created.
 * *********************************************************************/
template<class T>
Array<T>::Array(int s){
	size = s;
	array_ = new T[size];
}

/*********************************************************************
 * ** Description: Destructor for the Array<T> object. Deletes the array
 * ** off of the heap. 
 * ** Parameters:  None.
 * ** Pre-Conditions:  Array has been declared.
 * ** Post-Conditions: Array object is destructed.
 * *********************************************************************/
template<class T>
Array<T>::~Array(){
	delete[] array_;
}

/*********************************************************************
 * ** Description: Copy constructor for the Array class. Copies values from
 * ** old object and creates new, stores there. 
 * ** Parameters: const Array&
 * ** Pre-Conditions: Old array has been declared elsewhere
 * ** Post-Conditions: Contents of copied array are put into created new
 * ** one.
 * *********************************************************************/
template<class T>
Array<T>::Array(const Array& a){
	size = a.size;
	array_ = new T[size];
	for (int i =0; i < size; i++){
		array_[i] = a.array_[i];
	}
}

/*********************************************************************
 * ** Description: Assignment operator overload for array class. Copies
 * ** info from one Array object to the other.
 * ** Parameters: const Array& a
 * ** Pre-Conditions: Old array has been declared elsewhere
 * ** Post-Conditions: Contents of old array put into this array.
 * *********************************************************************/
template<class T>
Array<T>& Array<T>::operator = (const Array& a){
	size = a.size;
	delete[] array_;
	array_ = new T[size];
	for (int i= 0; i < size; i++){
		array_[i] = a.array_[i];
	}
}

/*********************************************************************
 * ** Description: Returns the size of the array in the Array object.
 * ** Parameters:  None.
 * ** Pre-Conditions: Array object has been declared elsewhere.
 * ** Post-Conditions: Size is returned as an integer.
 * *********************************************************************/
template <class T>
int Array<T>::return_size(){
	return size;
}

/*********************************************************************
 * ** Description: Adds one animal to the array, increases size by 1. 
 * ** Parameters: T a.
 * ** Pre-Conditions: a and Array object have been declared elsewhere.
 * ** Post-Conditions: Animal given is added into the Array object.
 * *********************************************************************/
template<class T>
void Array<T>::add_one_animal(T a){
	size++;
	T* array_new = new T[size];
	for (int i = 0; i < size-1; i++){
		array_new[i]=array_[i];
	}
	delete[] array_;
	array_ = array_new;
	array_[size-1] = a;
}

/*********************************************************************
 * ** Description: counts the number of the adult animals in the Array
 * ** object.
 * ** Parameters: None. 
 * ** Pre-Conditions: Array object has been declared elsewhere.
 * ** Post-Conditions: Returns the number of adult animals in the array object.
 * *********************************************************************/
template<class T>
int Array<T>::count_adults(){
	int num =0;
	if (size != 0){
		for (int i = 0; i < size; i++){
			if (array_[i].get_age() >= 48){
				num++;
			}
		}
	}
	return num;
}

/*********************************************************************
 * ** Description: Counts the number of baby animals in the Array object.
 * ** Parameters: None.
 * ** Pre-Conditions: Array object has been declared elsewhere.
 * ** Post-Conditions: Returns the number of baby animals in the array object.
 * *********************************************************************/
template<class T>
int Array<T>::count_babies(){
	int num = 0;
	if (size !=0){
		for (int i = 0; i < size; i++){
			if (array_[i].get_age() < 6){
				num++;
			}
		}
	}
	return num;
}

/*********************************************************************
 * ** Description: Determines the amount of revenue the animals in the
 * ** array get.
 * ** Parameters: None. 
 * ** Pre-Conditions: Array object has been declared elsewhere.
 * ** Post-Conditions: Returns the amount of revenue as an integer.
 * *********************************************************************/
template<class T>
int Array<T>::revenue(){
	int bal = 0;
	int n = 0;
	for (int i = 0; i < size; i++){
		bal+= (array_[i].get_revenue());
	}
	return bal;
}

/*********************************************************************
 * ** Description: Randomly chooses an animal to get sick.
 * ** Parameters: None.
 * ** Pre-Conditions: Array object has been declared elsewhere, there's
 * ** at least one animal in the Array.
 * ** Post-Conditions: Returns the index of that animal becoming sick.
 * *********************************************************************/
template<class T>
int Array<T>::sick_overview(){
	srand(time(NULL));
	int r_num = rand() % size;
	return r_num;
}

/*********************************************************************
 * ** Description: Ages up all of the animals in the Array.
 * ** Parameters:  None.
 * ** Pre-Conditions: Array object has been declared elsewhere
 * ** Post-Conditions: All animals are 1 month older.
 * *********************************************************************/
template<class T>
void Array<T>::age_up(){
	for (int i = 0; i < size; i++){
		array_[i].change_age();
		if (array_[i].get_age() == 6){
			array_[i].change_revenue();
		}	
	}
}

/*********************************************************************
 * ** Description: Adds n animals to the array, returns the cost of
 * ** those animals.
 * ** Parameters: int
 * ** Pre-Conditions: int and Array have been declared elsewhere. 
 * ** Post-Conditions: Cost of n animals is returned.
 * *********************************************************************/
template<class T>
int Array<T>::buying_animals(int n, int b){
	int cost = 0;
	for (int i =0; i < n; i++){
		T t = T(48, b);
		add_one_animal(t);
		cost += t.get_cost();
	}
	return cost;
}

/*********************************************************************
 * ** Description: Calculates the cost of all of the animals in the array
 * ** for food.
 * ** Parameters: float 
 * ** Pre-Conditions: float and Array have been declared elsewhere.
 * ** Post-Conditions: Cost of all of the food is returned.
 * *********************************************************************/
template<class T>
int Array<T>::buy_food(float r){
	int cost = 0;
	for (int i = 0; i <size; i++){
		cost += array_[i].get_food_cost()* r;
	}
	return cost;
}

/*********************************************************************
 * ** Description: Changes all of the food costs to a new base cost.
 * ** Parameters: float
 * ** Pre-Conditions: float and Array have been declared elsewhere
 * ** Post-Conditions: Base cost of all the animals has been edited to
 * ** one that is 80%-120% of OG.
 * *********************************************************************/
template<class T>
void Array<T>::change_food_costs(float r_num){
	for (int i = 0; i <size; i++){
		array_[i].change_food_cost(r_num);	
	}
}

/*********************************************************************
 * ** Description: Returns one animal from the Array at spot n.
 * ** Parameters:  int
 * ** Pre-Conditions: int and Array have been declared elsewhere
 * ** Post-Conditions: Animal in array_ at index n is returned.
 * *********************************************************************/
template<class T>
T Array<T>::get_one_animal(int n){
	return (array_[n]);

}

/*********************************************************************
 * ** Description: Adds a proper number of baby animals to the Array
 * ** object. 
 * ** Parameters: None. 
 * ** Pre-Conditions: Array object has been declared elsewhere, has at 
 * ** least one animal in it.
 * ** Post-Conditions: Appropriate number of babies, depending on animal,
 * ** is added to the array.
 * *********************************************************************/
template<class T>
void Array<T>::baby_event(int b){
	int n = array_[0].get_babies();
	for (int i = 0; i < n; i++){
		T t = T(0, b);	
		add_one_animal(t);
	}
}

/*********************************************************************
 * ** Description: Removes an animal from the array (to be used when
 * ** an animal dies) 
 * ** Parameters: int
 * ** Pre-Conditions: int has been declared elsewhere, there is something
 * ** in array_ at index n 
 * ** Post-Conditions: Animal at index n is removed from array_, size
 * ** is substracted by 1
 * *********************************************************************/
template<class T>
void Array<T>::remove_one_animal(int n){
	T* new_t= new T[size - 1];
	int j = 0;
	for (int i = 0; i < size; i++){
		if (i != n){
			new_t[j] = array_[i];
			j++;
		}
	}
	size--;
	delete[] array_;
	array_ = new_t;
}
