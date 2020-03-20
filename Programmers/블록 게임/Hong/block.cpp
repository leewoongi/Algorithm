#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cmath>
#include<stack>

using namespace std;

int st;

bool check(vector<vector<int>> board, int x, int y)
{
	int index = board[x][y];
	int n = board.size();


		if (x + 1 < n && x + 1 >= 0)
		{
			if (board[x + 1][y] == index)
			{
				if (x + 1 < n && y + 2 < n && x + 1 >= 0 && y + 2 >= 0)
				{
					if (board[x + 1][y + 1] == index)
					{
						if (board[x + 1][y + 2] == index)
						{
							st = 1;
							return true;
						}
					}
				}

				if (x + 2 < n && y - 1 < n && x + 2 >= 0 && y - 1 >= 0)
				{
					if (board[x + 2][y] == index)
					{
						if (board[x + 2][y - 1] == index)
						{
							st = 2;
							return true;
						}
					}
				}

				if (x + 2 < n && y + 1 < n && x + 2 >= 0 && y + 1 >= 0)
				{
					if (board[x + 2][y] == index)
					{
						if (board[x + 2][y + 1] == index)
						{
							st = 3;
							return true;
						}
					}
				}

				if (x + 1 < n && y - 2 < n && x + 1 >= 0 && y - 2 >= 0)
				{
					if (board[x + 1][y - 1] == index)
					{
						if (board[x + 1][y - 2] == index)
						{
							st = 4;
							return true;
						}
					}
				}

				if (x + 1 < n && y - 1 < n && x + 1 >= 0 && y - 1 >= 0 && y+1 <n && y+1>=0)
				{
					if (board[x + 1][y - 1] == index)
					{
						if (board[x + 1][y + 1] == index)
						{
							st = 5;
							return true;
						}
					}
				}
			}
		}

	return false;
}

bool block(vector<vector<int>> board, int x, int y)
{
	int n = board[x][y];

	if (st == 1)
	{
		for (int i = x; i >= 0; i--)
		{
			if (board[i][y + 1] != 0 || board[i][y+2] !=0)
			{
				return false;
			}
		}
	}
	else if (st == 2)
	{
		for (int i = x+1; i >= 0; i--)
		{
			if (board[i][y - 1] != 0)
			{
				return false;
			}
		}
	}
	else if (st == 3)
	{
		for (int i = x + 1; i >= 0; i--)
		{
			if (board[i][y + 1] != 0)
			{
				return false;
			}
		}
	}
	else if (st == 4)
	{
		for (int i = x; i >= 0; i--)
		{
			if (board[i][y - 1] != 0 || board[i][y - 2] != 0)
			{
				return false;
			}
		}
	}
	else if (st == 5)
	{
		for (int i = x; i >= 0; i--)
		{
			if (board[i][y - 1] != 0 || board[i][y + 1] != 0)
			{
				return false;
			}
		}
	}

	return true;
}

int solution(vector<vector<int>> board) {
	int answer = 0;
	bool loop = true;

	while (loop)
	{
		loop = false;
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board.size(); j++)
			{
				if (board[i][j] != 0)
				{
					int number = board[i][j];

					if (check(board, i, j)) // 삭제 될 수 있는 모양 인지 확인
					{
						if (block(board, i, j))//삭제 될 수 있는 모양이면 위에 장애물 없는지 확인 
						{
							for (int q = 0; q < board.size(); q++)
							{
								for (int w = 0; w < board.size(); w++)
								{
									if (board[q][w] == number)
									{
										board[q][w] = 0;
									}
								}
							}
							answer++;
							loop = true;
							//그 숫자 0으로 변경
						}
					}
				}
			}
		}
	}

	return answer;
}

int main()
{
	vector<vector<int>> board = {
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
	};

	cout << solution(board);

}