#include <iostream>
#include <stack>
using namespace std;

int map[51][51];
bool visit[51][51];

int dir_x[4] = { -1,0,1,0 };
int dir_y[4] = { 0,1,0,-1 };

typedef struct NODE {
	int x;
	int y;
}node;

int dfs(int x, int y, int m_m, int m_n) {

	int count = 1;

	stack<node> st;
	st.push({ x,y });
	visit[x][y] = true;

	while (!st.empty()) {

		node n = st.top();
		st.pop();

		for (int i = 0; i < 4; i++) {
			int x = n.x + dir_x[i];
			int y = n.y + dir_y[i];

			if (x >= 0 && x < m_m && y >= 0 && y < m_n) {
				if (visit[x][y] == false && map[x][y] == 1) {
					st.push({ x,y });
					visit[x][y] = true;
				}
			}
		}
	}

	return count;
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, tc;
	cin >> t;

	for (int tc = 1; tc <= t; tc++) {

		int m, n, k;
		cin >> m >> n >> k;

		for (int i = 0; i < k; i++) {
			int r, c;
			cin >> r >> c;

			map[r][c] = 1;
		}
		
		int result = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (visit[i][j] == false && map[i][j] == 1) {
					result = result + dfs(i, j, m, n);
				}
			}
		}


		cout << result << endl;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				visit[i][j] = false;
				map[i][j] = 0;
			}
		}
	}
	return 0;
}