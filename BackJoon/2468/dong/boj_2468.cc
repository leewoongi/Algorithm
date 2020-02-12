#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int n, m;
int arr[101][101];
bool visit[101][101];
int cnt = 0;
int result = 0;
int max_h = 0;
int dir_x[4] = { -1,0,1,0 };
int dir_y[4] = { 0,-1,0,1 };
typedef struct NODE {
	int x;
	int y;
}node;

queue<node> q;
void inspect(int h) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] <= h) {
				visit[i][j] = true;
			}
			else {
				visit[i][j] = false;
			}
		}
	}
}
void rainy(int h) {
	inspect(h);
	cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] == false) {
				q.push({ i,j });
				visit[i][j] = true;
				while (!q.empty()) {
					node nd = q.front();
					q.pop();

					for (int k = 0; k < 4; k++) {
						int x = nd.x + dir_x[k];
						int y = nd.y + dir_y[k];

						if (x >= 0 && x < n && y >= 0 && y < n) {
							if (visit[x][y] == false && arr[x][y] > h) {
								visit[x][y] = true;
								q.push({ x,y });
							}
						}
					}
				}
				cnt++;
			}

		}
	}
	if (result < cnt) {
		result = cnt;
	}


}
int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];

			if (max_h < arr[i][j]) {
				max_h = arr[i][j];
			}
			
		}
	}
	for (int i = 0; i <= max_h; i++) {
		rainy(i);
	}
	cout << result << '\n';

}