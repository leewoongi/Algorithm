#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define INF 21000000

using namespace std;

int player[101][101];
int flag[101];

void init_player() {
	for (int i = 1; i <= 101; i++) {
		for (int j = 1; j <= 101; j++) {
			if (i == j) {
				player[i][j] = 0;
			}
			else {
				player[i][j] = INF;
			}
		}
	}

	for (int i = 1; i <= 101; i++) {
		flag[i] = 0;
	}
}

int solution(int n, vector<vector<int>> results) {
	int answer = 0;

	init_player();

	int size = results.size();
	for (int i = 0; i < size; i++) {
		player[results[i][0]][results[i][1]] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				player[i][j] = min(player[i][j], player[i][k] + player[k][j]);
			}
		}
	}


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {

			if (player[i][j] == 0) {
				continue;
			}

			if (player[i][j] == INF) {
				if (player[j][i] == INF) {
					flag[i] = 1;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (flag[i] == 0) {
			answer++;
		}
	}

	return answer;
}
int main() {

	int n = 5;
	vector<vector<int>> results = {
		{4,3},
		{4,2},
		{3,2},
		{1,2},
		{2,5}
	};

	solution(n, results);

	return 0;
}