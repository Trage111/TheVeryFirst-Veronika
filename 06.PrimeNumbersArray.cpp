// Ïîòðà÷åíî îêîëî 10 ìèíóò
// Ðåçóëüòàò: íåïðàâèëüíûé îòâåò (2 èç 23)

//#include "stdafx.h"
#include <iostream>
#include "math.h"

using namespace std;

bool isPrimeNumber(int num)
{
	if (num == 2)
		return true;
	if (num % 2 == 0)
		return false;
	int root = sqrt(num) + 0.9;
	for (int i = 3; i <= root; i++)
	{
		if ((num % i) == 0)
		{
			return false;
		}
	}

	return true;
}

int main()
{
	int size;

	cin >> size;

	int * Numbers = new int[size];
	int * PrimeNumbers = new int[size];
	int offset = 0;

	for (int i = 0; i < size; i++)
	{
		cin >> Numbers[i];
		if (isPrimeNumber(Numbers[i]))
		{
			PrimeNumbers[offset] = Numbers[i];
			offset++;
		}
	}

	for (int i = 0; i < offset; i++)
	{
		cout << PrimeNumbers[i] << " ";
	}

	delete[] Numbers;
	delete[] PrimeNumbers;

    return 0;
}
