#include <iostream>
#include<vector>
#include<queue>

using namespace std;

typedef struct NODE {
	int x;
	int y;
	int d;
}node;

int board[101][101];
int dp[101][101];
bool visit[101][101];

int dir_x[4] = { -1,0,1,0 };
int dir_y[4] = { 0,1,0,-1 };

queue<node> q;
int solution(vector<vector<int> > maps)
{
	int answer = 0;

	int col = maps.size();
	int row = maps[0].size();

	for (int i = 0; i < col; i++) {
		for(int j = 0; j < row; j++){
			board[i + 1][j + 1] = maps[i][j];
		}
	}


	int start_x = 1;
	int start_y = 1;

	visit[start_x][start_y] = true;
	q.push({ start_x, start_y, 1 });

	int result = 0;
	while (!q.empty()) {

		node p = q.front();
		q.pop();

		if (p.x == col && p.y == row) {
			result = p.d;
			break;
		}


		for (int i = 0; i < 4; i++) {
			int x = p.x + dir_x[i];
			int y = p.y + dir_y[i];

			if (x >= 1 && x <= col && y >= 1 && y <= row) {
				if (visit[x][y] == false && board[x][y] == 1) {
					visit[x][y] = true;
					q.push({ x, y, p.d + 1 });
				}
			}
		}
	}

	if (result == 0) {
		answer = -1;
	}
	else {
		answer = result;
	}


	return answer;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	/*vector<vector<int>> v = {
		{1,0,1,1,1},
		{1,0,1,0,1},
		{1,0,1,1,1},
		{1,1,1,0,1},
		{0,0,0,0,1}

	};*/

	vector<vector<int>> v = {

		{1,0,1,1,1},
		{1,0,1,0,1},
		{1,0,1,1,1},
		{1,1,1,0,0},
		{0,0,0,0,1}

	};


	cout << solution(v);
	
	return 0;
}