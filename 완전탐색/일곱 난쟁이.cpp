#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	vector<int> vecTall;

	for (int i = 0; i < 9; i++)
	{
		int nTemp;
		cin >> nTemp;
		vecTall.push_back(nTemp);
	}

	int sum = 0;

	for (int i = 0; i < 9; i++)
	{
		sum += vecTall[i];
	}
	
	sort(vecTall.begin(), vecTall.end());
	bool bEndFind = false;

	for (int i = 0; i < 8; i++)
	{
		if (bEndFind)
		{
			break;
		}

		for (int j = i+1; j < 9; j++)
		{
			if ((sum - (vecTall[i] + vecTall[j])) == 100)
			{
				bEndFind = true;
				vecTall.erase(vecTall.begin() + i);
				vecTall.erase(vecTall.begin() + j - 1);		
				break;
			}
		}
	}

	for (int i = 0; i < vecTall.size(); i++)
	{
		cout << vecTall[i] << '\n';
	}

	return 0;
}