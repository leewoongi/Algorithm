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
int dp[SIZE];

int solution(vector<int> sticker)
{
	int s_size = sticker.size();
	int res = 0;
	for (int i = 0; i < s_size; i++) {
		arr[i + 1] = sticker[i];
	}
	//첫번째 쓰고 마지막 안썻을때
	dp[1] = arr[1];
	dp[2] = arr[2];

	res = max(res, max(dp[1], dp[2]));
	for (int i = 3; i < s_size; i++) {
		dp[i] = arr[i] + max(dp[i - 2], dp[i - 3]);
		res = max(res, dp[i]);
	}

	//첫번째 안쓰고 마지막 썻을때
	dp[1] = 0;
	dp[2] = arr[2];

	for (int i = 3; i <= s_size; i++) {
		dp[i] = arr[i] + max(dp[i - 2], dp[i - 3]);
		res = max(res, dp[i]);
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