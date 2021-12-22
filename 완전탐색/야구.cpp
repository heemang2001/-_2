#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int N;
int Answer;
int arrOrder[9] = { 1,2,3,4,5,6,7,8,9 };

int main()
{
	cin >> N;

	vector<int> vecTemp[51];

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			int nTemp;
			cin >> nTemp;
			vecTemp[i].push_back(nTemp);
		}
	}


	cout << Answer << '\n';

	return 0;
}