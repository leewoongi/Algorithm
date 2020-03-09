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

int dp[SIZE][3];
int arr[SIZE][3];

pair<int, int> loc(int left, int right) {
	pair<int, int> Loc = { left,right };

	if (left == -1)
		Loc.first = 2;
	if (right == 3)
		Loc.second = 0;

	return Loc;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int RED, GREEN, BLUE, COLOR; RED = 0; GREEN = 1; BLUE = 2; COLOR = 3;

	int N; cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i][RED] >> arr[i][GREEN] >> arr[i][BLUE];
	}

	for (int i = 0; i < 3; i++) {
		dp[0][i] = arr[0][i];
	}

	for (int i = 1; i < N; i++) {
		for (int c = 0; c < COLOR; c++) {
			pair<int, int> l = loc(c - 1, c + 1);

			dp[i][c] += min(dp[i - 1][l.first], dp[i - 1][l.second]) + arr[i][c];
		}
	}

	int res = INF;
	for (int c = 0; c < COLOR; c++) {
		res = min(res, dp[N-1][c]);
	}
	cout << res;
	getchar();
}