#include <iostream>
#include <vector>
#include <algorithm>

#define INF 210000000
using namespace std;

int coin[10001];

void init_coin() {
	for (int i = 0; i < 10001; i++) {
		coin[i] = INF;
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	init_coin();
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());
	coin[0] = 0;
	for (int i = 0; i < n; i++) {
		int now = v[i];

		for (int j = now; j <= k; j++) {
			if (coin[j] == INF) {
				coin[j] = coin[j - now] + 1;
			}
			else {
				coin[j] = min(coin[j - now] + 1, coin[j]);
			}
			
		}
	}

	if (coin[k] > INF) {
		cout << -1;
	}
	else {
		cout << coin[k];
	}
	
	return 0;
}