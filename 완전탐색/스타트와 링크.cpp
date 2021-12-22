#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int N;
int Answer = 987654321;
int arrMap[20][20];
int cnt_Team;
bool bVisited[20];

void DFS(int index, int cnt)
{
	if (cnt == cnt_Team)
	{
		int StartTeam = 0;
		int LinkTeam = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (i != j && bVisited[i] == bVisited[j] && bVisited[i] == true)
				{
					StartTeam += arrMap[i][j];
				}

				else if (i != j && bVisited[i] == bVisited[j] && bVisited[i] == false)
				{
					LinkTeam += arrMap[i][j];
				}
			}
		}

		Answer = min(Answer, abs(StartTeam - LinkTeam));
		return;
	}

	if (index == N)
	{
		return;
	}

	bVisited[index] = true;
	DFS(index + 1, cnt + 1);

	bVisited[index] = false;
	DFS(index + 1, cnt);
}

int main()
{
	cin >> N;

	cnt_Team = N / 2;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arrMap[i][j];
		}
	}

	DFS(0, 0);

	cout << Answer << '\n';

	return 0;
}