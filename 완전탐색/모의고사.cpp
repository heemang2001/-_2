#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers)
{    
    vector<int> answer;

    vector<int> soopo1 = {1,2,3,4,5};
    vector<int> soopo2 = {2,1,2,3,2,4,2,5};
    vector<int> soopo3 = {3,3,1,1,2,2,4,4,5,5};

    // 점수
    vector<int> Score = { 0, 0, 0 };

    int MaxScore = 0;

    for (int i = 0; i < answers.size(); i++)
    {
        if (soopo1[i % 5] == answers[i])
        {
            Score[0]++;
        }

        if (soopo2[i % 8] == answers[i])
        {
            Score[1]++;
        }

        if (soopo3[i % 10] == answers[i])
        {
            Score[2]++;
        }
    }    
    
    //MaxScore = max(max(Score[0], Score[1]), Score[2]);
    MaxScore = *max_element(Score.begin(), Score.end());

    for (int i = 0; i < Score.size(); i++)
    {
        if (MaxScore == Score[i])
        {
            answer.push_back(i + 1);
        }
    }

    return answer;
}

int main()
{
    vector<int> answers = { 1,2,3,4,5 };

    solution(answers);

   

    return 0;
}