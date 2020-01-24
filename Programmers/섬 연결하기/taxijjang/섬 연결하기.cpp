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

int parrent[SIZE];

void init() {
	for (int i = 0; i < SIZE; i++) {
		parrent[i] = i;
	}
}

typedef struct Data {
	int node1, node2, cost;
}Data;

struct cmp {
	bool operator()(Data d1, Data d2) {
		return d1.cost > d2.cost;
	}
};
priority_queue<Data, vector<Data>, cmp> pq;

int _find(int a) {
	if (parrent[a] == a)
		return a;
	else
		return parrent[a] = _find(parrent[a]);
}
void _union(int a, int b) {
	int aRoot = _find(a);
	int bRoot = _find(b);

	if (aRoot == bRoot)
		return;

	parrent[bRoot] = aRoot;
}
int solution(int n, vector<vector<int>> costs) {
	init();
	int c_size = costs.size();
	for (int i = 0; i < c_size; i++) {
		Data n;
		n.node1 = costs[i][0];
		n.node2 = costs[i][1];
		n.cost = costs[i][2];
		pq.push(n);
	}

	int answer = 0;
	while (!pq.empty()) {
		Data here = pq.top();
		pq.pop();

		if (_find(here.node1) != _find(here.node2)) {
			_union(here.node1, here.node2);
			answer += here.cost;
		}
	}
	
	return answer;

}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	vector<vector<int>> cost;

	for (int i = 0; i < 5; i++) {
		vector<int> v;
		int a, b, c; cin >> a >> b >> c;
		v.push_back(a); v.push_back(b); v.push_back(c);
		cost.push_back(v);
	}

	cout << solution(n, cost);
}
