#include <iostream>
#include <stack>
#include <vector>
using namespace std;


typedef struct NODE {
	int x;
	int y;
}node;

int map[16][16];
int dir_x[4] = { -1,0,1,0 };
int dir_y[4] = { 0,1,0,-1 };
bool visited[16][16];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	for (int tc = 1; tc <= 10; tc++) {

		int number;
		cin >> number;

		//map √ ±‚»≠
		int start_x, start_y;
		int end_x, end_y;

		for (int i = 0; i < 16; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < 16; j++) {
				map[i][j] = s[j] - '0';

				if (map[i][j] == 2) {
					start_x = i;
					start_y = j;
				}
				else if (map[i][j] == 3) {
					end_x = i;
					end_y = j;
				}
			}
		}

		stack<node> st;
		st.push({ start_x,start_y });
		visited[start_x][start_y] = true;

		int result = 0;
		while (!st.empty()) {

			node n = st.top();
			st.pop();

			if (n.x == end_x && n.y == end_y) {
				result = 1;
				break;
			}

			for (int i = 0; i < 4; i++) {
				int x = n.x + dir_x[i];
				int y = n.y + dir_y[i];

				if (x >= 0 && x < 16 && y >= 0 && y < 16) {
					if (visited[x][y] == false && map[x][y] != 1) {
						st.push({ x,y });
						visited[x][y] = true;
					}
				}
			}
		}

		cout << "#" << tc << " " << result << "\n";

		for (int i = 0; i < 16; i++) {
			for (int j = 0; j < 16; j++) {
				visited[i][j] = false;
			}
		}
		if (!st.empty()) {
			while (st.empty()) {
				st.pop();
			}
		}
	}

	return 0;
}