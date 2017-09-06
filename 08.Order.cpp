// Spent: 5 min

#include <iostream>
using namespace std;

void order (int &x, int &y) {
	
	if (x > y) {
		y += x;
		x = (y - x);
		y -= x;
	}
}

void order (int &x, int &y, int &z) {
	
	order (x, y);
	order (y, z);
	order (x, y);
}

int main() {
	
	int x, y, z;
	
	cin >> x >> y >> z;
	
	order(x, y, z);
	
	cout << x << " " << y << " " << z << endl;
	
	return 0;
}
