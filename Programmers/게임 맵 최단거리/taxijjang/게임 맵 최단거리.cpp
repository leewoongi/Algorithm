#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<functional>

#define SIZE 110

using namespace std;

typedef long long int ll;
typedef struct Data {
	int x, y, len = 1;
}Data;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

const int INF = 2000000000;

bool visited[SIZE][SIZE];
int board[SIZE][SIZE];
queue<Data> q;
int solution(vector<vector<int> > maps)
{
	int N = maps.size();
	int M = maps[0].size();

	memset(board, -1, sizeof(board));

	Data start; start.x = 0; start.y = 0;
	q.push(start);
	
	while (!q.empty()) {
		Data h = q.front();
		q.pop();

		visited[h.x][h.y] = true;
		board[h.x][h.y] = h.len;
		for (int i = 0; i < 4; i++) {
			Data n;
			n.x = h.x + dx[i];
			n.y = h.y + dy[i];
			n.len = h.len + 1;

			if (n.x < 0 || n.x >= N || n.y < 0 || n.y >= M)
				continue;
			if (visited[n.x][n.y] == true)
				continue;
			if (maps[n.x][n.y] == 0)
				continue;
			visited[n.x][n.y] = true;
			board[n.x][n.y] = n.len;
			q.push(n);
		}

	}
	return board[N - 1][M - 1];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M; cin >> N >> M;

	vector<vector<int>> maps;
	for (int i = 0; i < N; i++) {
		vector<int> m;
		for (int j = 0; j < M; j++) {
			int n; cin >> n;
			m.push_back(n);
		}
		maps.push_back(m);
	}

	cout << solution(maps);

}