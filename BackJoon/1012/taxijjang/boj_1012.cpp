#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>

#define INF 2e9
#define SIZE 55

using namespace std;

typedef long long int ll;

int M, N, K;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

bool arr[SIZE][SIZE];

void dfs(int h_x, int h_y) {
	arr[h_x][h_y] = false;

	for (int i = 0; i < 4; i++) {
		int n_x = h_x + dx[i];
		int n_y = h_y + dy[i];

		if (n_x < 0 || n_x >= M || n_y < 0 || n_y >= N)
			continue;
		if (arr[n_x][n_y] == false)
			continue;

		dfs(n_x, n_y);
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> M >> N >> K;

		memset(arr, false, sizeof(arr));

		for (int i = 0; i < K; i++) {
			int x, y; cin >> x >> y;
			arr[x][y] = true;
		}

		int res = 0;

		for (int x = 0; x < M; x++) {
			for (int y = 0; y < N; y++) {
				if (arr[x][y] != false) {
					res++;
					dfs(x, y);
				}
			}
		}

		cout << res << "\n";

	}
}