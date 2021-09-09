#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int answer = 1;
int E, S, M; //  (1 ¡Â E ¡Â 15, 1 ¡Â S ¡Â 28, 1 ¡Â M ¡Â 19)

int main()
{
	cin >> E >> S >> M;

	int nTemp1 = 1;
	int nTemp2 = 1;
	int nTemp3 = 1;

	while (1)
	{
		if (E == nTemp1 && S == nTemp2 && M == nTemp3)
		{
			cout << answer << '\n';
			break;
		}

		nTemp1++;
		nTemp2++;
		nTemp3++;

		if (nTemp1 > 15)
		{
			nTemp1 = 1;
		}

		if (nTemp2 > 28)
		{
			nTemp2 = 1;
		}

		if (nTemp3 > 19)
		{
			nTemp3 = 1;
		}

		answer++;
	}

	return 0;
}