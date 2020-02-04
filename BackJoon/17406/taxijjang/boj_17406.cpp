#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>

#define SIZE 55

using namespace std;

typedef long long int ll;
typedef struct Data {
	int x, y;
}Data;

typedef struct Loc {
	int r, c, s;
}Loc;
const int INF = 2000000000;
int N, M, K;

vector<Loc> loc;
int board[SIZE][SIZE];
int tmp_board[SIZE][SIZE];
bool visited[10];

void fill_tmp() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			tmp_board[i][j] = board[i][j];
		}
	}
}
int calc_row(int res) {
	for (int i = 1; i <= N; i++) {
		int r_sum = 0;
		for (int j = 1; j <= M; j++) {
			r_sum += tmp_board[i][j];
		}

		res = min(res, r_sum);
	}
	return res;
}
void rotate(int r, int c, int s) {
	
	Data left; left.x = r - s; left.y = c - s;
	Data right; right.x = r + s; right.y = c + s;

	
	while (left.x < right.x && left.y < right.y) {
		int tmp = tmp_board[left.x][left.y];
		//À§
		for (int u_y = left.y + 1; u_y <= right.y; u_y++) {
			int tmp2 = tmp_board[left.x][u_y];
			tmp_board[left.x][u_y] = tmp;
			tmp = tmp2;
		}
		//¿À¸¥ÂÊ
		for (int r_x = left.x + 1; r_x <= right.x; r_x++) {
			int tmp2 = tmp_board[r_x][right.y];
			tmp_board[r_x][right.y] = tmp;
			tmp = tmp2;
		}
		//¹Ø
		for (int d_y = right.y - 1; d_y >= left.y; d_y--) {
			int tmp2 = tmp_board[right.x][d_y];
			tmp_board[right.x][d_y] = tmp;
			tmp = tmp2;
		}
		//¿ÞÂÊ
		for (int l_x = right.x - 1; l_x >= left.x; l_x--) {
			int tmp2 = tmp_board[l_x][left.y];
			tmp_board[l_x][left.y] = tmp;
			tmp = tmp2;
		}

		left.x++; left.y++;
		right.x--; right.y--;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> board[i][j];
		}
	}

	vector<int> idx;
	int index = 0;
	for (int i = 0; i < K; i++) {
		Loc l; cin >> l.r >> l.c >>l. s;
		loc.push_back(l);
		idx.push_back(index++);
	}

	int res = INF;
	do {
		fill_tmp();
		for (auto i : idx) {
			Loc here = loc[i];
			rotate(here.r, here.c, here.s);
		}

		res = calc_row(res);
	} while (next_permutation(idx.begin(), idx.end()));

	cout << res;
	return 0;
}