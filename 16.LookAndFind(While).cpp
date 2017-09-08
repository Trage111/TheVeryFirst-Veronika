/*	status		time	ast.t.	memory
1 	OK 		0 	0.002 	1867776
2 	OK 		0 	0.001 	1867776
3 	OK 		0 	0.001 	1867776
4 	OK 		0 	0.001 	1867776
5 	OK 		0.001 	0.002 	1867776
6 	OK 		0.022 	0.023 	1867776
7 	OK 		0.257 	0.259 	2818048
8 	OK 		0 	0.001 	1867776 */


#include <iostream>
using namespace std;

bool binSearch (int *array, int size, const int value) {
	while (size > 1) {
		
		int middle = size / 2;
		
		if(value > array[middle]) {
			array += middle;
			size -= middle;
		}
		else if(value < array[middle]) {
			size -= middle;
		}
		else {
			return true;
		}
	}

	return array[0] == value;
}

void lookAndFind (int *arrayOne, int *arrayTwo, int sizeOne, int sizeTwo) {

	for (int j = 0; j < sizeTwo; j++) {
		cout << (binSearch (arrayOne, sizeOne, arrayTwo[j]) ? "YES" : "NO") << endl;
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

