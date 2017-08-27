// Spent: 20m
// Result: OK

#include <iostream>
using namespace std;

int * invert(int * array, int size){
	
	for (int i = 0, j = size - 1; i < size / 2; i++, j--){
	
		array[i]+=array[j];
		array[j]=(array[i]-array[j]);
		array[i]-=array[j];
	}
	
	return array;
}

int main() {

	int N = 0;
	cin >> N;
	int * array = new int[N];
	for (int i = 0; i < N; i++){
		cin >> array[i];
	}

	array = invert(array, N);
	
	for (int i = 0; i < N; i++){
		cout << array[i] << " ";
	}

	return 0;
}
