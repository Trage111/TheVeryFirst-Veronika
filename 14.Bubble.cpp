// spent: about 15 min
// result: OK

#include <iostream>
using namespace std;

int main() {
	
	int size;
	cin >> size;
	int * array = new int[size];
	
	for (int i = 0; i < size; i++) {
		cin >> array[i];
	}
	

	for (int i = 0; i < size; i ++) {
		bool end = true;
		for (int j = 0; j < size - i - 1; j++) {
			if (array[j] > array[j+1]) {
				swap(array[j], array[j+1]);
				end = false;
			}
		}
		if(end) {
			break;
		}
		end = true;
	}
	
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	
	cout << endl;
	
	delete[] array;
	
	return 0;
}
