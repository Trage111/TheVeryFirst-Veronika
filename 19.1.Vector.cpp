#include <iostream>
using namespace std;

enum TYPE {INT, CHAR};

class Vector {
	
public:
	Vector(TYPE t);
	~ Vector();
	void at(int index, int &value);
	void at(int index, char &value);
	void at(int index);
	bool empty();
	int size();
	void insert(int value, int index);
	void insert(char value, int index);
	void erase(int index);
	void erase(int index1, int index2);
	void push_back(int value);
	void push_back(char value);
	void pop_back();
	
private:
	TYPE type;
	int *arrayI;
	char *arrayC;
	int itsSize;
};

Vector::Vector(TYPE t): type(t), itsSize (0) {
	switch (type) {
		case INT: arrayI = new int[itsSize];
		arrayC = NULL;
		break;
		case CHAR: arrayC = new char[itsSize];
		arrayI = NULL;
		break;
	}
}
Vector::~Vector() {
		switch (type) {
		case INT: delete[] arrayI;
		break;
		case CHAR: delete[] arrayC;
	}
}
void Vector::at(int index, int &value) {
	if (empty()) {
		cout << "Error: Nothing to return" << endl;	
	}
	if (index < 0) {
		cout << "Error in At: Index must be a non-negative value" << endl;
		return void();
	}
	if (index > itsSize - 1) {
		cout << "Warning: Index is too big, returning the last existing member" << endl;
		index = itsSize - 1;
	}
	value = arrayI[index];
}
void Vector::at(int index, char &value) {
	if (empty()) {
		cout << "Error: Nothing to return" << endl;	
	}
	if (index < 0) {
		cout << "Error in At: Index must be a non-negative value" << endl;
		return void();
	}
	if (index > itsSize - 1) {
		cout << "Warning: Index is too big, returning the last existing member" << endl;
		index = itsSize - 1;
	}
	value = arrayC[index];
}
void Vector::at(int index) {
	if (empty()) {
		cout << "Error: Nothing to show" << endl;	
	}
	if (index < 0) {
		cout << "Error in At: Index must be a non-negative value" << endl;
		return void();
	}
	if (index > itsSize - 1) {
		cout << "Warning: Index is too big, showing the last existing member" << endl;
		index = itsSize - 1;
	}
	switch (type) {
		case INT: cout << arrayI[index] << endl;
		break;
		case CHAR: cout << arrayC[index] << endl;
	}
}
bool Vector::empty() {
	return itsSize == 0;
}
int Vector::size() {
	return itsSize;
}
void Vector::insert(int value, int index){
	if (index < 0) {
		cout << "Error in Insert: Index must be a non-negative value" << endl;
		return void();
	}
	if (index > itsSize) {
		cout << "Warning: Index is too big, your value will be inserted as the last member" << endl;
		index = itsSize;
	}
	int *tmp = arrayI;
	arrayI = new int[++itsSize];
	for (int i = 0; i < value; i++) {
		arrayI[i] = tmp[i];
	}
	arrayI[value] = value;
	for (int i = value + 1; i < itsSize; i++) {
		arrayI[i] = tmp[i - 1];
	}
	delete[] tmp;
}
void Vector::insert(char value, int index) {
	if (index < 0) {
		cout << "Error in Insert: Index must be a non-negative value" << endl;
		return void();
	}
	if (index > itsSize) {
		cout << "Warning: Index is too big, your value will be inserted as the last member" << endl;
		index = itsSize;
	}
	char *tmp = arrayC;
	arrayC = new char[++itsSize];
	for (int i = 0; i < index; i++) {
		arrayC[i] = tmp[i];
	}
	arrayC[index] = value;
	for (int i = index + 1; i < itsSize; i++) {
		arrayC[i] = tmp[i - 1];
	}
	delete[] tmp;
}
void Vector::erase(int index) {
	if (index < 0) {
		cout << "Error in Erase: Index must be a non-negative value" << endl;
		return void();
	}
	if (index > itsSize) {
		cout << "Warning: Index is too big, erasing the last member..." << endl;
		index = itsSize;
	}
	if (type == INT) {
		int *tmp = arrayI;
		arrayI = new int[--itsSize];
		for (int i = 0; i < index; i++) {
			arrayI[i] = tmp[i];
		}
		for (int i = index; i < itsSize; i++) {
			arrayI[i] = tmp[i + 1];
		}
		delete[] tmp;
	}
	else if (type == CHAR) {
		char *tmp = arrayC;
		arrayC = new char[--itsSize];
		for (int i = 0; i < index; i++) {
			arrayC[i] = tmp[i];
		}
		for (int i = index; i < itsSize; i++) {
			arrayC[i] = tmp[i + 1];
		}
		delete[] tmp;
	}
}
void Vector::erase(int index1, int index2) {
	if (index1 < 0 || index2 < 0) {
		cout << "Error in Erase: Index must be a non-negative value" << endl;
		return void();
	}
	if (index1 > itsSize - 1) {
		cout << "Warning: Index1 is too big and will be set to point to the last member" << endl;
		index1 = itsSize - 1;
	}
	if (index2 > itsSize - 1) {
		cout << "Warning: Index2 is too big and will be set to point to the last member" << endl;
		index2 = itsSize - 1;
	}
	if (type == INT) {
		int *tmp = arrayI;
		itsSize -= index2 - index1;
		arrayI = new int[itsSize];
		for (int i = 0; i < index1; i++) {
			arrayI[i] = tmp[i];
		}
		for (int i = index1; i < itsSize; i++) {
			arrayI[i] = tmp[i + index2];
		}
		delete[] tmp;
	}
	else if (type == CHAR) {
		char *tmp = arrayC;
		itsSize -= index2 - index1;
		arrayC = new char[itsSize];
		for (int i = 0; i < index1; i++) {
			arrayC[i] = tmp[i];
		}
		for (int i = index1; i < itsSize; i++) {
			arrayC[i] = tmp[i + index2];
		}
		delete[] tmp;
	}
}
void Vector::push_back(int value) {
	insert(value, itsSize);
}
void Vector::push_back(char value) {
	insert(value, itsSize);
}
void Vector::pop_back() {
	erase(itsSize-1);
}

int main() {
	
	Vector A (INT);
	Vector B (CHAR);
	B.insert('a', 0);
	B.insert('b', 1);
	B.insert('c', 2);
	char b;
	B.at(1, b);
	cout << b << endl;
	B.insert('N', 1);
	B.insert('d', 5);
	B.erase(0);
	cout << endl;
	B.at(0);
	B.at(1);
	B.at(2);
	B.at(3);
	B.erase(0, 2);
	cout << endl;
	B.at(0);
	B.at(1);
	B.push_back('F');
	B.at(2);
	B.pop_back();
	B.at(2);

	return 0;
}
