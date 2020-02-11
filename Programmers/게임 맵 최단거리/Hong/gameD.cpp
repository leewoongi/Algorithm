#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int visit[105][105];

struct node
{
	int x;
	int y;
	int d;
};

int bfs(vector<vector<int> > maps)
{
	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,1,0,-1 };
	int n = maps.size();
	int m = maps[0].size();
	queue<node> q;

	q.push({ 0,0,1 });
	visit[0][0] = true;

	while (!q.empty())
	{
		node val;
		val = q.front();
		q.pop();

		if (val.x == n - 1 && val.y == m - 1)
		{
			return val.d;
		}

		for (int i = 0; i < 4; i++)
		{
			int cx = val.x + dx[i];
			int cy = val.y + dy[i];

			if (cx >= 0 && cy >= 0 && cx < n && cy < m && !visit[cx][cy] && maps[cx][cy] == 1)
			{
				q.push({ cx,cy,val.d+1 });
				visit[cx][cy] = true;
			}
		}
	}

	return -1;
}

int solution(vector<vector<int> > maps)
{
	int answer = 0;

	answer = bfs(maps);
	return answer;
}

int main()
{
	vector<vector<int>> maps =
	{
		{1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1}
	};

	cout << solution(maps);
}

