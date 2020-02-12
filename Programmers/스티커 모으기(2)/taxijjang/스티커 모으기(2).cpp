#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<functional>

#define SIZE 101000

using namespace std;

typedef long long int ll;

const int INF = 2000000000;

int arr[SIZE];
int dp[2][SIZE];

int solution(vector<int> sticker)
{
	int s_size = sticker.size();
	if (s_size == 1)
		return sticker[0];
	for (int i = 0; i < s_size; i++) {
		arr[i + 1] = sticker[i];
	}

	for (int i = 0; i < 3; i++) {
		dp[0][i] = arr[i];
		dp[1][s_size - i] = arr[s_size- i];
	}

	for (int i = 3; i <= s_size; i++) {
		dp[0][i] = arr[i] + max(dp[0][i - 2], dp[0][i - 3]);
	}
	dp[0][s_size] -= dp[0][1];

	for (int i = s_size -2 ; i >= 0; i--) {
		dp[1][i] = arr[i] + max(dp[1][i + 2], dp[1][i + 3]);
	}
	dp[1][1] -= dp[1][s_size];

	int res = 0;
	for (int i = 1; i <= 8; i++) {
		res = max(res, max(dp[0][i], dp[1][i]));
	}

	return res;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<int> s;
	int N; cin >> N;

	for (int i = 0; i < N; i++) {
		int n; cin >> n;
		s.push_back(n);
	}
	cout << solution(s);
}