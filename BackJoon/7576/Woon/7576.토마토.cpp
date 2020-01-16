#include <iostream>
#include <queue>

using namespace std;

typedef struct NODE {
	int x;
	int y;
	int count = 0;
}node;


int map[1001][1001];
bool visit[1001][1001];

int dir_x[4] = { -1,0,1,0 };
int dir_y[4] = { 0,1,0,-1 };

queue<node> q;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	//∏  √ ±‚»≠
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];

			if (map[i][j] == 1) {
				q.push({ i,j,0 });
				visit[i][j] = true;
			}
		}
	}

	// bfs
	node p;
	while (!q.empty()) {

		p = q.front();
		q.pop();
		
		for (int i = 0; i < 4; i++) {
 			int x = p.x + dir_x[i];
			int y = p.y + dir_y[i];

			if (x >= 0 && x < m && y >= 0 && y < n) {
				if (visit[x][y] == false && map[x][y] == 0) {
					
					q.push({ x,y,p.count+1});
					map[x][y] = 1;
					visit[x][y] = true;
				}
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
	}

	cout << p.count;
	return 0;
}