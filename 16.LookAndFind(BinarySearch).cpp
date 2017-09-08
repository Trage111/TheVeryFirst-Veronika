/*	status		time	ast.t.	memory
1 	OK		0 	0.001 	1871872
2 	OK 		0 	0.001 	1871872
3 	OK 		0 	0.001 	1871872
4 	OK 		0 	0.001 	1871872
5 	OK 		0.002 	0.004 	1871872
6 	OK 		0.022 	0.023 	1871872
7 	OK 		0.181 	0.182 	2822144
8 	OK 		0 	0.001 	1871872 */

#include <iostream>
using namespace std;

bool search (const int *array, int left, int right, const int value) {
	
	if (right - left <= 1) {
		if (array[left] == value || array[right] == value) {
			return true;
		}
		else {
			return false;
		}
	}
	
	
	else {
		int middle = (left + right) / 2;
		if (value > array[middle]) {
			search (array, middle, right, value);
		}
		else if (value < array[size / 2]){
			search (array, left, middle, value);
		}
		else {
			return true;
		}
	}
	
}

void lookAndFind (const int *arrayOne, const int *arrayTwo, int sizeOne, int sizeTwo) {
	
	for (int i = 0; i < sizeTwo; i++) {
		if (search(arrayOne, 0, sizeOne - 1, arrayTwo[i])) {
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
