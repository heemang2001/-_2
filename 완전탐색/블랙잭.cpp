#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 한글테스트
int N, M;
int answer;

int BF(vector<int> vecNum, int num)
{
	int nValue = -1;

	for (int i = 0; i < vecNum.size(); i++)
	{
		for (int j = 0; j < vecNum.size(); j++)
		{
			for (int k = 0; k < vecNum.size(); k++)
			{
				if (i != j && j != k && i != k)
				{
					int nTemp = vecNum[i] + vecNum[j] + vecNum[k];
					if (nTemp <= num)
					{
						nValue = max(nValue, nTemp);
					}
				}
			}
		}
	}

	return nValue;
}

int main()
{
	cin >> N >> M;

	vector<int> vecNum(N);

	for (int i = 0; i < N; i++)
	{
		int nTemp;
		cin >> nTemp;
		vecNum[i] = nTemp;
	}

	answer = BF(vecNum, M);

	cout << answer << '\n';

	return 0;
}