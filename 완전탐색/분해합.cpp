#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define MAX_NUM 1000000

int N;
int answer;

int BoonHaeHab(int num)
{
	int BSum = num;
	string sTemp = to_string(num);

	for (int i = 0; i < sTemp.size(); i++)
	{
		BSum += sTemp[i] - '0';
	}

	return BSum;
}

int main()
{
	cin >> N;

	for (int i = 1; i <= MAX_NUM; i++)
	{
		if (BoonHaeHab(i) == N)
		{
			answer = i;
			break;
		}
	}

	cout << answer << '\n';

	return 0;
}