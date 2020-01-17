#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>

#define INF 2e9
#define SIZE 1010

using namespace std;

typedef long long int ll;

typedef struct Data {
	int x, y;
	int day = 0;
}Data;

typedef struct Res {
	int ssuk = 0;
	int ik = 0;
}Res;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int arr[SIZE][SIZE];
bool visited[SIZE][SIZE];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int M, N; cin >> M >> N;

	queue<Data> q;
	Res res;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				Data h; h.x = i; h.y = j;
				q.push(h);
				visited[i][j] = true;
				res.ik++;
			}
			else if (arr[i][j] == -1)
				res.ssuk++;

		}
	}

	if (res.ik + res.ssuk == N*M) {
		cout << "0";
		return 0 ;
	}

	int day = 0;
	while (!q.empty()) {
		Data h = q.front();
		visited[h.x][h.y] = true;
		q.pop();

		for (int i = 0; i < 4; i++) {
			Data n; 
			n.x = h.x + dx[i];
			n.y = h.y + dy[i];
			n.day = h.day + 1;


			if (n.x <= 0 || n.x > N || n.y <= 0 || n.y > M)
				continue;
			if (visited[n.x][n.y] == true)
				continue;
			if (arr[n.x][n.y] != 0)
				continue;

			q.push(n);
			visited[n.x][n.y] = true;
			res.ik++;
			day = max(day, n.day);
		}
	}


	if (res.ik + res.ssuk == N*M)
		cout << day;
	else
		cout << "-1";
	
	return 0;
}