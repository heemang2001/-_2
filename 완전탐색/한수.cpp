#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 1 <= 한수 <= N

bool IsHanSoo(int num)
{
	// 100 미만
	if (num < 100)
	{
		return true;
	}

	// 100 이상
	else
	{
		string sTemp = to_string(num);
		int differNum = sTemp[1] - sTemp[0];		

		for (int i = 0; i < sTemp.size() - 1; i++)
		{
			if ((sTemp[i] + differNum) != sTemp[i + 1])
			{
				return false;
			}
		}
	}

	return true;
}

int main()
{
	int cnt = 0;
	int N; // 0 <= N <= 1000

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		if (IsHanSoo(i))
		{
			cnt++;
		}
	}

	cout << cnt << '\n';
	cout << "테스트" << '\n';

	return 0;
}