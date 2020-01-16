#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct q {
	int x;
	int y;
};

int n, m, counter, v_counter, result;
int maze[102][102];
bool visit[102][102];
int bfs_x[4] = { -1,0,1,0 };
int bfs_y[4] = { 0,1,0,-1 };
bool b_result;

queue<q> que;

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%1d", &maze[i][j]);
		}
	}

	que.push({ 1,1 });
	v_counter = 1;
	visit[1][1] = true;

	while (1)
	{
		q que_value;
		int rx, ry;
		counter = v_counter;
		v_counter = 0;
		
		for (int i = 0; i < counter; i++)
		{
			que_value = que.front();
			que.pop();
			for (int j = 0; j < 4; j++)
			{
				rx = que_value.x + bfs_x[j];
				ry = que_value.y + bfs_y[j];

				if (rx > 0 && ry > 0 && rx <= n && ry <= m && !visit[rx][ry]&& maze[rx][ry]==1)
				{
					v_counter++;
					que.push({ rx,ry });
					visit[rx][ry] = true;
					if (rx == n && ry == m)
					{
						b_result = true;
					}
				}
			}
		}
		if (b_result)
		{
			break;
		}
		else
			result++;
	}
	cout << result + 2;
}