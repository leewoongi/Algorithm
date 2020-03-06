#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct node
{
	int x;
	int y;
	int d;
	int n;
};

int N, M, result;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int map[1010][1010];
bool visit[1010][1010][2];
queue<node> q;

void bfs()
{
	visit[1][1][0] = true;
	bool check = false;
	while (!q.empty())
	{
		node val;
		val = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int cx = val.x + dx[i];
			int cy = val.y + dy[i];

			if (cx > 0 && cy > 0 && cx <= N && cy <= M && val.n < 2)
			{
				if (!visit[cx][cy][val.n] && map[cx][cy] == 0)
				{
					visit[cx][cy][val.n] = true;
					q.push({ cx, cy, val.d + 1, val.n });
					if (cx == N && cy == M)
					{
						result = val.d + 1;
						check = true;
						while (!q.empty())
						{
							q.pop();
						}
					}
				}
				else if (map[cx][cy] == 1 && val.n == 0)
				{
					visit[cx][cy][1] = true;
					q.push({ cx,cy,val.d + 1,val.n + 1 });
					if (cx == N && cy == M)
					{
						result = val.d + 1;
						check = true;
						while (!q.empty())
						{
							q.pop();
						}
					}
				}
			}
		}
	}
	if (!check)
	{
		result = -1;
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	q.push({ 1,1,1,0 });

	if (N == 1 && M == 1)
	{
		result = 1;
	}
	else
		bfs();

	cout << result;
}