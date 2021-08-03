#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int N;
int answer;

void DFS(vector<vector<bool>>& vecQueen, int row)
{
	// ��� �࿡ 1���� �־������� ����
	if (row == vecQueen.size())
	{
		answer++;
		return;
	}

	// ��� �ϳ��� �� �� ����
	for (int col = 0; col < vecQueen[row].size(); col++)
	{
		bool bSuccess = true;	
		
		// ���� ��鿡�� �˻�
		for (int i = row - 1, j = 1; i >= 0; i--, j++)
		{
			bool bCheck1 = vecQueen[i][col];	// ���� ���� �����ֳ�?
			bool bCheck2 = col - j >= 0 && vecQueen[i][col - j];	// ���� �밢���� �����ֳ�?
			bool bCheck3 = col + j <= vecQueen.size() - 1 && vecQueen[i][col + j];	// ������ �밢���� �����ֳ�?

			// ���� �ϳ��� �ش� �ȳ��� vecQueen[row][col] �ڸ��� ������ ����
			if (bCheck1 || bCheck2 || bCheck3)
			{
				bSuccess = false;
				break;
			}		
		}

		if (bSuccess)
		{
			vecQueen[row][col] = true; // �� ����
			DFS(vecQueen, row + 1); // ���� �� �˻�
			vecQueen[row][col] = false; // �� �����
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