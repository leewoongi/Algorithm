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

#define SIZE 1010
typedef long long int ll;

const ll INF = 2000000000000;

using namespace std;


vector<ll> costs;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M; cin >> N >> M;

	ll left=0, right=INF, mid;
	for (int i = 0; i < N; i++) {
		ll cost; cin >> cost;
		costs.push_back(cost);
		left = max(left, cost);
	}

	ll res = INF;
	while (left <= right) {
		mid = (left + right) / 2;

		ll tmp = mid;
		int out_cnt = 1;

		for (auto cost : costs) {
			if (tmp >= cost) {
				tmp -= cost;
			}
			else {
				tmp = mid - cost;
				out_cnt++;
			}
		}

		if (out_cnt <= M) {
			if (out_cnt == M) {
				res = min(res, mid);
			}
			right = mid - 1;
		}

		else
			left = mid + 1;
	}

	cout << res;


}