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

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long left = 1;
    long long right = 999999999999999999;
    long long mid;

    while (left <= right)
    {
        long long counter = 0;
        mid = (left + right) / 2;
        for (int i = 0; i < times.size(); i++)
        {
            counter += mid / times[i];
        }

        if (counter >= n)
        {
            right = mid - 1;
        }
        else
            left = mid + 1;
    }

    answer = left;

    return answer;
}

int main()
{
    int n = 2;
    vector<int> times = { 1,1 };

    cout << solution(n, times);
}
