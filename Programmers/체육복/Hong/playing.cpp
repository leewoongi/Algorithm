#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool visit[30];
bool check[30];

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int s_size = lost.size();
    int b = 0;
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    for (int i = 0; i < reserve.size(); i++)
    {
        for (int j = 0; j < lost.size(); j++)
        {
            if (reserve[i] == lost[j])
            {
                if (visit[reserve[i]] || check[lost[j]])
                {
                    b--;
                }
                reserve.erase(reserve.begin() + i);
                lost.erase(lost.begin() + j);
                i--;
                j--;
                b++;
            }
            else if (reserve[i] - 1 == lost[j] && !visit[reserve[i]] && !check[lost[j]])
            {
                b++;
                visit[reserve[i]] = true;
                check[lost[j]] = true;
            }
            else if (reserve[i] + 1 == lost[j] && !visit[reserve[i]] && !check[lost[j]])
            {
                b++;
                visit[reserve[i]] = true;
                check[lost[j]] = true;
            }
        }
    }
    answer = n - (s_size - b);
    return answer;
}

int main()
{
    int n = 7;
    vector<int> lost = { 2,3,4 };
    vector<int> reserve = { 1,2,3,6 };
    cout << solution(n, lost, reserve);
}