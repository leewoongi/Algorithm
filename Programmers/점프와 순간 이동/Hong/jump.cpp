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
    
    while (val > 0)
    {
        ans = ans + val % 2;
        val = val / 2;
    }

    return ans;
}

int main()
{
    int n = 5000;
    cout << solution(n);
}