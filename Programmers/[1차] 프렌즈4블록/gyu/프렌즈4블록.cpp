#include<iostream>
#include<vector>

using namespace std;

bool visit[31][31];
int solution(int m, int n, vector<string> board)
{
	int answer = 0;
	while (true)
	{
		bool find = false;
		for (int i = 0; i < m - 1; i++)
		{
			for (int j = 0; j < n - 1; j++)
			{
				char block = board[i][j];
				if (block != ' '&&block == board[i][j + 1] && block == board[i + 1][j] && block == board[i + 1][j + 1])
				{
					visit[i][j] = true;
					visit[i][j + 1] = true;
					visit[i + 1][j] = true;
					visit[i + 1][j + 1] = true;
					find = true;
				}
			}
		}
		if (!find)
		{
			break;
		}
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (visit[i][j])
				{
					board[i][j] = ' ';
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			int k = 0;
			for (int j = m - 1; j >= 0; j--)
			{
				if (board[j][i] == ' ')
				{
					k++;
				}
				else
				{
					board[j + k][i] = board[j][i];
					if (k != 0)
					{
						board[j][i] = ' ';
					}
				}
			}
		}
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				visit[i][j] = false;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == ' ') {
				answer++;
			}
		}
	}
	return answer;
}

int main()
{
	int m, n;
	m = 4;
	n = 5;
	vector<string> v = { "CCBDE", "AAADE", "AAABF", "CCBBF" };
	//vector<string> v = { "TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ " };
	cout << solution(m, n, v) << endl;
}