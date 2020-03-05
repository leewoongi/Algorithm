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

#define SIZE 110
#define MOD 1000000007
const int INF = 2000000000;

using namespace std;

typedef long long int ll;

int board[SIZE][SIZE];
map<pair<int, int>, int> _map;
int solution(int m, int n, vector<vector<int>> puddles) {
	for (auto p : puddles) _map[{p[0], p[1]}] = 1;
	for (int i = 1; i <= m; i++) {
		if (_map[{i, 1}] == 1) break;
		board[i][1] = 1;
	}
	for (int j = 1; j <= n; j++) {
		if (_map[{1, j}] == 1)  break;
		board[1][j] = 1;
	}


	for (int i = 1; i < m; i++) {
		for (int j = 1; j <= n; j++) {
			board[i + 1][j] = (board[i][j] + board[i + 1][j - 1]) % MOD;
			if (_map[{i + 1, j}] == 1)board[i + 1][j] = 0;
		}
	}

	return board[m][n] % MOD;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<vector<int>> puddles;
	vector<int> puddle = { 2,2 };
	puddles.push_back(puddle);
	cout << solution(4, 3, puddles);
}