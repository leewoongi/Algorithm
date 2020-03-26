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

int solution(vector<int> scoville, int K){
    int answer = 0;
    int number;
    priority_queue<int, vector<int>, greater<int>> sc;

    for (int i = 0; i < scoville.size(); i++)
    {
        sc.push(scoville[i]);
    }

    while (1)
    {
        if (sc.size() == 1)
        {
            if (sc.top() > K)
                return answer;
            else
                return -1;
        }

        if (sc.top() > K)
        {
            return answer;
        }
        else
        {
            int a, b;
            a = sc.top();
            sc.pop();
            b = sc.top();
            sc.pop();
            number = a + (b * 2);
            sc.push(number);
            answer++;
        }
    }
    return answer;
}

int main()
{
    vector<int> v = { 1,2,3 };
    int k = 20;

    cout << solution(v, k);
}