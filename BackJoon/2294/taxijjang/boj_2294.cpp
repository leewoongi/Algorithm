#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>

#define INF 2e9
#define SIZE 10010

using namespace std;

typedef long long int ll;

vector<int> cost;

int dp[SIZE];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K; cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int c; cin >> c;
		cost.push_back(c);
	}

	sort(cost.begin(), cost.end());
	fill(dp, dp + SIZE, 20000);

	dp[0] = 0;
	for (int i = 0; i < N; i++) {
		int start = cost[i];

		for (int s = start; s <= K; s++) {
			dp[s] = min(dp[s - start] + 1, dp[s]);
		}
	}

	cout << (dp[K] == 20000 ? -1 : dp[K]);
}