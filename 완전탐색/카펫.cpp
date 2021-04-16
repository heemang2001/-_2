#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow)
{
    vector<int> answer;

    // ����, ���� (�ּ�3)
    int Horizontal = 3;
    int Vertical = 3;

    // ��ü Ÿ�ϰ���
    int MapTile = brown + yellow;

    while (1)
    {
        if ((MapTile % Vertical) == 0)
        {
            Horizontal = MapTile / Vertical;
        }

        if ((Horizontal - 2) * (Vertical - 2) == yellow)
        {
            answer.push_back(Horizontal);
            answer.push_back(Vertical);
            break;
        }

        Vertical++;
    }

    return answer;
}

int main()
{
    solution(10, 2);

    return 0;
}