#include <iostream>
using namespace std;

void * invert(int * array, int size){
	
	for (int * i = array, * j = array + size - 1; i < j; i++, j--){
		swap(*i, *j);
	}
}

int main() {

	int N = 0;
	cin >> N;
	int * array = new int[N];
	for (int i = 0; i < N; i++){
		cin >> array[i];
	}

	invert(array, N);
	
	for (int i = 0; i < N; i++){
		cout << array[i] << " ";
	}
	
	delete [] array;

	return 0;
}
