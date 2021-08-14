#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int N, K;
int answer;

int ReverseGooGoo(int num)
{
	string sTemp = to_string(num);
	int nValue = 0;

	if (sTemp.size() == 1)
	{
		return num;
	}

	else if (sTemp.size() >= 2)
	{
		reverse(sTemp.begin(), sTemp.end());
		nValue = stoi(sTemp);
		return nValue;
	}
}

int main()
{
	cin >> N >> K;

	vector<int> vecGooGoo;

	for (int i = 1; i <= K; i++)
	{
		int nTemp = ReverseGooGoo(N * i);
		vecGooGoo.push_back(nTemp);
	}

	answer = *max_element(vecGooGoo.begin(), vecGooGoo.end());

	cout << answer << '\n';

	return 0;
}