#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int N;
int answer;

void DFS(vector<vector<bool>>& vecQueen, int row)
{
	// 모든 행에 1개씩 넣어졌으면 성공
	if (row == vecQueen.size())
	{
		answer++;
		return;
	}

	// 행당 하나만 들어갈 수 있음
	for (int col = 0; col < vecQueen[row].size(); col++)
	{
		bool bSuccess = true;	
		
		// 이전 행들에서 검사
		for (int i = row - 1, j = 1; i >= 0; i--, j++)
		{
			bool bCheck1 = vecQueen[i][col];	// 같은 열에 놓여있나?
			bool bCheck2 = col - j >= 0 && vecQueen[i][col - j];	// 왼쪽 대각선에 놓여있나?
			bool bCheck3 = col + j <= vecQueen.size() - 1 && vecQueen[i][col + j];	// 오른쪽 대각선에 놓여있나?

			// 셋중 하나라도 해당 된나면 vecQueen[row][col] 자리엔 놓을수 없음
			if (bCheck1 || bCheck2 || bCheck3)
			{
				bSuccess = false;
				break;
			}		
		}

		if (bSuccess)
		{
			vecQueen[row][col] = true; // 퀸 놓기
			DFS(vecQueen, row + 1); // 다음 행 검사
			vecQueen[row][col] = false; // 퀸 지우기
		}
	}
}

int main()
{
	cin >> N;

	vector<vector<bool>> vecQueen(N, vector<bool>(N));

	DFS(vecQueen,0);

	cout << answer << '\n';

	return 0;
}