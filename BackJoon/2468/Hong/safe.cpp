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
};

int N, height, counter;
int map[500][500];
bool visit[500][500];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
queue<node> q;
vector<int> sum;

void v_reset()
{
	for (int i = 0; i < 500; i++)
	{
		for (int j = 0; j < 500; j++)
		{
			visit[i][j] = false;
		}
	}
}

void settings()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] > height)
			{
				height = map[i][j];
			}
		}
	}
}

void bfs(int i, int j, int t)
{
	q.push({ i,j });

	while (!q.empty())
	{
		node nd = q.front();
		q.pop();

		visit[nd.x][nd.y] = true;

		for (int i = 0; i < 4; i++)
		{
			int cx = nd.x + dx[i];
			int cy = nd.y + dy[i];

			if (cx >= 0 && cy >= 0 && cx < N && cy < N && !visit[cx][cy] && map[cx][cy] > t)
			{
				q.push({ cx,cy });
				visit[cx][cy] = true;
			}
		}
	}
	counter++;
}

int main()
{
	settings();

	for (int t = 0; t <= height; t++)
	{
		v_reset();
		counter = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (map[i][j] > t && !visit[i][j])
				{
					bfs(i, j, t);
				}
			}
		}
		sum.push_back(counter);
	}

	sort(sum.begin(), sum.end());

	cout << sum[sum.size() - 1];
}