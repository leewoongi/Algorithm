#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>

#define INF 1e9
#define SIZE 510

using namespace std;

typedef long long int ll;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int N, M;
int arr[SIZE][SIZE];
int visited[SIZE][SIZE];

void fill_v() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			visited[i][j] = -1;
		}
	}
}
int dfs(int h_x, int h_y) {
	if (h_x == N - 1 && h_y == M - 1)
		return visited[h_x][h_y] = 1;

	if (visited[h_x][h_y] != -1)
		return visited[h_x][h_y];
	
	visited[h_x][h_y] = 0;
	for (int i = 0; i < 4; i++) {
		int n_x = h_x + dx[i];
		int n_y = h_y + dy[i];

		if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= M)
			continue;
		if (arr[h_x][h_y] <= arr[n_x][n_y])
			continue;

		visited[h_x][h_y] += dfs(n_x, n_y);
	}
	return visited[h_x][h_y];
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	fill_v();
	cout << dfs(0, 0);
	return 0;
}