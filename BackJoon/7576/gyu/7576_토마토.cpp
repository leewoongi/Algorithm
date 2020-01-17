#include<iostream>
#include<queue>

using namespace std;

int tomato[1000][1000];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int result = 0;
int check[1000][1000];
typedef struct node {
	int y;
	int x;
}Node;
queue<Node> Q;
int main()
{
	int n, m;//n=x,m=y
	int x=1, y=1;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> tomato[i][j];
			if (tomato[i][j] == 1)
			{
				Q.push({ i,j });
				check[i][j] = 0;
			}
		}
	}
	while (!Q.empty())
	{
		int cx = Q.front().x;
		int cy = Q.front().y;
		Q.pop();
		for (int i = 0; i < 4; i++)
		{
			x = cx + dx[i];
			y = cy + dy[i];
			if (x<n && y<m && x>-1 && y>-1) 
			{
				if (tomato[y][x] == 0 && check)
				{
					tomato[y][x] = 1;
					check[y][x]=check[cy][cx]+1;
					Q.push({ y,x });
				}
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (tomato[i][j] == 0)
			{
				cout << -1 << endl;
				return 0;
			}
			else
			{
				if (result < check[i][j])
				{
					result = check[i][j];
				}
			}
		}
	}
	cout << result << endl;
}