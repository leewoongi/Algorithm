#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<functional>
#include<cmath>
#include<stack>

#define SIZE 210
const int INF = 2000000000;

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

vector<int> net[SIZE];
bool visited[SIZE];

void dfs(int here) {
	visited[here] = true;

	for (auto next : net[here]) {
		if (visited[next] == true)
			continue;

		dfs(next);
	}
}
int solution(int n, vector<vector<int>> computers) {
	for (int here = 0; here < n; here ++){
		for (int next = 0; next < n; next++) {
			if (here == next)continue;
			if (computers[here][next] != 0)
				net[here].push_back(next);
		}
	}

	int res = 0;
	for (int i = 0; i < n; i++) {
		if (visited[i] != true) {
			res++;
			dfs(i);
		}
	}
	return res;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n = 3;
	vector<vector<int>> com = { {1,1,0},{1,1,1},{0,1,1} };

	cout << solution(n, com);
}