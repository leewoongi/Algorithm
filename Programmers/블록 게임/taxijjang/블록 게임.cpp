#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<cmath>

#define SIZE 110
const int INF = 2e9;

using namespace std;

typedef long long int ll;

int EMPTY = 0;
int BLOCK = 222;

int b_size;

int garo(int x, int y, vector<vector<int>> &board) {
	map<int, int > m; int cnt = 0;
	if (x <= b_size - 2 && y <= b_size - 3) {
		for (int i = y; i < y + 3; i++) {
			m[board[x][i]]++;
			m[board[x + 1][i]]++;
		}



		if (m[BLOCK] == 2 && m.size() == 2 && m.begin()->first != 0) {
			cnt++;
			for (int j = y; j < y + 3; j++) {
				for (int i = 0; i < b_size; i++) {
					if (board[i][j] == m.begin()->first || board[i][j] == EMPTY || board[i][j] == BLOCK)
						board[i][j] = BLOCK;
					else
						break;
				}
			}
		}
	}
	return cnt;
}
bool sero(int x, int y ,vector<vector<int>> &board) {
	map<int, int> m;	int cnt = 0;
	if (x <= b_size - 3 && y <= b_size - 2) {
		for (int i = x; i < x + 3; i++) {
			m[board[i][y]]++;
			m[board[i][y + 1]]++;
		}


	
		if (m[BLOCK] == 2 && m.size() == 2 && m.begin()->first != 0) {
			cnt++;
			for (int j = y; j < y + 2; j++) {
				for (int i = 0; i < b_size; i++) {
					if (board[i][j] == m.begin()->first || board[i][j] == EMPTY || board[i][j] == BLOCK)
						board[i][j] = BLOCK;
					else
						break;
				}
			}
		}
	}
	return cnt;
}
int solution(vector<vector<int>> board) {
	b_size = board.size();
	for (int j = 0; j < b_size; j++) {
		for (int i = 0; i < b_size; i++) {
			board[i][j] = board[i][j] == EMPTY ? BLOCK : board[i][j];
			if (board[i][j] != BLOCK)
				break;
		}
	}

	int res = 0;
	for (int i = 0; i < b_size; i++) {
		for (int k = 0; k < 2; k++) {
			for (int j = 0; j < b_size; j++) {
				res += garo(i, j, board);
				res += sero(i, j, board);
			}
		}
	}
	
	return res;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//vector<vector<int>> board = { {0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,4,0,0,0},{0,0,0,0,0,4,4,0,0,0},{0,0,0,0,3,0,4,0,0,0},{0,0,0,2,3,0,0,0,5,5},{1,2,2,2,3,3,0,0,0,5},{1,1,1,0,0,0,0,0,0,5} };
	//vector<vector<int>> board = { {0,0,2,0}, {1,0,2,0},{1,2,2,0},{1,1,0,0} };
	
	int n; cin >> n;

	vector<vector<int>> board;

	for (int i = 0; i < n; i++) {
		vector<int > b;
		for (int j = 0; j < n; j++) {
			int num; cin >> num; b.push_back(num);
		}
		board.push_back(b);
	}
	cout << solution(board);
	return 0;
}