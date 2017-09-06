// result: 1/21
// no idea what's wrong, all my own tests were OK


#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;


int digSum (int dig) {
	
	int sum = 0;
	while(dig) {
		sum += dig % 10;
		dig /= 10;
	}
	
	return sum;
}

bool comp (int a, int b) {
	return digSum(a) > digSum(b);
}

int main() {
	
	int size;
	cin >> size;
	
	int * array = new int[size];
	
	for (int i = 0; i < size; i++) {
		cin >> array[i];
	}
	
	sort(array, array + size, comp);
	
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	
}
