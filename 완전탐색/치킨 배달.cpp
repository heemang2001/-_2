#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define MAX_NUM 50

int N, M;
int answer;
int Map[MAX_NUM][MAX_NUM];

vector<pair<int, int>> vecHouse;
vector<pair<int, int>> vecChicken;
bool isVisited[13];

int Calcul_Distance(pair<int, int> num1, pair<int, int> num2)
{
	return abs(num1.first - num2.first) + abs(num1.second - num2.second);
}

void DFS(int index, int select)
{
	// 조건 만족
	if (select == M)
	{
		int nTemp = 0;

		for (int i = 0; i < vecHouse.size(); i++)
		{
			int distance = 987654321;

			for (int j = 0; j < vecChicken.size(); j++)
			{
				if (isVisited[j])
				{
					distance = min(distance, Calcul_Distance(vecHouse[i], vecChicken[j]));
				}
			}

			nTemp += distance;
		}

		answer = min(answer, nTemp);
		return;
	}

	if (index == vecChicken.size())
	{
		return;
	}

	// 프랜차이즈 선정
	isVisited[index] = true;
	DFS(index + 1, select + 1);

	// 프랜차이즈 선정X
	isVisited[index] = false;
	DFS(index + 1, select);
}

int main()
{
	cin >> N >> M;

	vector<vector<int>> vecMap(N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int nTemp;
			cin >> Map[i][j];

			// 집이면
			if (Map[i][j] == 1)
			{
				vecHouse.push_back({ i,j });
			}

			// 치킨집이면
			else if (Map[i][j] == 2)
			{
				vecChicken.push_back({ i,j });
			}			
		}
	}

	answer = 987654321;
	
	DFS(0, 0);

	cout << answer << '\n';

	return 0;
}