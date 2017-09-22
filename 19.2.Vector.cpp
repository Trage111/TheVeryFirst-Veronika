#include <iostream>
using namespace std;

template <class T>
class Vector {
	public:
	Vector();
	Vector(const Vector &rhs);
	~Vector() { delete[] pArray; }
	T& operator [] (int index);
	Vector& operator = (const Vector &rhs);
	bool empty() { return itsSize == 0; }
	int size() { return itsSize; }
	T& at (int index) { return pArray[index]; }
	void clear() { itsSize = 0; }
	void insert (T value, int index);
	void erase (int index);
	void erase (int index1, int index2);
	void push_back (T value) { insert (value, itsSize); }
	void pop_back() { erase (itsSize - 1); }
 	
	private:
	T *pArray;
	int itsSize;
};

template <class T> Vector<T>::Vector(): itsSize(0) {
	pArray = new T[itsSize];
}
template <class T> Vector<T>::Vector(const Vector<T> &rhs): itsSize(rhs.itsSize) {
	pArray = new T[itsSize];
	for (int i = 0; i < itsSize; i++) {
		pArray[i] = rhs.pArray[i];
	}
}
template <class T> Vector<T>& Vector<T>::operator = (const Vector &rhs) {
	return Vector<T>(rhs);
}
template <class T> T& Vector<T>::operator [] (int index) {
	return pArray[index];
}
template <class T> void Vector<T>::insert (T value, int index) {
	T *tmp = pArray;
	pArray = new T[++itsSize];
	for (int i = 0; i < index; i++) {
		pArray[i] = tmp[i];
	}
	pArray[index] = value;
	for (int i = index + 1; i < itsSize; i++) {
		pArray[i] = tmp[i - 1];
	}
	delete[] tmp;
}
template <class T> void Vector<T>::erase (int index) {
	T *tmp = pArray;
	pArray = new T[--itsSize];
	for (int i = 0; i < index; i++) {
		pArray[i] = tmp[i];
	}
	for (int i = index; i < itsSize; i++) {
		pArray[i] = tmp[i + 1];
	}
	delete[] tmp;
}
template <class T> void Vector<T>::erase (int index1, int index2) {
	T *tmp = pArray;
	itsSize -= index2 - index1;
	pArray = new T[itsSize];
	for (int i = 0; i < index1; i++) {
		pArray[i] = tmp[i];
	}
	for (int i = index1; i < itsSize; i++) {
		pArray[i] = tmp[i + index2 - index1];
	}
	delete[] tmp;
}




int main() {
	Vector <int> A;
	for (int i = 0; i < 10; i++) {
		A.insert(i, i);
	}
	for (int i = 0; i < 10; i++) {
		cout << A.at(i) << " ";
	}
	A.erase(2, 5);
	cout << endl;
	for (int i = 0; i < A.size(); i++) {
		cout << A.at(i) << " ";
	}
	cout << endl;
	A.erase(0);
	for (int i = 0; i < A.size(); i++) {
		cout << A.at(i) << " ";
	}
	A.pop_back();
	cout << endl;
	for (int i = 0; i < A.size(); i++) {
		cout << A.at(i) << " ";
	}
	A.push_back('c');
	cout << endl;
	for (int i = 0; i < A.size(); i++) {
		cout << A.at(i) << " ";
	}
	cout << A.at(-100) << endl;
	Vector <int> B = A;
	for (int i = 0; i < B.size(); i++) {
		cout << B.at(i) << " ";
	}
	B.pop_back();
	for (int i = 0; i < A.size(); i++) {
		cout << A.at(i) << " ";
	}for (int i = 0; i < B.size(); i++) {
		cout << B.at(i) << " ";
	}
	cout << endl;
	cout << B[0];
}