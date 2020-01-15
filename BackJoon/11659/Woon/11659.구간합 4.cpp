#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	v.push_back(0);

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		
		v.push_back(v[i - 1] + x);
	}

	for (int i = 1; i <= m; i++) {
		int first, second;
		cin >> first >> second;

		cout << v[second] - v[first-1] << "\n";
	}

	return 0;
}