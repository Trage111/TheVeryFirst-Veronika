// spent: about 15 min
// result: OK

#include <iostream>
using namespace std;

void swap (int * x, int * y) {
	*y += *x;
	*x = *y - *x;
	*y -= *x;
}

void selectionSort (int * array, int size) {
	
	int minNum = 0;
	
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (array[j] < array[minNum]) {
				minNum = j;
			}
		}
		swap(array[i], array[minNum]);
		minNum = i + 1;
	}
} 

int main() {
	
	int s;
	cin >> s;
	int * array = new int [s];
	for (int i = 0; i < s; i++) {
		cin >> array[i];
	}
	selectionSort (array, s);
	
	for (int i = 0; i < s; i++) {
		cout << array[i]; i < s - 1 ? cout << " " : cout << "\n";
	}
	
	delete[] array;
	
	return 0;
}
