#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

typedef struct NODE {
	int x;
	int y;
	int block_count;
	int dis;
}node;


int map[1001][1001];
int visit[1001][1001];
int dp[1001][1001];
int dir_x[4] = { -1,0,1,0 };
int dir_y[4] = { 0,1,0,-1 };


void init_map(int n, int m) {
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= m; j++) {
			map[i][j] = s[j - 1] - '0';
		}
	}
}

int main() {

	int n, m;
	cin >> n >> m;

	init_map(n, m);
	int start_x = 1, start_y = 1;
	int end_x = n, end_y = m;

	queue<node> q;
	q.push({ start_x, start_y, 0, 0 });
	visit[start_x][start_y] = true;

	int result = -1;
	while (!q.empty()) {
		node p = q.front();
		q.pop();

		if (p.x == end_x && p.y == end_y) {
			result = p.dis;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int x = p.x + dir_x[i];
			int y = p.y + dir_y[i];

			if (x >= 1 && x <= n && y >= 1 && y <= m) {
				if (visit[x][y] == false) {

					// 0일떄
					if (map[x][y] == 0) {
						visit[x][y] = true;
						q.push({ x,y,p.block_count,p.dis + 1 });
						dp[x][y] = p.block_count;
					}

					// 1일때
					else {
						if (p.block_count == 0) {
							visit[x][y] = true;
							q.push({ x,y,p.block_count + 1,p.dis + 1 });
							dp[x][y] = p.block_count;
						}
					}

				}
				// 방문한 지점일떄
				else {
					if (dp[x][y] > p.block_count) {
						q.push({ x,y,p.block_count,p.dis + 1 });
						dp[x][y] = p.block_count;
					}
				}
			}
		}
	}


	if (result == -1) {
		result = -1;
	}
	else {
		result = result + 1;
	}

	cout << result;
	return 0;
}