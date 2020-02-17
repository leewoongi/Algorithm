#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;


int map[16][16];
int copy_map[16][16];
int visit_pos;
int n, m;
int limit;
int arrow[3];
int minimum = 1000000;
int index_x;
int index_y;
int cnt = 0;
int result = 0;
int visit[16][16];
int tmp_visit[16][16];
void reset_map() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			map[i][j] = copy_map[i][j];
		}
	}
}
void reset_visit() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visit[i][j] = false;
			tmp_visit[i][j] = false;
		}
	}
}
void finalize() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tmp_visit[i][j] = visit[i][j];
			if (visit[i][j] == true) {
				map[i][j] = 0;
			}
		}
	}
}
void castle() {
	cnt = 0;
	reset_visit();
	for (int i = n - 1; i >= 0; i--) {

		for (int ar = 0; ar < 3; ar++) {
			minimum = 1000000;
			index_x = n;
			index_y = m;
			for (int j = 0; j < limit; j++) {
				for (int k = m - 1; k >= 0; k--) {
					int abs_re = abs(visit_pos - (i - j)) + abs(arrow[ar] - k);
					if (abs_re <= minimum && abs_re <= limit && map[i - j][k] == 1 && tmp_visit[i - j][k] == false) {
						if (index_y < k && minimum == abs_re) {//같은줄 같은거리 전의 값보다 오른쪽에 있으면 넘기기
							continue;
						}
						if (index_x < i - j && index_y < k && minimum == abs_re) {//다른 줄 같은 거리 전 값보다 오른쪽에 있으면 넘기기
							continue;
						}
						else {
							minimum = abs_re;
							index_x = i - j;
							index_y = k;
						}
					}

				}

			}
			if (minimum <= limit && visit[index_x][index_y] == false) {
				if (index_x == n && index_y == m) {
					continue;
				}
				visit[index_x][index_y] = true;
				cnt++;
			}

		}
		finalize();
		visit_pos--;
	}
	if (cnt >= result) {
		result = cnt;
	}

}
void location() {
	for (int i = 0; i < m - 2; i++) {
		for (int j = i + 1; j < m - 1; j++) {
			for (int k = j + 1; k < m; k++) {

				arrow[0] = i;
				arrow[1] = j;
				arrow[2] = k;
				reset_map();
				visit_pos = n;
				castle();
			}
		}
	}
	cout << result << '\n';

}
int main() {
	cin >> n >> m >> limit;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			copy_map[i][j] = map[i][j];
		}
	}
	location();
}