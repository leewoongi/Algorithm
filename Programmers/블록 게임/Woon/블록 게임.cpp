#include <string>
#include <map>
#include <vector>

using namespace std;


int gameboard[51][51];

int init_board(int size, vector<vector<int>> board) {
	bool flag = false;
	int x = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			gameboard[i][j] = board[i][j];
			if (flag == false && gameboard[i][j] != 0) {
				flag = true;
				x = i;
			}
		}
	}
	return x;
}


void change_board(int size) {

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {

			if (gameboard[j][i] == 209) {
				continue;
			}
			else if (gameboard[j][i] != 0 && gameboard[j][i] != 209) {
				break;
			}
			else {
				gameboard[j][i] = 209;
			}
		}
	}
}

void row_change(int x, int y) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			gameboard[x + i][y + j] = 0;
		}
	}
}


bool check_row(int x, int y) {

	int b_count = 0;
	int tmp_count = 0;
	map<int,int> m;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			if (gameboard[x + i][y + j] == 209) {
				if (m.find(gameboard[x + i][y + j]) == m.end()) {
					m[gameboard[x + i][y + j]]++;
				}
				b_count++;
			}
			else if (gameboard[x + i][y + j] != 209 && gameboard[x + i][y + j] != 0) {
				if (m.find(gameboard[x + i][y + j]) == m.end()) {
					m[gameboard[x + i][y + j]]++;
				}
				tmp_count++;
			}
		}
	}
	int size = m.size();
	if (b_count == 2 && tmp_count == 4 && size == 2) {
		row_change(x,y);
		return true;
	}

	return false;
}



void col_change(int x, int y) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			gameboard[x + i][y + j] = 0;
		}
	}
}

bool check_col(int x, int y) {

	int b_count = 0;
	int tmp_count = 0;
	map<int, int> m;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			if (gameboard[x + i][y + j] == 209) {
				if (m.find(gameboard[x + i][y + j]) == m.end()) {
					m[gameboard[x + i][y + j]]++;
				}
				b_count++;
			}
			else if (gameboard[x + i][y + j] != 209 && gameboard[x + i][y + j] != 0) {
				if (m.find(gameboard[x + i][y + j]) == m.end()) {
					m[gameboard[x + i][y + j]]++;
				}
				tmp_count++;
			}
		}
	}
	int size = m.size();
	if (b_count == 2 && tmp_count == 4 && size == 2) {
		col_change(x, y);
		return true;
	}
	return false;
}


int solution(vector<vector<int>> board) {
	int answer = 0;
	int size = board.size();

	int index = init_board(size, board);
	change_board(size);

	bool tmp_row = true;
	bool tmp_col = true;

	while (true) {
		
		if (tmp_row == false && tmp_col == false) {
			break;
		}

		tmp_row = false;
		tmp_col = false;

		//가로
		for (int i = index; i < size - 1; i++) {
			for (int j = 0; j < size - 2; j++) {
				bool row = check_row(i, j);

				if (row == true) {
					change_board(size);
					answer = answer + 1;
					tmp_row = true;
				}
			}
		}

		//세로
		for (int i = index; i < size - 2; i++) {
			for (int j = 0; j < size - 1; j++) {
				bool col = check_col(i,j);

				if (col == true) {
					change_board(size);
					answer = answer + 1;
					tmp_col = true;
				}
			}
		}
	}

	return answer;
}

int main() {

	/*vector<vector<int>> board = {
	   {0,0,0,0,0,0,0,0,0,0},
	   {0,0,0,0,0,0,0,0,0,0},
	   {0,0,0,0,0,0,0,0,0,0},
	   {0,0,0,0,0,0,0,0,0,0},
	   {0,0,0,0,0,0,4,0,0,0},
	   {0,0,0,0,0,4,4,0,0,0},
	   {0,0,0,0,3,0,4,0,0,0},
	   {0,0,0,2,3,0,0,0,5,5},
	   {1,2,2,2,3,3,0,0,0,5},
	   {1,1,1,0,0,0,0,0,0,5}
	};*/

	
	/*vector<vector<int>> board = {
	   {0,0,0,0,0,0},
	   {0,0,0,0,0,0},
	   {0,0,0,0,0,0},
	   {0,0,0,0,0,0},
	   {0,0,0,0,0,0},
	   {0,0,0,0,0,0}
	};*/

	vector<vector<int>> board = {
	   {0,0,0,5,0,0},
	   {0,5,5,5,4,0},
	   {0,2,2,0,4,4},
	   {1,0,2,0,4,0},
	   {1,0,2,0,3,0},
	   {1,1,0,3,3,3}
	};
	solution(board);

	return 0;
}