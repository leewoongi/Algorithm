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

#define INF 210000000

using namespace std;

int n, m, a, b, c;
int city[105][105];

void reset() {
	for (int i = 0; i < 105; i++) {
		for (int j = 0; j < 105; j++) {
			if (i == j) {
				city[i][j] = 0;
				continue;
			}
			city[i][j] = INF;
		}
	}
}

int main() {

	cin >> n;
	cin >> m;
	reset();

	for (int i = 1; i <= m; i++) {
		cin >> a >> b >> c;
		if (city[a][b] > c) {
			city[a][b] = c;
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				city[i][j] = min(city[i][j], city[i][k] + city[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (city[i][j] == INF){
				cout << 0 << " ";
				continue;
			}
			cout << city[i][j] << " ";
		}
		cout << '\n';
	}
}
