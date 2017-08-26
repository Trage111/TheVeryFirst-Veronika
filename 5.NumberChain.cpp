// Всего потрачено около 40 минут
// Результат: неправильный ответ (1 из 23)

//#include "stdafx.h"
#include <iostream>

using namespace std;


int main()
{
	int members;

		cin >> members;

		int * numArray = new int[members];

		for (int i = 0; i < members; i++)
		{
			cin >> numArray[i];
		}

		int maxCount = 1;
		int count = 1;
		int number = numArray[members - 1];

		for (int i = members - 1; i > 0; i--)
		{
			if (numArray[i] != numArray[i - 1])
			{
				count = 1;
				continue;
			}
			else
			{
				count++;
			}

			if (maxCount <= count)
			{
				maxCount = count;
				number = numArray[i];
			}
		}

		cout << number << " " << maxCount;

		delete[] numArray;

    return 0;
}

