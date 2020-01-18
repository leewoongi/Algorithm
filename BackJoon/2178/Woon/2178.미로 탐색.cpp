#include <iostream>
#include <string>
#include <queue>
using namespace std;


typedef struct NODE {
	
	int x;
	int y;

}node;

int map[101][101];
int dp[101][101];
bool visit[101][101];

int dir_x[4] = { -1,0,1,0 };
int dir_y[4] = { 0,1,0,-1 };

queue<node> q;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	//map ±¸¼º
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			map[i][j] = s[j] - '0';
		}
	}

	q.push({ 0,0});
	visit[0][0] = true;

	while (!q.empty()) {

		node p = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int x = p.x + dir_x[i];
			int y = p.y + dir_y[i];

			if (x >= 0 && x < n && y >= 0 && y < m) {
				if (visit[x][y] == false && map[x][y] == 1) {
					
					dp[x][y] = dp[p.x][p.y] + 1;
					visit[x][y] = true;
					q.push({ x,y});
					
				}
			}
		}
	}


	cout << dp[n - 1][m - 1] + 1;
	return 0;
}