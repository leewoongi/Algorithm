#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct node {
	int y;
	int x;
	int result;
}Node;

int sea[20][20];
bool visit[20][20];
int shark_size = 2;
int shark_check = 0;
int time=0;
int shark_x;
int shark_y;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
vector<Node> v;
queue<Node> Q;
bool compare(Node v1, Node v2)
{
	if (v1.result == v2.result) //거리값이 같으면
	{
		if (v1.y == v2.y)//위의 값
		{
			return v1.x < v2.x;//왼쪽
		}
		else
		{
			return v1.y < v2.y;//맨위
		}
	}
	else//아니면 거리가 가장 가까운걸로
	{
		return v1.result < v2.result;
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
			cin >> sea[i][j];
			if (sea[i][j] == 9)
			{
				shark_x = j;
				shark_y = i;
				sea[i][j] = 0;
			}
		}
	}
	while (true)
	{
		Q.push({ shark_y,shark_x ,0});
		visit[shark_y][shark_x] = true;
		while (!Q.empty())
		{
			Node no = Q.front();
			Q.pop();
			for (int i = 0; i < 4; i++)
			{
				int x = dx[i] + no.x;
				int y = dy[i] + no.y;
				if (x > -1 && y > -1 && x < n && y < n)
				{
					if (!visit[y][x]) 
					{
						if (sea[y][x] <= shark_size)
						{
							Q.push({ y,x,no.result+1 });
							visit[y][x] = true;
						}
						if (sea[y][x] < shark_size && sea[y][x] != 0)
						{
							visit[y][x] = true;
							v.push_back({ y,x ,no.result+1 });
							Q.push({ y,x,no.result+1 });
						}
					}
				}
			}
		}
		sort(v.begin(), v.end(), compare);
		int vector_size = v.size();
		if (!v.size())
		{
			break;
		}
		if (v.size())
		{
			shark_check++;
			sea[v[0].y][v[0].x]=0;
		}
		if (shark_check == shark_size)
		{
			shark_size++;
			shark_check = 0;
		}
		shark_x = v[0].x;
		shark_y = v[0].y;
		time += v[0].result;
		for (int i = 0; i < vector_size; i++)
		{
			v.pop_back();
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				visit[i][j] = false;
			}
		}
	}
	cout << time << endl;
}

