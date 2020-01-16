#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct q {
	int x;
	int y;
};

int n, m, counter, v_counter, result, mult, m_add;
int tomato[1002][1002];
bool visit[1002][1002];
int bfs_x[4] = { -1,0,1,0 };
int bfs_y[4] = { 0,1,0,-1 };
bool b_result;

queue<q> que;

int main()
{
	cin >> m >> n;
	mult = m * n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> tomato[i][j];
			if (tomato[i][j] == 1)
			{
				que.push({ i,j });
				visit[i][j] = true;
				v_counter++;
				m_add++;
			}
			else if (tomato[i][j] == -1)
			{
				visit[i][j] = true;
				m_add++;
			}
		}
	}

	while (!que.empty() && !(m_add==mult))
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

				if (rx > 0 && ry > 0 && rx <= n && ry <= m && !visit[rx][ry]&& tomato[rx][ry]==0)
				{
					v_counter++;
					m_add++;
					que.push({ rx,ry });
					visit[rx][ry] = true;
				}
			}
		}
		result++;
	}
	if (m_add == mult)
	{
		cout << result;
	}
	else
	{
		cout << -1;
	}
}
