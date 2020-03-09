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

priority_queue <pair<int, int>> pq;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;

	for (int i = 0; i < N; i++) {
		int left, right; cin >> left >> right;
		pq.push(make_pair(-right, -left));
	}

	pair<int, int> start = pq.top();
	pq.pop();
	int res = 1;
	while (!pq.empty()) {
		pair<int, int> next = pq.top();
		pq.pop();

		if (start.first >= next.second) {
			start = next;
			res++;
		}
	}


	cout << res;
}