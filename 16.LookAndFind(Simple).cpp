/*	status		time	ast.t.	memory

1 	OK 		0 	0.001 	1867776
2 	OK 		0 	0.001 	1867776
3 	OK 		0 	0.001 	1867776
4 	OK 		0 	0.001 	1867776
5 	OK 		0.002 	0.003 	1867776
6 	OK 		0.05 	0.052 	1867776
7 	OK 		2.291 	2.299 	2818048
8 	OK 		0 	0.001 	1867776 */


#include <iostream>
using namespace std;

bool search (int *array, int size, int value) {
	for (int i = 0; i < size; i++) {
		if (array[i] == value) {
			return true;
		}
	}
	return false;
}

void lookAndFind (int *arrayOne, int *arrayTwo, int sizeOne, int sizeTwo) {

	for (int j = 0; j < sizeTwo; j++) {
		cout << (search (arrayOne, sizeOne, arrayTwo[j]) ? "YES" : "NO") << endl;
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
