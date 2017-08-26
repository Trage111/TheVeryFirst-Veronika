// Потрачено около 30 минут на написание и около 30 минут на безуспешные попытки понять, что не так.
// Результат проверки: неправильный ответ
// Все мои тесты выдавали ожидаемый ("правильный") ответ

//#include "stdafx.h"
#include "math.h"
#include <iostream>

using namespace std;


bool isPrimeNumber(int num)
{
	if (num == 2)
	{
		return true;
	}
	if (num % 2 == 0)
	{
		return false;
	}

	for (int i = 3; i*i <= num; i++)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	
	return true;	
}

bool isHyperPrimeNumber(int num)
{
	do
	{
		if (!isPrimeNumber(num))
		{
			return false;
		}
		num = num/10;
	} while (num);

	return true;
}

int main()
{
	int a, b;
	cin >> a >> b;

	bool c = false;

	for (int i = a; i <= b; i++)
	{
		if (isHyperPrimeNumber(i))
		{
			c = true;
			cout << i << " ";
		}
	}

	if (!c)
	{
		cout << 0 << endl;
	}

    return 0;
}


