#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int N, S;
int answer;
vector<int> vecNum;

void DFS(int index, int num)
{
	if (index == N)
	{
		return;
	}

	if (num + vecNum[index] == S)
	{
		answer++;
	}

	DFS(index + 1, num);
	DFS(index + 1, num + vecNum[index]);
}

int main()
{
	cin >> N >> S;

	for (int i = 0; i < N; i++)
	{
		int nTemp;
		cin >> nTemp;
		vecNum.push_back(nTemp);
	}

	DFS(0, 0);

	cout << answer << '\n';

	return 0;
}