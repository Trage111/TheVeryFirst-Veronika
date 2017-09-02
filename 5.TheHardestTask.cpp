// result: OK O_o
// but i've spent 3 hours (is it really very bad?) and still have a feeling there must be a simpler solution

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	
	int n;
	cin >> n;
	
	int size = 2 * n + 1;
	
	int array [size][size];
	
	int x = size / 2;
	int y = size / 2;
	array[x][y] = 0;
	
	int shiftx = 0;
	int shifty = 0;
	int circle = 1;
	
	for (int i = 1; i < size * size;) {
		
		shiftx--;
		array[x+shiftx][y+shifty] = i;
		i++;

		for (int j = 0; j < (circle * 2) - 1 && i < size * size; j++) {
			shifty--;
			array[x+shiftx][y+shifty] = i;
			i++;
		}

		for (int j = 0; j < circle * 2 && i < size * size; j++) {
			shiftx++;
			array[x+shiftx][y+shifty] = i;
			i++;
		}
		
		for (int j = 0; j < circle * 2 && i < size * size; j++) {
			shifty++;
			array[x+shiftx][y+shifty] = i;
			i++;
		}
		
		for (int j = 0; j < circle * 2 && i < size * size; j++) {
			shiftx--;
			array[x+shiftx][y+shifty] = i;
			i++;
		}
		
		circle++;
	
	}
		
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << setw(3) << array[i][j];
		}
		cout << endl;
	}
	
	return 0;
}
