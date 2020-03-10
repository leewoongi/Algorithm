#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int main() {

	int n, m;
	cin >> n >> m;

	int sum = 0;
	int m_min = 2100000000;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		sum = sum + x;
		if (m_min > x) {
			m_min = x;
		}
		v.push_back(x);

	}

	int left = m_min;
	int right = sum;
	int result = 210000000;

	while (left <= right) {

		int mid = (left + right) / 2;
		int money = 0;
		int count = 0;
		bool flag = true;

		for (int i = 0; i < n; i++) {

			if (mid < v[i]) {
				flag = false;
				break;
			}

			if (money < v[i]) {
				count++;
				money = mid;
				
			}
			
			money = money - v[i];
			

		}

		if (count > m || flag == false) {
			left = mid+1;
		}
		else {

			if (result > mid) {
				result = mid;
			}
			
			right = mid-1;			
		}		
	}

	cout << result;
	return 0;
	
}
