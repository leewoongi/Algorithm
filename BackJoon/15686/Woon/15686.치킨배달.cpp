#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <queue>

using namespace std;


typedef struct NODE {
	int x;
	int y;
}node;

int map[51][51];
int tmp_map[51][51];
bool visit[51][51];

int dir_x[4] = { -1,0,1,0 };
int dir_y[4] = { 0,1,0,-1 };

vector<node> v;
vector<int> index;
queue<node> q;

void init_map(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				v.push_back({ i,j });
			}
		}
	}
}

void init_tmpmap(int n) {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			tmp_map[i][j] = map[i][j];
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	init_map(n);
	init_tmpmap(n);

	int size = v.size();

	for (int i = 0; i < size; i++) {
		if (i < size - m) {
			index.push_back(0);
		}
		else {
			index.push_back(1);
		}
	}


	vector<int> answer;
	do {
		for (int i = 0; i < size; i++) {
			if (index[i] == 0) {
				node p = v[0];
				tmp_map[p.x][p.y] = 0;
			}
		}

		int sum = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (tmp_map[i][j] == 1) {
					int result = 210000000;

					//치킨집이랑 거리 구하기
					for (int k = 0; k < size; k++) {
						if (index[k] == 1) {
							node store = v[k];
							int dis = abs(store.x - i) + abs(store.y - j);

							if (dis < result) {
								result = dis;
							}
						}

					}

					sum = sum + result;
				}
			}
		}

		answer.push_back(sum);
		init_tmpmap(n);

	} while (next_permutation(index.begin(), index.end()));

	sort(answer.begin(), answer.end());
	cout << answer[0];

	return 0;
}
