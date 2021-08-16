#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int n, m;
char arr[20];

// 최소 1개이상의 모음 (a, e, i, o, u)
// 최소 2개이상의 자음

void DFS(int pos, string str, int ja, int mo)
{
	if (str.size() == n)
	{
		// 자음 2개이상 모음 1개 이상이 없으면 리턴
		if (ja < 2 || mo < 1)
		{
			return;
		}			

		cout << str << endl;
	}

	for (int i = pos; i < m; i++)
	{
		// 모음이면
		if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
		{
			DFS(i + 1, str + arr[i], ja, mo + 1);
		}
			
		// 자음이면
		else
		{
			DFS(i + 1, str + arr[i], ja + 1, mo);
		}			
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> arr[i];
	}		

	sort(arr, arr + m);

	DFS(0, "", 0, 0);

	return 0;
}