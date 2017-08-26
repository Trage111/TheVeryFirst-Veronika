// Потрачено около 10 минут
// Результат проверки: ОК

//#include "stdafx.h"
#include <iostream>

using namespace std;


int main()
{

	int members;

	cin >> members;

	int * numArray = new int [members];
	int count = 0;

	for (int i = 0; i < members; i++)
	{
		cin >> numArray[i];
		if (numArray[i] > 0)
		{
			count++;
		}
	}

	cout << count;
	
	delete[] numArray;

    return 0;
}

