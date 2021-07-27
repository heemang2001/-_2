#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int N;
int answer;

void DFS(int num, int sum, vector<pair<int, int>>& vecMap)
{
	if (num > N+1)
	{
		return;
	}

	answer = max(answer, sum);

	for (int i = num; i <= N; i++)
	{
		DFS(i + vecMap[i].first, sum + vecMap[i].second, vecMap);
	}
}

int main()
{
	cin >> N;

	vector<pair<int, int>> vecMap(N+1);	

	for (int i = 1; i <= N; i++)
	{
		int nTemp1;
		int nTemp2;

		cin >> nTemp1 >> nTemp2;

		vecMap[i] = { nTemp1, nTemp2 };
	}
	
	for (int i = 1; i <= N; i++)
	{
		DFS(i + vecMap[i].first, vecMap[i].second, vecMap);
	}

	cout << answer << '\n';

	return 0;
}