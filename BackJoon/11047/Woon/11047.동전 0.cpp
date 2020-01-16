#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		
		v.push_back(x);
	}
	
	sort(v.begin(), v.end());

	int i = n-1;
	int count = 0;

	for (int i = n - 1; i >= 0; i--) {
		
		if (k >= v[i]) {
			while (true) {
				// k의 현재값보다 빼줄금액이 더 클 경우 종료
				if (k < v[i]) {
					break;
				}
				k = k - v[i];
				count++;
			}
		}

		if (k == 0) {
			break;
		}
	}



	cout << count;
	return 0;
}