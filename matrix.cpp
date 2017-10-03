// ConsoleApplication12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

const string add = "--add";
const string mult = "--mult";

class Matrix {
public:
//	Matrix(): rows(0), cols(0), matrix(NULL) {}
	Matrix(ifstream *ifs);
	Matrix(const Matrix &rhs);
	~Matrix();
//	Matrix operator + (const Matrix &rhs);
	void operator += (const Matrix &rhs);
	friend ostream& operator << (ostream& ost, const Matrix& rhs);

private:
	int rows;
	int cols;
	double ** matrix;
};

Matrix::Matrix(ifstream *ifs) {
	string tmp;
	getline(*ifs, tmp, ' ');
	rows = stoi(tmp);
	getline(*ifs, tmp, '\n');
	cols = stoi(tmp);
	matrix = new double*[rows];
	for (int i = 0; i < rows; i++) {
		if (ifs->eof()) {
			rows = i-1;
			break;
		}
		matrix[i] = new double[cols];
		getline(*ifs, tmp);
		stringstream ss(tmp);
		for (int j = 0; j < cols; j++) {
			string t;
			getline(ss, t, ' ');
			if (t.empty()) {
				if (i == 0) {
					cols = j - 1;
					break;
				}
				matrix[i][j] = 0;
			}
			else {
				matrix[i][j] = stoi(t);
			}
		}
	}
}
Matrix::Matrix(const Matrix &rhs) {
	rows = rhs.rows;
	cols = rhs.cols;
	matrix = new double*[rows];
	for (int i = 0; i < rows; i++) {
		matrix[i] = new double[cols];
		for (int j = 0; j < cols; j++) {
			matrix[i][j] = rhs.matrix[i][j];
		}
	}
}
Matrix::~Matrix() {
	for (int i = 0; i < rows; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}
/*Matrix Matrix::operator + (const Matrix &rhs) {
	if (matrix == NULL) {
		cols = rhs.cols;
		rows = rhs.rows;
		matrix = new double*[rows];
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				matrix[i][j] = 0;
			}
		}
	}
	if (cols != rhs.cols || rows != rhs.rows) {
		return NULL;
	}
	Matrix toReturn(*this);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			toReturn.matrix[i][j] += rhs.matrix[i][j];
		}
	}
	return toReturn;
} */
void Matrix::operator += (const Matrix &rhs) {
/*	if (matrix == NULL) {
		cout << "matrix = NULL" << endl;
		cols = rhs.cols;
		rows = rhs.rows;
		matrix = new double*[rows];
		for (int i = 0; i < rows; i++) {
			matrix[i] = new double[cols];
			for (int j = 0; j < cols; j++) {
				matrix[i][j] = 0;
				cout << "matrix[i][j] = 0;" << endl;
			}
		}
	} */
	if (cols != rhs.cols || rows != rhs.rows) {
		return void();
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			matrix[i][j] += rhs.matrix[i][j];
		}
	}
}
ostream& operator << (ostream& ost, const Matrix& rhs) {
	for (int i = 0; i < rhs.rows; i++) {
		for (int j = 0; j < rhs.cols; j++) {
			cout << rhs.matrix[i][j] << " ";
		}
		cout << endl;
	}
	return ost;
}

int main(int argc, char ** argv) {

	if (argc < 4 || argc % 2) {
		cout << "Too few arguments" << endl;
		return 1;
	}

	ifstream file(argv[1]);
	Matrix result(&file);
	cout << result;

	for (int i = 3; i < argc; i+=2) {
		if (argv[i - 1] == add) {
			ifstream file(argv[i]);
			if (!file.is_open()) {
				return 1;
			}
			Matrix fromFile(&file);
			result += fromFile;
		}
		else if (argv[i-1] == mult) {
			// do nothing
		}
		else {
			cout << "Wrong syntax" << endl;
		}
	}

	cout << result;

    return 0;
}
