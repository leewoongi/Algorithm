#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>

#define INF 2e9
#define SIZE 110

using namespace std;

typedef long long int ll;

typedef struct Data {
	int x = 1, y = 1;
	int work = 1;
}Data;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

char arr[SIZE][SIZE];
bool visited[SIZE][SIZE];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M; cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}

	queue<Data> q;
	Data start;

	q.push(start);

	while (!q.empty()) {
		Data h = q.front();
		visited[h.x][h.y] = true;
		q.pop();

		for (int i = 0; i < 4; i++) {
			Data n;
			n.x = h.x + dx[i];
			n.y = h.y + dy[i];
			n.work = h.work + 1;

			if (n.x <= 0 || n.x > N || n.y <= 0 || n.y > M)
				continue;
			if (visited[n.x][n.y] == true || arr[n.x][n.y] != '1')
				continue;

			if (n.x == N && n.y == M) {
				cout << n.work;
				return 0;
			}

			visited[n.x][n.y] = true;
			q.push(n);

		}
	}
	return 0;


}