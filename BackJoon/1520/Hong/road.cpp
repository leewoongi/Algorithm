#include <iostream>
#include <vector>

using namespace std;

int map[501][501];
int dp[501][501];
int M, N;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int dfs(int x, int y)
{
	if (x == M - 1 && y == N - 1)
	{
		return 1;
	}

	dp[x][y] = 0;

	for (int i = 0; i < 4; i++)
	{

		if (x + dx[i] >= 0 && y + dy[i] >= 0 && x + dx[i] < M && y + dy[i] < N
			&& map[x][y] > map[x + dx[i]][y + dy[i]])
		{
			if (dp[x + dx[i]][y + dy[i]] != -1)
			{
				dp[x][y] = dp[x][y] + dp[x + dx[i]][y + dy[i]];
			}
			else
				dp[x][y] = dp[x][y] + dfs(x + dx[i], y + dy[i]);
		}

	}

	return dp[x][y];
}

int main()
{
	cin >> M >> N;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			dp[i][j] = -1;
		}
	}

	cout << dfs(0, 0);
}