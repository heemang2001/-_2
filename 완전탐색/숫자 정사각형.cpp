#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int N, M;
int Answer = 1;
int arrMap[51][51];

int main()
{
	cin >> N >> M;

	vector<string> vecTemp;

	for (int i = 0; i < N; i++)
	{
		string sTemp;
		cin >> sTemp;
		vecTemp.push_back(sTemp);
	}

	memset(arrMap, -1, sizeof(arrMap));

	for (int i = 0; i < vecTemp.size(); i++)
	{
		for (int j = 0; j < vecTemp[i].size(); j++)
		{
			arrMap[i][j] = vecTemp[i][j] - '0';
		}
	}

	int minNum = min(N, M);

	if (N > 1)
	{
		int curLenth = 1;

		while (1)
		{
			if (curLenth == minNum)
			{
				break;
			}			

			for (int i = 0; i < N - curLenth; i++)
			{
				for (int j = 0; j < M - curLenth; j++)
				{
					int curLeftUp = arrMap[i][j];

					if (curLeftUp == arrMap[i][j + curLenth] && curLeftUp == arrMap[i + curLenth][j] && curLeftUp == arrMap[i + curLenth][j + curLenth])
					{
						Answer = max(Answer, (curLenth + 1) * (curLenth + 1));
					}
				}
			}

			curLenth++;
		}		
	}

	cout << Answer << '\n';

	return 0;
}