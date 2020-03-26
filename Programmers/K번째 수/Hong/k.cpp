#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cmath>
#include<stack>
#include<utility>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (int i = 0; i < commands.size(); i++)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int j = commands[i][0] - 1; j < commands[i][1]; j++)
        {
            pq.push(array[j]);
        }

        for (int r = 1; r < commands[i][2]; r++)
        {
            pq.pop();
        }
        answer.push_back(pq.top());
    }

    return answer;
}
int main()
{
    vector<int> a = { 1, 5, 2, 6, 3, 7, 4 };
    vector<vector<int>> c = { {2, 5, 3},{4, 4, 1},{1, 7, 3} };
    solution(a, c);
}