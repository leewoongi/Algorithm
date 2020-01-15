#include <iostream>
#include <vector>
using namespace std;


vector<int> v[1001];
bool visited[1001];

void dfs(int n_x) {

	visited[n_x] = true;
	int len = v[n_x].size();

	for (int i = 0; i < len; i++) {
		
		int x = v[n_x][i];

		if (visited[x] == false) {
			dfs(x);
		}
	}
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		v[x].push_back(y);
		v[y].push_back(x);
	}

	int count = 0;
	for (int i = 1; i <= n; i++) {
		if (visited[i] == false) {
			count++;
			dfs(i);
		}
	}


	cout << count << endl;
	return 0;
}