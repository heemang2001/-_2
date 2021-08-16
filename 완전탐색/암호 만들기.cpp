#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int n, m;
char arr[20];

void DFS(int pos, string str, int ja, int mo)
{
	if (str.size() == n)
	{
		if (ja < 2 || mo < 1)
		{
			return;
		}			

		cout << str << endl;
	}

	for (int i = pos; i < m; i++)
	{
		if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
		{
			DFS(i + 1, str + arr[i], ja, mo + 1);
		}
			
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