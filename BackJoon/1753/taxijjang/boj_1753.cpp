#include<iostream>
#include<queue>
#define INF 300000
#define SIZE 20010

using namespace std;

priority_queue<pair<int, int>> pq;
vector<pair<int, int>> dijk[SIZE];

int arr[SIZE];
bool visited[SIZE];
int main(void) {
	int V, E; scanf("%d %d", &V, &E);

	fill(arr, arr + SIZE, INF);

	int start; scanf("%d", &start);

	for (int i = 0; i < E; i++) {
		int u, v, w; scanf("%d %d %d", &u, &v, &w);
		dijk[u].push_back({ w,v });
	}

	arr[start] = 0;

	pq.push({ 0,start });

	while (!pq.empty()) {
		int h_w = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		for (auto n_v : dijk[here]) {
			int n_w = n_v.first;
			int next = n_v.second;
			if (arr[here] + n_w < arr[next]) {
				arr[next] = arr[here] + n_w;
				pq.push({ -arr[next],next });
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (arr[i] == INF)
			cout << "INF\n";
		else
			cout << arr[i] << "\n";
	}
}