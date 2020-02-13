#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

typedef struct node
{
	int y;
	int x;
	int result;
}Node;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool visit[16][16];
int map[16][16];
int map_check[16][16];
int init_map[16][16];
vector<vector<Node>>result_test(16);
vector<int>sum;
bool compare(Node n1, Node n2)
{
	if (n1.result == n2.result)
	{
		return n1.x < n2.x;
	}
	else
	{
		return n1.result < n2.result;
	}
}

void init_visit(int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			visit[i][j] = false;
		}
	}
	for (int i = 0; i < m; i++)
	{
		visit[n][i] = true;
	}
}

void move_test(int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == n - 1)
			{
				map[i][j] = 0;
			}
			map_check[i][j] = map[i][j];
			if (i == 0)
			{
				map[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < m; j++)
		{
			map[i + 1][j] = map_check[i][j];
		}
	}
}

bool check_map_zero(int n, int m)
{
	int check_counter = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 0)
			{
				check_counter++;
			}
		}
	}
	if (check_counter == n * m)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void bfs(int n, int m, int d)
{
	queue<Node> Q;
	int check_x;
	int check_y;
	int result = 0;
	while (true)
	{
		for (int i = 0; i < m; i++)
		{
			result_test[i].clear();
			if (map[n][i] == 1)
			{
				init_visit(n, m);
				Q.push({ n,i,0 });
			}
			while (!Q.empty())
			{
				Node no = Q.front();
				Q.pop();
				for (int j = 0; j < 4; j++)
				{

					int x = dx[j] + no.x;
					int y = dy[j] + no.y;
					if (x > -1 && y > -1 && x <= m && y <= n && !visit[y][x])
					{
						Q.push({ y,x,no.result + 1 });
						visit[y][x] = true;
						if (map[y][x] == 1 && (no.result + 1) <= d)
						{
							result_test[i].push_back({ y,x,no.result + 1 });
						}
					}
				}
			}
			sort(result_test[i].begin(), result_test[i].end(), compare);
		}
		for (int i = 0; i < m; i++)
		{
			if (!result_test[i].size())
			{
				continue;
			}
			else
			{
				check_x = result_test[i][0].x;
				check_y = result_test[i][0].y;
			}

			if (result_test.size() && map[check_y][check_x] == 1)
			{
				map[result_test[i][0].y][result_test[i][0].x] = 0;
				result++;
			}
		}
		sum.push_back(result);
		move_test(n, m);
		if (check_map_zero(n, m))
		{
			break;
		}
	}
	result = 0;
}

void init_map_check(int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			map[i][j] = init_map[i][j];
		}
	}
}

int main()
{
	vector<int>V;
	int n, m, d;
	cin >> n >> m >> d;
	Node xyd;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			init_map[i][j] = map[i][j];
		}
	}

	for (int i = 0; i < 3; i++)
	{
		V.push_back(1);
	}
	for (int i = 3; i < m; i++)
	{
		V.push_back(0);
	}
	sort(V.begin(), V.end());
	do {
		for (int i = 0; i < m; i++)
		{
			map[n][i] = V[i];
			visit[n][i] = true;
			if (map[n][i] == 1)
			{

			}
		}
		bfs(n, m, d);
		init_map_check(n, m);
	} while (next_permutation(V.begin(), V.end()));
	sort(sum.begin(), sum.end());
	cout << sum[sum.size() - 1];
	return 0;
}

