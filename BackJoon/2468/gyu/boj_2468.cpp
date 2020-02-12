#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

typedef struct node {
	int y;
	int x;
}Node;

int maps[101][101];
bool visit[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
vector<int> V;
int max_height = 0;
int check_hegiht = 0;
bool compare(int x, int y)
{
	return x > y;
}

void init_visit()
{
	for (int i = 0; i < 101; i++)
	{
		for (int j=0; j < 101; j++)
		{
			visit[i][j] = false;
		}
	}
}
int sum = 0;
int check = 0;
void bfs(int n)
{
	queue<Node> Q;
	while (true)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!visit[i][j])
				{
					Q.push({ i,j });
					check++;
					visit[i][j] = true;
					break;
				}
			}
			if (!Q.empty())
			{
				break;
			}
		}
		while (!Q.empty())
		{
			Node no = Q.front();
			Q.pop();
			for (int i = 0; i < 4; i++)
			{
				int x = no.x + dx[i];
				int y = no.y + dy[i];
				if (x > -1 && y > -1 && x < n && y < n)
				{
					if (!visit[y][x])
					{
						Q.push({ y,x });
						check++;
						visit[y][x] = true;
					}
				}
			}
		}
		sum++;
		if (check == n * n)
		{
			break;
		}
	}
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> maps[i][j];
			check_hegiht = maps[i][j];
			if (check_hegiht > max_height)
			{
				max_height = check_hegiht;
			}
			
		}
	}
	int rain = 0;
	while (rain <= max_height)
	{
		init_visit();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (maps[i][j] <= rain)
				{
					visit[i][j] = true;
					check++;
				}
			}
			if (check == n*n)
			{
				sum = -1;
			}
		}
		bfs(n);
		V.push_back(sum);
		sum = 0;
		rain++;
		check = 0;
	}
	sort(V.begin(), V.end(), compare);
	cout << V[0] << endl;
	return 0;
}