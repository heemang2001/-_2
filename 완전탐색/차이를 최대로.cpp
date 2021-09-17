#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N;
int Answer;

int SumMinus(vector<int>& vec)
{
	int nValue = 0;

	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = i + 1; j < vec.size(); j++)
		{
			nValue += abs(vec[i] - vec[j]);
			break;
		}
	}

	return nValue;
}

int main()
{
	cin >> N;

	vector<int> vecNum(N);

	for (int i = 0; i < N; i++)
	{
		int nTemp;
		cin >> nTemp;
		vecNum[i] = nTemp;
	}

	sort(vecNum.begin(), vecNum.end());

	do
	{
		Answer = max(Answer, SumMinus(vecNum));

	} while (next_permutation(vecNum.begin(), vecNum.end()));

	cout << Answer << '\n';

	return 0;
}
