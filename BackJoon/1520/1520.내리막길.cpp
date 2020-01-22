#include <iostream>
#include <vector>

using namespace std;

int map[501][501];
int dp[501][501];

int dir_x[4] = { -1,0,1,0 };
int dir_y[4] = { 0,1,0,-1 };



int dfs(int x, int y, int m, int n) {


	if (x == m - 1 && y == n - 1) {
		return dp[x][y] = 1;
	}

	dp[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int n_x = x + dir_x[i];
		int n_y = y + dir_y[i];

		if (n_x >= 0 && n_x < m && n_y >= 0 && n_y < n) {
			if (map[x][y] > map[n_x][n_y]) {
				if (dp[n_x][n_y] != -1) {
					dp[x][y] = dp[x][y] + dp[n_x][n_y];
					continue;
				}
				dp[x][y] = dp[x][y] + dfs(n_x, n_y, m, n);
			}
		}
	}

	return dp[x][y];
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int m, n;
	cin >> m >> n;

	// ¸Ê ¸¸µé±â
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			dp[i][j] = -1;
		}
	}

	int start_x = 0, start_y = 0;

	cout << dfs(start_x, start_y, m, n);




	return 0;
}