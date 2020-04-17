#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cmath>
#include<stack>
#include<utility>
#include<string.h>

const int INF = 210000000;

using namespace std;

vector<pair<int, int>> vec[20001];
priority_queue<pair<int, int>> pq;
vector<int> res;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E, S;
	cin >> V >> E;
	cin >> S;

	res.resize(V + 1);
	fill(res.begin(), res.end(), INF);

	res[S] = 0;

	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		vec[u].push_back({ -w,v });

		if (u == S) {
			pq.push({ -w,v });
		}
	}

	while (!pq.empty()) {
		int w, v;
		w = pq.top().first;
		v = pq.top().second;
		pq.pop();

		if (res[v] != INF)
			continue;

		res[v] = -w;

		for (int i = 0; i < vec[v].size(); i++) {
			if (res[vec[v][i].second] == INF) {
				pq.push({ w + vec[v][i].first, vec[v][i].second });
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (res[i] == INF) {
			cout << "INF" << '\n';
			continue;
		}
		cout << res[i] << '\n';
	}
}