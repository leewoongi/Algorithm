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

vector<int > graph[SIZE];
bool visited[SIZE];

void dfs(int h_x) {
	visited[h_x] = true;

	//현재 위치인 h_x와 연결된 모든 요소를 가지고 옴
	for (auto next : graph[h_x]) {
		if (visited[next] != true) {
			dfs(next);
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int N, M; cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);

	}

	int res = 0;
	for (int i = 1; i <= N; i++) {
		//방문하지 않았으면 연결되지 않았기에 연결 요소 증가
		if (visited[i] != true) {
			res++;
			dfs(i);
		}
	}

	cout << res;

}