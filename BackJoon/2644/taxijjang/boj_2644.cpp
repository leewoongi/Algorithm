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
	int n1, cnt=0;
}Data;
int parrent[SIZE];
int res;
int node1, node2;
vector<int> arr[SIZE];
bool visited[SIZE];

void fill_root() {
	for (int i = 0; i < SIZE; i++) {
		parrent[i] = i;
	}
}


int _find(int a) {
	if (parrent[a] == a)
		return a;
	return parrent[a] = _find(parrent[a]);
}

void _union(int a, int b) {
	int aRoot = _find(a);
	int bRoot = _find(b);

	if (aRoot == bRoot)
		return;

	parrent[bRoot] = aRoot;
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	fill_root();
	int N; cin >> N;
	 cin >> node1 >> node2;

	int query; cin >> query;
	for (int i = 0; i < query; i++) {
		int n1, n2; cin >> n1 >> n2;
		arr[n1].push_back(n2);
		arr[n2].push_back(n1);
		_union(n1, n2);
		
	}

	if (parrent[node1] != parrent[node2]) {
		cout << -1;
		return 0;
	}

	queue<Data> q;
	Data s; s.n1 = node1; s.cnt = 0;
	q.push(s);

	while (!q.empty()) {
		auto here = q.front();
		q.pop();

		visited[here.n1] = true;

		for (auto next : arr[here.n1]) {
			if (visited[next] == true)
				continue;

			Data n; 
			n.n1 = next;
			n.cnt = here.cnt + 1;

			if (n.n1 == node2) {
				cout << n.cnt;
				return 0;
			}
			visited[n.n1] = true;
			q.push(n);
		}
	}
	return 0;
}