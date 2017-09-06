// spent: 30m
// result: OK

#include <iostream>
using namespace std;

bool isSym (int ** array, int members) {
	
	for (int i = 0; i < members; i++) {
		
		for (int j = members - 1; j >= 0; j--) {
			if (array[i][j] != array[j][i]) {
				return false;
			}
		}
	}
	
	return true;
}

int main() {
	
	int N;
	cin >> N;

	int ** table = new int * [N];
	
	for (int i = 0; i < N; i++) {
		
		table[i] = new int [N];
		
		for (int j = 0; j < N; j++) {
			
			cin >> table[i][j];
		}
	}
	
	isSym(table, N) ? cout << "yes" << : cout << "no"; cout << endl;
	
	delete [] table;
	
	return 0;
}
