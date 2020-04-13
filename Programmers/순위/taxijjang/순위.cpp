#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<cmath>

#define SIZE 110
const int INF = 2e6;
using namespace std;

typedef long long int ll;

int arr1[SIZE][SIZE];
int arr2[SIZE][SIZE];

void init() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (i == j) continue;
			arr1[i][j] = INF;
			arr2[i][j] = INF;
		}
	}
}

int solution(int n, vector<vector<int>> results) {
	
	init();

	for (auto result : results) {
		arr1[result[0]][result[1]] = 1;
		arr2[result[1]][result[0]] = 1;
	}


	int results_size = results.size();
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;

				arr1[i][j] = min(arr1[i][j], arr1[i][k] + arr1[k][j]);
				arr2[i][j] = min(arr2[i][j], arr2[i][k] + arr2[k][j]);
			}
		}
	}

	int res = 0;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			arr1[i][j] = min(arr1[i][j], arr2[i][j]);
			if (arr1[i][j] != INF)
				cnt++;
		}

		res = cnt == n-1 ? res + 1 : res;
	}

	return res;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; n = 8;
	//vector<vector<int>> results = { {4, 3},{4, 2},{3, 2},{1, 2},{2, 5} };
	vector<vector<int>> results = { {1,2},{2,3},{3,4},{5,6},{6,7},{7,8},{4,5} };
	cout << solution(n, results);
	return 0;
}