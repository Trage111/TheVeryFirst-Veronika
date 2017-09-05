// spent: about 40 min
// status: OK

#include <iostream>
#include "math.h"
using namespace std;

struct Point {
	int x;
	int y;
};

float Interval (Point a, Point b) {
	return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

float triangleSquare (Point a, Point b, Point c) {
	
	float sideAB = Interval(a, b);
	float sideBC = Interval(b, c);
	float sideAC = Interval(a, c);
	
	float p = (sideAB + sideBC + sideAC) / 2;
	
	return sqrt(p * (p - sideAB) * (p - sideBC) * (p - sideAC));
}

float maxTriangleSquare (Point * array, int size) {
	float maxSquare = 0;
	
	for (int i = 0; i < size - 2; i++) {
		for (int j = i + 1; j < size - 1; j++) {
			for (int k = j + 1; k < size; k++) {
				if (triangleSquare(array[i],array[j],array[k]) > maxSquare) {
					maxSquare = triangleSquare(array[i],array[j],array[k]);
				}
			}
		}
	}
	
	return maxSquare;
}

int main() {
	
	int num;
	cin >> num;
	Point * array = new Point[num];
	
	for (int i = 0; i < num; i++) {
		cin >> array[i].x >> array[i].y;
	}
	
	cout << maxTriangleSquare(array, num);

	delete[] array;

	return 0;
}
