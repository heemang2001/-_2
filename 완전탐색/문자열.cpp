#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int Answer;

int main()
{
	string sTemp1;
	string sTemp2;	

	cin >> sTemp1 >> sTemp2;

	for (int i = 0; i <= sTemp2.size() - sTemp1.size(); i++)
	{
		int cnt = 0;

		for (int j = 0; j < sTemp1.size(); j++)
		{
			if (sTemp1[j] == sTemp2[i + j])
			{
				cnt++;
			}
		}

		Answer = max(Answer, cnt);
	}

	cout << sTemp1.size() - Answer << '\n';

	return 0;
}