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

#define SIZE 555
const int INF = 2000000000;

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

bool visited[SIZE];
void init() {
	for (int i = 0; i < SIZE; i++) {
		visited[i] = false;
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;

	while (T--) {
		init();
		vector<int> arr[SIZE];
		queue < pair<int,int>> q;
		int N, M; cin >> N >> M;
		for (int i = 0; i < M; i++) {
			int a, b; cin >> a >> b;
			arr[a].push_back(b);
			arr[b].push_back(a);
		}

		int res = 0;
		q.push({ 1,0 });
		while (!q.empty()) {
			pair<int, int> h = q.front(); q.pop();

			visited[h.first] = true;
			if (h.second >= 2) {
				continue;
			}
			for (auto next : arr[h.first]) {
				if (visited[next] != true) {
					visited[next] = true;
					pair<int, int> n;
					n.first = next; n.second = h.second + 1;
					q.push(n);
					res++;
				}
			}
		}
		cout << res << "\n";
	}
	
}