#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<functional>

#define SIZE 17

using namespace std;

typedef long long int ll;
typedef struct Data {
	int x, y;
}Data;

const int INF = 2000000000;

typedef struct Man {
	int x=INF, y=INF, len = INF;
}Man;


int board[SIZE][SIZE];
int tmp_board[SIZE][SIZE];
Man man_attck[3];
bool man_v[3];
int N, M, D;

vector<int> idx;
vector<Data> man;

int res = 0;

void copy_board() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			tmp_board[i][j] = board[i][j];
		}
	}
}

int down_board() {
	int cnt = 0;
	for (int i = 0; i < 3; i++) {
		if (man_attck[i].x == INF || man_attck[i].y == INF)
			continue;
		if (tmp_board[man_attck[i].x][man_attck[i].y] == 1) {
			tmp_board[man_attck[i].x][man_attck[i].y] = 0;
			cnt++;
		}
	}
	for (int i = N - 1; i >= 0; i--) {
		for (int j = 1; j <= M; j++) {
			tmp_board[i + 1][j] = tmp_board[i][j];
		}
	}

	for (int i = 0; i < 3; i++) {
		man_v[i] = false;
		Man m;
		man_attck[i] = m;
	}

	return cnt;
}

int cnt_board() {
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (tmp_board[i][j] == 1)
				cnt++;
		}
	}
	return cnt;
}

int calc_len(int r1, int c1, int r2, int c2) {
	return abs(r1 - r2) + abs(c1 - c2);
}

void roof() {
	vector<Data> man_arr;
	for (int i = 0; i < M; i++) {
		if (idx[i] == 1) {
			man_arr.push_back(man[i]);
			cout << man[i].x << " " << man[i].y << " ";
		}
	}
	copy_board();
	int cnt = 0;
	while (cnt_board() != 0) {
		for (int i = N; i >= N - D; i--) {
			for (int j = 1; j <= M ; j++) {
				if (tmp_board[i][j] == 1) {
					for (int man_index = 0; man_index < 3; man_index++) {
						int len = calc_len(i, j, man_arr[man_index].x, man_arr[man_index].y);
						if (len <= D) {
							if (man_attck[man_index].len > len) {
								man_attck[man_index].x = i; man_attck[man_index].y = j;
								man_attck[man_index].len = len;
							}
							else if (man_attck[man_index].len == len && man_attck[man_index].y > j) {
								man_attck[man_index].x = i; man_attck[man_index].y = j;
								man_attck[man_index].len = len;
							}
						}
					}
				}
			}
		}
		cnt += down_board();
	}

	cout << " " << cnt << "\n";
	res = max(res, cnt);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> D;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < M; i++) {
		if (i < M - 3)
			idx.push_back(0);
		else
			idx.push_back(1);

		Data m; m.x = N + 1; m.y = i + 1;
		man.push_back(m);
	}

	

	do { 
		roof();
	} while (next_permutation(idx.begin(), idx.end()));

	cout << res;
}
