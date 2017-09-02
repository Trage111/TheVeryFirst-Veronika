// Spent: a lot
// Result: 3/31; wrong answers & runtime errors

#include <iostream>
using namespace std;

long int * shift (long int * array, long int size, long int offset) {
	
	if (offset == 0) {
		return array;
	}
	
	long int * arrayToReturn = new long int[size];
	
	if (offset > 0) {
		
		int j = 0;
		
		for (int i = offset - 1; i < size; i++, j++) {
			arrayToReturn[j] = array[i];
		}
		for (int i = 0; i < offset - 1; i ++, j++) {
			arrayToReturn[j] = array[i];
		}
	}
	else {
		int j = 0;
		
		for (int i = size - 1 + offset + 1; i < size; i++, j++) {
			arrayToReturn[j] = array[i];
		}
		for (int i = 0; i < size - 1 + offset + 1; i++, j++) {
			arrayToReturn[j] = array[i];
		}
	}
	
	
	return arrayToReturn;
}

int main() {
	
	long int N, K;
	cin >> N;
	long int * array = new long int [N];
	for (int i = 0; i < N; i++) {
		cin >> array[i];
	}
	cin >> K;
	
	array = shift(array, N, K);
	
	for (int i = 0; i < N; i++) {
		cout << array[i] << " ";
	}
	
	return 0;
}
