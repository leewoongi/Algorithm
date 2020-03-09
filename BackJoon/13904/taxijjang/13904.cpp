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

vector<int> arr[SIZE];


priority_queue<int> pq;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int d, w; cin >> d >> w;
		arr[d].push_back(w);
	}

	for (int i = 1; i < SIZE; i++) {
		for (auto w : arr[i]) {
			pq.push(-w);
		}

		while (pq.size() > i)
			pq.pop();
	}

	int res = 0;
	while (!pq.empty()) {
		res += -pq.top();
		pq.pop();
	}

	cout << res;
}