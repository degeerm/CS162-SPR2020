#include <stdlib.h>
#include <stdexcept>

//using std::cout;
//using std::endl;
template <class T>
class vector {
	private:
		T *v;
		int s;
		int c;
	public:
		vector(){
		     s=0;
		     v=NULL;
		     c = 100;
		}

		vector(int cap){
			c = cap;
			s = 0;
			v = NULL;
		}

		~vector(){
		     delete [] v;
		}

		int size() {
		     return s;
		}

		int get_capacity(){
			return c;
		}

		void push_back(T e) {
		     T *temp;
		     if (s == c){
			     c*=2;
		     } 
		     s++;
		     temp = new T[c];
		     for(int i=0; i<s-1; i++){
			temp[i]=v[i];
	    	     }
		     
		     delete [] v;
		     v=temp;
		     v[s-1]=e;
		}

		vector(vector<T> &other){
			s = other.s;
			c = other.c;
			v = new T[c];
			for (int i = 0; i < s; i++){
				v[i] = other.v[i];
			}
		}

		void operator=(vector<T> &other){
			s = other.s;
			c = other.c;
			delete [] v;
			v = new T[c];
			for (int i = 0; i < s; i++){
				v[i] = other.v[i];
			}	
		}

		T operator[](int i){
			return v[i];
		}

		T at(int i){
			try{
               			if (i<0 || i > c){
					throw std::out_of_range("Index out of bounds");
						               }
		         	else{
					return v[i];
				}
			}
			catch(const std::out_of_range &error){
				//cout << error.what() << endl;
				return -1;
			}
       		}

		void resize(int n){
			T* temp = new T[n];
			int i;
			if (n >= s){
				i = s;
			}else if (n < s){
				i = n;
			}
			for (int j= 0; j < i; j++){
				temp[j] = v[j];
			}
			s = n;
			//c = s*2;
			delete[]v;
			v = temp;
		}
		
};
