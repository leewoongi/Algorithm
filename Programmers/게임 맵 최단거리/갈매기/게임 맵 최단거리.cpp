#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int board[100][100];
int result[100][100];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
typedef struct node
{
	int y;
	int x;
}Node;
int solution(vector<vector<int>> maps)
{
	int answer = 0;
	int n = maps.size();
	int m = maps[0].size();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			board[i][j] = maps[i][j];
		}
	}
	result[0][0] = 1;
	queue<Node> Q;
	Q.push({ 0,0 });
	while (!Q.empty())
	{
		Node no= Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++)
		{
			int x = dx[i] + no.x;
			int y = dy[i] + no.y;
			if (x > -1 && y > -1 && x < m && y < n)
			{
				if (board[y][x] == 1 && result[y][x] == 0)
				{
					Q.push({ y,x });
					result[y][x] = result[y - dy[i]][x - dx[i]] + 1;
				}
			}
		}
	}
	if (result[n-1][m-1] == 0)
	{
		return -1;
	}
	else 
	{
		answer = result[n - 1][m - 1];
		return answer;
	}
}

int main()
{
	vector<vector<int>> maps=
	{    {1,0,1,1,1}
		,{1,0,1,0,1}
		,{1,0,1,1,1}
		,{1,1,1,0,0}
		,{0,0,0,0,1}
	};
	cout << solution(maps) << endl;
	return 0;
}