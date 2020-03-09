#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int house[1001][3];


void init_map(int n) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> house[i][j];
		}
	}
}

int main() {
	
	int n;
	cin >> n;

	init_map(n);

	for (int i = n-1; i >= 1; i--) {

			house[i-1][0] = min(house[i][1] + house[i-1][0], house[i][2] + house[i-1][0]);
			house[i-1][1] = min(house[i][0] + house[i-1][1], house[i][2] + house[i-1][1]);
			house[i-1][2] = min(house[i][0] + house[i-1][2], house[i][1] + house[i-1][2]);
	}


	int result = 0;
	result = min(house[0][0], min(house[0][1], house[0][2]));


	cout << result;


	return 0;
}