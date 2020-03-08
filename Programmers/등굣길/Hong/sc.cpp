#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long lr[101][101];
long ud[101][101];
bool check[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    long answer = 0;
    lr[1][0] = 0;
    ud[0][1] = 1;

    for (int i = 0; i < puddles.size(); i++)
    {
        check[puddles[i][0]][puddles[i][1]] = true;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (check[i][j])
            {
                continue;
            }
            else if (lr[i][j - 1] == -1)
            {
                ud[i][j] = ud[i - 1][j] % 1000000007;
                lr[i][j] = ud[i - 1][j] % 1000000007;
            }
            else if (ud[i - 1][j] == -1)
            {
                ud[i][j] = lr[i][j - 1] % 1000000007;
                lr[i][j] = lr[i][j - 1] % 1000000007;
            }
            else
            {
                ud[i][j] = (lr[i][j - 1] + ud[i - 1][j]) % 1000000007;
                lr[i][j] = (lr[i][j - 1] + ud[i - 1][j]) % 1000000007;
            }
        }
    }

    answer = (lr[m][n - 1] + ud[m - 1][n]) % 1000000007;

    return answer;
}

int main()
{
    int m = 4;
    int n = 3;
    vector<vector<int>> puddles = { { 2,2 } };
    cout << solution(m, n, puddles);
}