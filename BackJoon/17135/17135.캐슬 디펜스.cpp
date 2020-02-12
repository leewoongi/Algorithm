#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <algorithm>

using namespace std;

typedef struct NODE {
	int enemy_pos_x;
	int enemy_pos_y;
	int dis;
}node;

typedef struct INFO {
	int x;
	int y;
}info;


int map[17][17];
int original_map[17][17];
int kill_count = 0;

vector<int> position;
vector<node> v;
vector<info> inf;

bool cmp(const node& x, const node& y) {
	if (x.dis == y.dis) {
		return x.enemy_pos_y < y.enemy_pos_y;
	}
	return x.dis < y.dis;
}



void create_inshotarea(int n, int m, int pos, int d) {
	int start = pos - d;
	int end = pos + d ;

	if (start < 0) {
		start = 0;
	}
	if (end > m - 1) {
		end = m - 1;
	}

	for (int i = start; i <= end; i++) {
		for (int j = n - d; j <= n - 1; j++) {

			int distance = (abs(n - j) + abs(pos - i));

			if (distance <= d) {
				if (map[j][i] == 1) {
					v.push_back({ j, i, distance });
				}
			}
		}
	}

	sort(v.begin(), v.end(), cmp);

	int size = v.size();
	if (size > 0) {

		int x = v[0].enemy_pos_x;
		int y = v[0].enemy_pos_y;
	
		inf.push_back({ x,y });

		while (!v.empty()) {
			v.pop_back();
		}
	}
}

void change_map(int n, int m) {

	for (int i = 0; i <= m; i++) {
		for (int j = n - 1; j >= 0; j--) {
			if (j == 0) {
				map[j][i] = 0;
			}
			else {
				map[j][i] = map[j - 1][i];
			}
		}
	}
}

void kill_enemy() {

	int len = inf.size();
	for (int i = 0; i < len; i++) {
		if (map[inf[i].x][inf[i].y] == 1) {
			map[inf[i].x][inf[i].y] = 0;
			kill_count = kill_count + 1;
		}
	}

	while (!inf.empty()) {
		inf.pop_back();
	}
}


void shot_check(int n, int m, int d) {

	int end = 0;
	while (true) {

		if (n == end) {
			break;
		}

		for (int i = 0; i < m; i++) {
			if (map[n][i] == 1) {

				create_inshotarea(n, m, i, d);

			}
		}

		kill_enemy();
		change_map(n, m);
		end++;
	}
}

void init_map(int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			map[i][j] = original_map[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		map[n][i] = 0;
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	int n, m, d;
	cin >> n >> m >> d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			original_map[i][j] = map[i][j];
		}
	}

	// 궁수위치 정해주기
	int index = 0;
	for (int i = 0; i < m; i++) {
		if (index < 3) {
			position.push_back(1);
			index++;
		}
		else {
			position.push_back(0);
		}
	}

	sort(position.begin(), position.end());


	int result = 0;
	do {

		//궁수 배치
		for (int i = 0; i < m; i++) {
			if (position[i] == 1) {
				map[n][i] = 1;
			}
		}

		shot_check(n, m, d);
		if (result < kill_count) {
			result = kill_count;
		}

		kill_count = 0;
		init_map(n, m);

	} while (next_permutation(position.begin(), position.end()));



	cout << result;
	return 0;
}