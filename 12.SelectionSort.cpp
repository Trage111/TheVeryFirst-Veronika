// spent: about 15 min
// result: OK

#include <iostream>
using namespace std;

void selectionSort (int * array, int size) {
	
	for (int i = 0; i < size; i++) {
		int minNum = i;
		for (int j = i + 1; j < size; j++) {
			if (array[j] < array[minNum]) {
				minNum = j;
			}
		}
		swap(array[i], array[minNum]);
	}
} 

int main() {
	
	int s;
	cin >> s;
	int * array = new int[s];
	for (int i = 0; i < s; i++) {
		cin >> array[i];
	}
	selectionSort(array, s);
	
	for (int i = 0; i < s; i++) {
		cout << array[i]; i < s - 1 ? cout << " " : cout << "\n";
	}
	
	delete[] array;
	
	return 0;
}
