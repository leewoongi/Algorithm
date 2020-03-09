#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;


vector<int> v;
int main() {
		
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x; 
		cin >> x;

		v.push_back(x);
	}

	int m;
	cin >> m;

	sort(v.begin(), v.end());

	int left = 0;
	int right = v[n - 1];

	int result = 0;
	int mid = 0;

	while (left <= right) {

		mid = (left + right)/2;
		int tmp = 0;
		for (int i = 0; i < n; i++) {
			if (mid > v[i]) {
				tmp = tmp + v[i];
			}
			else {
				tmp = tmp + mid;
			}
		}

		if (tmp > m) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
			if (result < mid) {
				result = mid;
			}
		}
	}

	cout << result;
	return 0;
}