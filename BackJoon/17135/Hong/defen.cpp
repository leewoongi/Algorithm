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
};

int map[20][20];
int map_s[20][20];
bool visit[20][20];
int N, M, D, counter;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
queue<node> q;
vector<vector<node>> at(3);
vector<int> a_index, o_index;
node archer[3];
vector<int> sum;

void reset()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			map[i][j] = 9;
		}
	}
}

void v_reset()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			visit[i][j] = false;
		}
	}
}

void move()
{
	for (int i = 0; i < M; i++)
	{
		map[N - 1][i] = 0;
	}

	for (int i = N - 2; i >= 0; i--)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 1)
			{
				map[i+1][j] = 1;
				map[i][j] = 0;
			}
		}
	}
}

bool m_check()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 1)
				return true;
		}
	}
	return false;
}
bool cmp(node n1, node n2)
{
	if (n1.d != n2.d)
	{
		return n1.d < n2.d;
	}
	else
	{
		return n1.y < n2.y;
	}
}
void settings()
{
	cin >> N >> M >> D;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map_s[i][j];
		}
	}

	for (int i = 0; i < M; i++)
	{
		a_index.push_back(i);
	}

	for (int i = 0; i < 3; i++)
	{
		o_index.push_back(1);
	}

	for (int i = 0; i < M - 3; i++)
	{
		o_index.push_back(0);
	}

	sort(a_index.begin(), a_index.end());
	sort(o_index.begin(), o_index.end());
}

void mapsetting()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			map[i][j] = map_s[i][j];
		}
	}
}

void bfs()
{
	bool check = true;

	while (check)
	{
		check = false;

		for (int i = 0; i < 3; i++)
		{
			at[i].clear();
			v_reset();
			q.push({ archer[i].x, archer[i].y, archer[i].d });

			while (!q.empty())
			{
				node qv = q.front();
				q.pop();

				for (int j = 0; j < 4; j++)
				{
					int cx = qv.x + dx[j];
					int cy = qv.y + dy[j];

					if (cx >= 0 && cy >= 0 && cx < N && cy < M && !visit[cx][cy])
					{
						q.push({ cx,cy,(qv.d) + 1 });
						visit[cx][cy] = true;
						if (map[cx][cy] == 1 && ((qv.d)+1) <= D)
						{
							at[i].push_back({ cx,cy,(qv.d) + 1 });
						}
					}
				}
			}

			sort(at[i].begin(), at[i].end(), cmp);
		}

		for (int i = 0; i < 3; i++)
		{
			if(!at[i].empty())
			{ 
				if (map[at[i][0].x][at[i][0].y] == 1)
				{
					map[at[i][0].x][at[i][0].y] = 0;
					counter++;
				}
			}
		}

		move();
		check = m_check();
	}

	sum.push_back(counter);
	counter = 0;
}

int main()
{
	reset();

	settings();
	
	do
	{
		mapsetting();
		int counter = 0;
		int a = 0;
		for (int i = 0; i < o_index.size(); i++)
		{
			if (o_index[i] == 1)
			{
				archer[a].x = N;
				archer[a].y = i;
				archer[a].d = 0;
				a++;
			}
		}

		bfs();


	} while (next_permutation(o_index.begin(), o_index.end()));

	sort(sum.begin(), sum.end());

	cout << sum[sum.size() - 1];

}