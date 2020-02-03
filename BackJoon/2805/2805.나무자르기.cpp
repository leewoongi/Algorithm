#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		v.push_back(x);
	}

	sort(v.begin(), v.end());
	int bottom = 0;
	int top = v[v.size() - 1];

	int result = 0;
	
	while (bottom <= top) {

		int mid = (bottom + top) / 2;
		int sum = 0;

		for (int i = 0; i < n; i++) {
			if (mid < v[i]) {
				sum = sum + (v[i]-mid);
			}			
		}

		if (sum >= m) {
			bottom = mid + 1;
			if (result < mid) {
				result = mid;
			}
		}

		if (sum < m) {
			top = mid - 1;
		}
	}

	cout << result;

	return 0;
}