#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef struct NODE {
	int x;
	int count;
}node;


vector<int> v[101];
bool visit[101];
queue<node> q;


int parent[101];

void init_parent() {
	for (int i = 1; i <= 100; i++) {
		parent[i] = i;
	}
}

int find(int a) {

	if (a == parent[a]) {
		return a;
	}
	else {

		return parent[a] = find(parent[a]);
	}
}

void Union(int x, int y) {

	x = find(x);
	y = find(y);

	if (x != y) {
		parent[y] = x;
	}
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	int x, y;
	cin >> x >> y;

	int m;
	cin >> m;

	init_parent();

	for (int i = 0; i < m; i++) {
		int p, c;
		cin >> p >> c;
		v[p].push_back(c);
		v[c].push_back(p);


		Union(p, c);
	}

	if (parent[x] != parent[y]) {
		cout << -1;
		return 0;
	}
	else {

		q.push({ x,0 });
		visit[x] = true;

		while (!q.empty()) {

			node n1 = q.front();
			q.pop();

			int len = v[n1.x].size();
			for (int i = 0; i < len; i++) {			
				if (visit[v[n1.x][i]] == false) {

					int next = v[n1.x][i];
					int next_count = n1.count + 1;

					if (next == y) {
						cout << next_count;
						return 0;
					}

					visit[next] = true;
					q.push({ next, next_count });
				}
			}
		}
	}

	return 0;
}