#include<iostream>
#include<vector>
#include<queue>

using namespace std;

bool visit[201];

int bfs(int n, vector<vector<int>> computers)
{
	queue<int> q;
	int answer = 0;
	for (int j = 0; j < n; j++)
	{
		if (!visit[j])
		{
			answer++;
			visit[j] = true;
			q.push(j);
		}
		while (!q.empty())
		{
			int ch = q.front();
			q.pop();
			for (int i = 0; i < n; i++)
			{
				if (computers[ch][i] != 0 && !visit[i])
				{
					visit[i] = true;
					q.push(i);
				}
			}
		}
	}
	return answer;
}

int solution(int n, vector<vector<int>> computers)
{
	int answer = 0;
	return bfs(n,computers);
}