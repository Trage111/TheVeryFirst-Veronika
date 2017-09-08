// not very clever of me but I've written this instead of what I'm supposed to write (I should have read the task more attentively)
// this code converts decimal numbers to binary numbers and counts the sum of their digits
// and sorts the decimal numbers basing on this sum
// spent more than an hour writing this :/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int decToBin (int dec) {
	
	int bin = 0;
	for (int i = 0, power = 1; dec; i++, power *= 10) {
		bin += (dec % 2) * power;
		dec /= 2;
	}
	
	return bin;
}

int digSum (int dig) {
	
	int sum = 0;
	while(dig) {
		sum += dig % 10;
		dig /= 10;
	}
	
	return sum;
}

bool comp (int a, int b) {
	return digSum(decToBin(a)) > digSum(decToBin(b));
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
	
	delete[] array;
	return 0;
	
}
