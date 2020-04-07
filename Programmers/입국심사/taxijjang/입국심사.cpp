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

#define SIZE 1010
const int INF = 2000000000;

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

long long solution(int n, vector<int> times) {
	long long answer = 0;
	ll left = 1, right = n * (ll)times.back() + 1, mid;
	while (left <= right) {
		//½Ã°£
		mid = (left + right) / 2;

		ll man_cnt = 0;
		for (auto time : times) {
			man_cnt = man_cnt + (mid / time);
		}

		if (man_cnt < n)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return left;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n = 6;
	vector<int> times = { 7,10 };
	cout << solution(6, times);
}