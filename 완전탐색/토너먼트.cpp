#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N;
int Jimin;
int Hansoo;
int Answer;

int main()
{
	cin >> N >> Jimin >> Hansoo;

	while (1)
	{
		Answer++;

		if ((Jimin % 2 == 1 && Jimin + 1 == Hansoo) || (Hansoo % 2 == 1 && Hansoo + 1 == Jimin))
		{
			break;
		}

		if (Jimin % 2 == 0)
		{
			Jimin /= 2;
		}

		else
		{
			Jimin /= 2;
			Jimin++;
		}

		if (Hansoo % 2 == 0)
		{
			Hansoo /= 2;
		}

		else
		{
			Hansoo /= 2;
			Hansoo++;
		}
	}

	cout << Answer << '\n';

	return 0;
}