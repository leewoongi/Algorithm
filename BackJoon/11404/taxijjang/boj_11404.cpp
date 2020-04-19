#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<cmath>

#define SIZE 110
const int INF = 2e6;
using namespace std;

typedef long long int ll;

int city[SIZE][SIZE];

void init() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (i == j) continue;
			city[i][j] = INF;
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m; cin >> n >> m;

	init();
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		city[a][b] = c;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;

				city[i][j] = min(city[i][j], city[i][k] + city[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << city[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}