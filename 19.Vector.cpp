// Well after I've spent ca. 3-4 hours on it I can see that this code is pretty much inadequate, although it is working somehow (gosh!)
// If I find some time, I'll completely rework it (class Vector will just have two+ arrays of different types, only one of them will be initialized)

#include <iostream>
#include <string>

using namespace std;

enum {CHAR, INT};

class arr {
	public:
	virtual ~arr() {}
	virtual int getI(int) {}
	virtual char getC(int) {}
	virtual void insert(arr*, char*, int, int) {}
	virtual void insert(arr*, int, int, int) {}
	virtual void erase(arr*, int, int) {}
	virtual void erase(arr*, int, int, int) {}
	virtual void print(int) {};
};
class aInt: public arr {
	public:
	aInt (int size) {itsA = new int[size];}
	~aInt() {
		cout << "Destrusctor called" << endl;
		delete[] itsA;
	}
	int getI(int index) {return itsA[index];}
	void insert(arr *array, char *value, int member, int size) {
		for (int i = 0; i < member; i++) {
			itsA[i] = array->getI(i);
		}
		itsA[member] = atoi(value);
		for (int i = member + 1; i < size; i++) {
			itsA[i] = array->getI(i-1);
		}
	}
	void insert(arr *array, int value, int member, int size) {
		for (int i = 0; i < member; i++) {
			itsA[i] = array->getI(i);
		}
		itsA[member] = value;
		for (int i = member + 1; i < size; i++) {
			itsA[i] = array->getI(i-1);
		}
	}
	void erase(arr *array, int member, int size) {
		for (int i = 0; i < member; i++) {
			itsA[i] = array->getI(i);
		}
		for (int i = member; i < size; i++) {
			itsA[i] = array->getI(i + 1);
		}
	}
	void erase(arr *array, int first, int last, int size) {
		for (int i = 0; i < first; i++) {
			itsA[i] = array->getI(i);
		}
		for (int i = first; i < size; i++) {
			itsA[i] = array->getI(i + last - 1);
		}
	}
	void print(int size) {
		for (int i = 0; i < size; i++) {
			cout << itsA[i] << " ";
		}
		cout << endl;
	}
	private:
	int *itsA;
};
class aChar: public arr {
	public:
	aChar (int size) {itsA = new char[size];}
	~aChar() {
		cout << "Destrusctor called" << endl;
		delete[] itsA;
	}
	char getC(int index) {return itsA[index];}
	void insert(arr *array, char *value, int member, int size) {
		for (int i = 0; i < member; i++) {
			itsA[i] = array->getC(i);
		}
		itsA[member] = *value;
		for (int i = member + 1; i < size; i++) {
			itsA[i] = array->getC(i-1);
		}
	}
	void erase(arr *array, int member, int size) {
		for (int i = 0; i < member; i++) {
			itsA[i] = array->getC(i);
		}
		for (int i = member; i < size; i++) {
			itsA[i] = array->getC(i + 1);
		}
	}
	void erase(arr *array, int first, int last, int size) {
		for (int i = 0; i < first; i++) {
			itsA[i] = array->getC(i);
		}
		for (int i = first; i < size; i++) {
			itsA[i] = array->getC(i + last - 1);
		}
	}
	void print(int size) {
		for (int i = 0; i < size; i++) {
			cout << itsA[i] << " ";
		}
		cout << endl;
	}
	private:
	char *itsA;
};

class Vector {
	public:
	Vector(int t): itsSize(0), type(t) {
		switch (type){
		case CHAR: array = new aChar[itsSize];
		break;
		case INT: array = new aInt[itsSize];
		break;
		default: cout << "Error in Vector constructor: Unknown type" << endl;
		}
	}
	~Vector() { cout << "Destructor " << endl; delete array;}
	int atI (int index) { // didn't find a way to do with a single at function
		return array->getI(index);
	}
	char atC (int index) {
		return array->getC(index);
	}
	char operator [] (int i) {
		switch (type) {
			case CHAR: return atC(i);
			case INT: return atI(i) + '0';
		}
	}
	bool empty () {
		return itsSize == 0;
	}
	int size () {
		return itsSize;
	}
	void insert(char *value, int member) {
		arr *tmp = array;
		switch (type){
		case CHAR: array = new aChar[++itsSize];
		break;
		case INT: array = new aInt[++itsSize];
		break;
		}
		array->insert(tmp, value, member, itsSize);
		delete tmp;
	}
	void insert(int value, int member) {
		if (type == CHAR) {
			cout << "Can't insert 'int' value to 'char' array" << endl;
			return void();
		}
		arr *tmp = array;
		array = new aInt[++itsSize];
		array->insert(tmp, value, member, itsSize);
		delete tmp;
	}
	void erase(int member) {
		arr *tmp = array;
		switch (type){
		case CHAR: array = new aChar[--itsSize];
		break;
		case INT: array = new aInt[--itsSize];
		break;
		}
		array->erase(tmp, member, itsSize);
		delete tmp;
	}
	void erase(int first, int last) {
		itsSize -= last - first;
		arr *tmp = array;
		switch (type){
		case CHAR: array = new aChar[itsSize];
		break;
		case INT: array = new aInt[itsSize];
		break;
		}
		array->erase(tmp, first, last, itsSize);
		delete tmp;
	}
	void push_back(char *value) {
		arr *tmp = array;
		switch (type){
		case CHAR: array = new aChar[++itsSize];
		break;
		case INT: array = new aInt[++itsSize];
		break;
		}
		array->insert(tmp, value, itsSize-1, itsSize);
		delete tmp;
	}
	void pop_back() {
		arr *tmp = array;
		switch (type){
		case CHAR: array = new aChar[--itsSize];
		break;
		case INT: array = new aInt[--itsSize];
		break;
		}
		array->erase(tmp, itsSize, itsSize);
		delete tmp;
	}
	void print(){
		array->print(itsSize);
	}
	void clear() {
		itsSize = 0;
	}
	
	private:
	arr *array;
	int itsSize;
	int type;
};


int main() {
	char *c = new char;
/*	Vector a (0);
	cout << a.empty() << endl;
	*c = '5';
	a.insert(c, 0);
	*c = 'a';
	a.push_back(c);
	a.print();
	cout << a[1] << endl;
	*c = '!';
	a.push_back(c);
	a.print();
	a.pop_back();
	a.print();
	a.push_back(c);
	*c = '*';
	a.push_back(c);
	*c = '8';
	a.push_back(c);
	*c = ']';
	a.push_back(c);
	a.print();
	a.erase(1);
	a.print();
	a.erase(1, 3);
	a.print();
	a.clear();
	a.print(); */
	
	Vector b(1);
	*c = '1';
	b.insert(c, 0);
	b.print();
	b.insert(100, 1);
	b.print();
	
	
	delete c;
	return 0;
}
