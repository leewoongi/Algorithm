#include <iostream>
#include <queue>
using namespace std;

typedef struct NODE {
	int x;
	int y;
}node;

int map[101][101];
bool visit[101][101];

int dir_x[4] = { -1,0,1,0 };
int dir_y[4] = { 0,1,0,-1 };

queue<node> q;
void safe_rand(int x, int y, int n, int water) {

	q.push({ x,y });
	visit[x][y] = true;

	while (!q.empty()) {
		node p = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int n_x = p.x + dir_x[i];
			int n_y = p.y + dir_y[i];

			if (n_x >= 0 && n_x < n && n_y >= 0 && n_y < n) {
				if (visit[n_x][n_y] == false) {

					// 다음 위치가 물에 잠기는 높이가 아니라면
					if (map[n_x][n_y] > water) {
						visit[n_x][n_y] = true;
						q.push({ n_x, n_y });
					}
				}
			}
		}
	}
}

void init_visit(int n) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visit[i][j] = false;
		}
	}
}

int sum = 0;
void check_rand(int n, int visit_count) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			if (map[i][j] > visit_count && visit[i][j] == false) {

				safe_rand(i, j, n, visit_count);
				sum = sum + 1;

			}
		}
	}

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	int max_height = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (max_height < map[i][j]) {
				max_height = map[i][j];
			}
		}
	}

	int visit_count = 0;
	int max_rand = 0;

	while (visit_count < max_height) {

		// 안전지역 체크하기
		check_rand(n, visit_count);

		// 최대 안전지역 구하기
		if (max_rand < sum) {
			max_rand = sum;
		}

		// 방문횟수 초기화
		sum = 0;

		// 물의 높이 높이기
		visit_count = visit_count + 1;

		init_visit(n);

	}
	
	cout << max_rand;
	return 0;
}