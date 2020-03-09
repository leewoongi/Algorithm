#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;


priority_queue<int> pq;
vector<int> v[1001];
int main() {

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int r, s;
		cin >> r >> s;

		v[r].push_back(s);
	}

	for (int i = 1; i < 1001; i++) {

		int size = v[i].size();
		for (int j = 0; j < size; j++) {
			pq.push(-v[i][j]);
		}

		while (pq.size() > i) {
			pq.pop();
		}
	}


	int result = 0;
	while (!pq.empty()) {
		result = result + (-pq.top());
		pq.pop();
	}

	cout << result;
	return 0;
}