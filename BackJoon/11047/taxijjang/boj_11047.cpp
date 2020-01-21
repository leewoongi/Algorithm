#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>

#define INF 2e9
#define SIZE 1010

using namespace std;

typedef long long int ll;

vector<int> cost;

bool cmp(int a, int b) {
	return b < a;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K; cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int c; cin >> c;
		cost.push_back(c);
	}

	sort(cost.begin(), cost.end(), cmp);

	int res = 0;

	for (auto c : cost) {
		res += K / c > 0 ? K / c : 0;
		K %= c;
	}

	cout << res;
}