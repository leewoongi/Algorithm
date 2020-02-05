#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(int n)
{
    int ans = 0;
    int val = n;
    int left=0, right=n, mid;

    while (left < right)
    {
        mid = (left + right) / 2;
        if (right % 2 == 0)
        {
            right = mid;
        }
        else
        {
            right = mid;
            ans++;
        }
    }
    return ans;
}

int main()
{
    int n = 5000;
    cout << solution(n);
}