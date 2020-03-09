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
const int INF = 2000000000;

using namespace std;

typedef long long int ll;

vector<ll> citys;

ll calc(vector<ll> &citys, ll mid) {
	ll total_cost = 0;

	for (auto city : citys) {
		if (city < mid)
			total_cost += city;
		else {
			total_cost += mid;
		}
	}

	return total_cost;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;

	ll left = 0, right = INF, mid;
	ll sum = 0;
	for (int i = 0; i < N; i++) {
		ll cost; cin >> cost;
		citys.push_back(cost);
		sum += cost;
	}

	sort(citys.begin(), citys.end());
	right = citys.back();
	
	ll budget; cin >> budget;

	while (left <= right) {	
		mid = (left + right) / 2;
		ll total_cost = 0;

		total_cost = calc(citys, mid);

		if (total_cost <= budget) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << right;
}