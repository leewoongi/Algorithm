#include <iostream>
#define mod 10007
using namespace std;

int dp[1000];
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	// n = 1 / 1개 	
	// n = 2 / 3개
	// n = 3 / 5개
	// n = 4 / 11개

	dp[1] = 1;
	dp[2] = 3;

	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % mod;
	}
	
	
	cout << dp[n];

	return 0;
}