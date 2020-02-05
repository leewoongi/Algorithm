#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, start, sum;
int consul[16][2];
int dp[20];


int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int T, P;
		cin >> T >> P;

		consul[i][0] = T;
		consul[i][1] = P;
	}

	for (int i = N - 1; i >= 0; i--)
	{
		if ((consul[i][0] + i) > N)
		{
			dp[i] = dp[i + 1];
		}
		else
		{
			dp[i] = max((consul[i][1] + dp[i + consul[i][0]]), dp[i]);
			dp[i] = max(dp[i], dp[i + 1]);
			sum = dp[i];
		}
	}

	cout << sum;

}