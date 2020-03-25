#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cmath>
#include<stack>

using namespace std;

vector<int> solution(vector<int> heights)
{
    vector<int> answer;
    int counter = 0;
    int index = 0;

    answer.push_back(0);

    for (int i = 1; i < heights.size(); i++)
    {
        if (heights[i - 1] > heights[i])
        {
            answer.push_back(i);
            index = i;
            counter = heights[i-1];
        }
        else
        {
            if (counter > heights[i])
            {
                answer.push_back(index);
            }
            else
            {
                answer.push_back(0);
            }
        }
    }

    return answer;
}

int main()
{
    //vector<int> heights{ 1, 5, 3, 6, 7, 6, 5 };
    vector<int> heights{ 6,9,5,7,4 };

    solution(heights);
}