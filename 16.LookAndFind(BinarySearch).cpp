/* 	status 		time	ast.t. 	memory

1 	OK 		0 	0.001 	1867776
2 	OK 		0 	0.001 	1867776
3 	OK 		0 	0.001 	1867776
4 	OK 		0 	0.001 	1867776
5 	OK 		0.001 	0.002 	1867776
6 	OK 		0.022 	0.023 	1867776
7 	OK 		0.265 	0.267 	2818048
8 	OK 		0 	0.001 	1867776 */


#include <iostream>
using namespace std;

bool search (const int *array, int size, const int value) {
	
	if (size == 1) {
		if (array[0] == value) {
			return true;
		}
		else {
			return false;
		}
	}
	
	
	else {
		if (value > array[size / 2]) {
			size % 2 ? search (array + size / 2 + 1, size / 2, value) : search (array + size / 2, size / 2, value);
		}
		else if (value < array[size / 2]){
			search (array, size / 2, value);
		}
		else {
			return true;
		}
	}
	
}

void lookAndFind (const int *arrayOne, const int *arrayTwo, int sizeOne, int sizeTwo) {
	
	for (int i = 0; i < sizeTwo; i++) {
		if (search(arrayOne, sizeOne, arrayTwo[i])) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}

int main() {
	
	int N, K;
	cin >> N >> K;
	int * arrayOne = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arrayOne[i];
	}
	int * arrayTwo = new int[K];
	for (int i = 0; i < K; i++) { 
		cin >> arrayTwo[i];
	}
	
	lookAndFind(arrayOne, arrayTwo, N, K);
	
	return 0;
}
