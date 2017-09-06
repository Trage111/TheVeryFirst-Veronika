// Âñåãî ïîòðà÷åíî îêîëî 40 ìèíóò
// Ðåçóëüòàò: íåïðàâèëüíûé îòâåò (1 èç 23)

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

