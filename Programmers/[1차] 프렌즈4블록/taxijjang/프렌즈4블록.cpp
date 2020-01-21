#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>

#define INF 2e9
#define SIZE 40

using namespace std;

typedef long long int ll;

int dx[3] = { 0,1, 1 };
int dy[3] = { 1,1 ,0 };

bool visited[SIZE][SIZE];

char arr[SIZE][SIZE];
void fill_v() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			visited[i][j] = false;
		}
	}
}

void change_v(int h_x, int h_y) {
	visited[h_x][h_y] = true;
	for (int i = 0; i < 3; i++) {
		visited[h_x + dx[i]][h_y + dy[i]] = true;
	}
}
bool check(int h_x, int h_y) {
	int cnt = 0;
	char here_chr = arr[h_x][h_y];

	for (int i = 0; i < 3; i++) {
		int n_x = h_x + dx[i];
		int n_y = h_y + dy[i];

		if (arr[n_x][n_y] == here_chr)
			cnt++;
	}

	if (cnt == 3)
		change_v(h_x, h_y);
	return (cnt == 3 ? true : false);
}

void del_arr(int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == true)
				arr[i][j] = '0';
		}
	}
}

void down_arr(int m, int n) {
	for (int i = 0; i < n; i++) {
		int zero_cnt = 0;
		for (int j = m - 1; j >= 0; j--) {
			if (arr[j][i] == '0')
				zero_cnt++;
			else {
				arr[j + zero_cnt][i] = arr[j][i];
				arr[j][i] = zero_cnt != 0 ? '0' : arr[j][i];
			}
		}
	}
}

int cnt_arr(int m, int n) {
	int res = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			res += arr[i][j] == '0' ? 1 : 0;
		}
	}
	return res;
}
int solution(int m, int n, vector<string> board) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = board[i][j];
		}
	}
	int judge = 1;

	while (judge != 0) {
		judge = 0;
		for (int i = 0; i < m - 1; i++) {
			for (int j = 0; j < n - 1; j++) {
				if (arr[i][j] != '0') {
					judge += check(i, j) == true ? 1 : 0;
				}
			}
		}
		//지우기
		del_arr(m, n);

		//내리기
		down_arr(m, n);

		fill_v();
	}

	return cnt_arr(m, n);

}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int M, N; cin >> M >> N;

	vector<string> board;

	for (int i = 0; i < M; i++) {
		string s; cin >> s;
		board.push_back(s);
	}
	
	cout << solution(M, N, board);
}