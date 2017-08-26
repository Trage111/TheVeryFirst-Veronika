#include <iostream>

using namespace std;

int LeastCommonMultiple(int a, int b, int gcd)
{
	return a*b / gcd;
}

int GreatestCommonDivisor(int a, int b)
{
	if (a < b)
	{
		int temp = a;
		a = b;
		b = temp;
	}

	int gcd, tmp;

	do
	{
		tmp = b;
		b = a%b;
		a = tmp;
	} while (a%b != 0);

	gcd = b;

	return gcd;
}

int main()
{
	int a, b;

	cin >> a >> b;

	int GCD;
	
	if (a == 0)
	{
		GCD = b;
	}
	if (b == 0)
	{
		GCD = a;
	}
	else
		GCD = GreatestCommonDivisor(a, b);

	int LCM = LeastCommonMultiple(a, b, GCD);

	cout << LCM << endl;

	return 0;
}
