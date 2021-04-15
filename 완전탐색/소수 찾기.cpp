#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// �Ҽ� �Ǻ� �Լ�
bool isPrime(int n)
{
    if(n < 2)
    {
        return false;
    }

    // �����佺�׳׽��� ü
    for(int i = 2; (i*i) <= n; i++)
    {
        if(n % i == 0)
        {
            return false;
        }
    }        

    return true;
}

int solution(string numbers)
{
    int answer = 0;
    vector<char> v;  // ���� ������ �� ���� ����
    vector<int> nums;   // ���� �������� ���� �� �ִ� ��� �� ����

    // numbers�� �� ���ڸ� v�� �Է� �� �������� ����
    for (int i = 0; i < numbers.size(); i++)
    {
        v.push_back(numbers[i]);
    }
        
    sort(v.begin(), v.end());

    do
    {
        string temp = "";
        // ���� �� �ִ� ��� ���� nums�� ����
        for (int i = 0; i < v.size(); i++) {
            temp.push_back(v[i]);
            nums.push_back(stoi(temp));
        }
    }

    while (next_permutation(v.begin(), v.end()));

    // �ߺ� �� �����
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    for (int i = 0; i < nums.size(); i++)
    {
        // �Ҽ��� ��� answer++
        if (isPrime(nums[i]))
        {
            answer++;
        }            
    }

    return answer;
}

int main()
{
	cout << solution("112");

	return 0;
}