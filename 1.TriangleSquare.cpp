// spent: about 40 min
// status: OK

#include <iostream>
#include "math.h"
using namespace std;

struct Point {
	int x;
	int y;
};

double distance (Point a, Point b) {
	
	double dx = b.x - a.x;
	double dy = b.y - a.y;
	return sqrt(dx * dx + dy * dy);
}

double triangleSquare (double a, double b, double c) {
	
	double p = (a + b + c) / 2;
	
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

double maxTriangleSquare (Point * array, int size) {
	double maxSquare = 0;
	
	for (int i = 0; i < size - 2; i++) {
		for (int j = i + 1; j < size - 1; j++) {
			for (int k = j + 1; k < size; k++) {
				double sideAB = distance(array[i], array[j]);
				double sideBC = distance(array[j], array[k]);
				double sideAC = distance(array[i], array[k]);
				double square = triangleSquare(sideAB, sideBC, sideAC);
				if (square > maxSquare) {
					maxSquare = square;
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
