// Spent: a lot and even more
// Result: 23/31 - OK, the rest - timeout reached (I realize that this code is time consuming)

#include <iostream>
using namespace std;

void swap (long int &a, long int &b) {
	long int tmp = a;
	a = b;
	b = tmp;
}

void shift (long int * array, long int size, long int offset) {
	
	if (offset > 0) {
		
		for (long int j = offset; j > 0; j--) {
		
			long int tmp = array[0];
		
			for (long int i = 1; i < size; i++) {
			
				swap(array[i], tmp);		
			}
				
			swap(array[0], tmp);
		}
	}
	
	if (offset < 0) {
		
		for (long int j = offset; j < 0; j++) {
		
			long int tmp = array[size - 1];
		
			for (long int i = size - 2; i >= 0; i--) {
				
				swap(array[i], tmp);	
			}
					
			swap(array[size - 1], tmp);			
		}
	}	
}

int main() {
	
	long int N, K;
	cin >> N;
	long int * array = new long int [N];
	for (long int i = 0; i < N; i++) {
		cin >> array[i];
	}
	cin >> K;
	
	
	shift(array, N, K);
	
	for (long int i = 0; i < N; i++) {
		cout << array[i] << " ";
	}
	
	return 0;
}
