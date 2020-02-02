#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, counter, check;
int dp[10001] = { -1, };

vector<int> coin;

int main()
{
	cin >> n >> k;

	fill(dp, dp + 10001, 100001);

	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;

		coin.push_back(a);
	}

	sort(coin.begin(), coin.end());
	dp[0] = 0;

	for (int i = 0; i < n; i++) // 3
	{
		for (int j = coin[i]; j <= k; j++) // 15
		{
			dp[j] = min(dp[j - coin[i]] + 1, dp[j]);
		}
	}
	if (dp[k] == 100001)
	{
		cout << -1;
	}
	else
	{
		cout << dp[k];
	}
}