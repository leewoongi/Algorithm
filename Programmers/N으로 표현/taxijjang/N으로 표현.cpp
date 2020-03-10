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

int res = INF;

void dfs(int *N, int *number, int index, int sum) {
	if (index > 8)
		return;

	if (sum == *number)
		res = min(res, index);

	int tmp = 0;

	for (int i = 0; i < 8; i++) {
		tmp = tmp * 10 + *N;
		dfs(N, number, index + i + 1, sum + tmp);
		dfs(N, number, index + i + 1, sum - tmp);
		dfs(N, number, index + i + 1, sum * tmp);
		dfs(N, number, index + i + 1, sum / tmp);
	}
}
int solution(int N, int number) {
	dfs(&N, &number, 0, 0);
	if (res > 8)
		return -1;
	else
		return res;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, number; cin >> N >> number;
	cout << solution(N, number);
}