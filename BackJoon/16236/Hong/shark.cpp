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
	int z;
};

int N, time, f_up;
int ar[30][30];
int f_size = 2;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
bool visit[500][500];

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

bool cmp(node v1, node v2)
{
	// 거리가 같을때
	if (v1.z == v2.z)
	{
		//위에가 같을때
		if (v1.x == v2.x)
		{
			return v1.y < v2.y;
		}
		//위에가 다를때
		else
		{
			return v1.x < v2.x;
		}

	}
	//거리가 다를떄
	else {
		return v1.z < v2.z;
	}

}

queue<node> q;
vector<node> vec;

void bfs()
{
	int d = 1;

	while (!q.empty())
	{
		int loof = q.size();
		for (int j = 0; j < loof; j++)
		{
			node qval = q.front();
			q.pop();
			visit[qval.x][qval.y] = true;
			for (int i = 0; i < 4; i++)
			{
				if (qval.x + dx[i] >= 0 && qval.y + dy[i] >= 0 && qval.x + dx[i] < N
					&& qval.y + dy[i] < N && ar[qval.x + dx[i]][qval.y + dy[i]] <= f_size &&
					!visit[qval.x + dx[i]][qval.y + dy[i]])
				{
					q.push({ qval.x + dx[i] ,qval.y + dy[i] });
					if (ar[qval.x + dx[i]][qval.y + dy[i]] < f_size && ar[qval.x + dx[i]][qval.y + dy[i]] != 0)
					{
						vec.push_back({ qval.x + dx[i] , qval.y + dy[i] , d });
					}
				}
				visit[qval.x + dx[i]][qval.y + dy[i]] = true;
			}
		}
		d++;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int f;
			cin >> ar[i][j];
			if (ar[i][j] == 9)
			{
				q.push({ i,j });
				ar[i][j] = 0;
			}
		}
	}

	while (1)
	{
		v_reset();
		node q_node;
		bfs();
		if (!vec.empty())
		{
			sort(vec.begin(), vec.end(), cmp);
			q_node = vec.front();
			q.push({ q_node.x,q_node.y });
			time += q_node.z;
			f_up++;
			if (f_up == f_size && f_size < 8)
			{
				f_size++;
				f_up = 0;
			}
			ar[q_node.x][q_node.y] = 0;
			vec.clear();
		}
		else
		{
			break;
		}
	}

	cout << time;
}