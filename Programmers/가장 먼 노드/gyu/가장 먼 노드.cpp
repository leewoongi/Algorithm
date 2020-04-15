#include<iostream>
#include <string>
#include <vector>
#include<queue>
#include<algorithm>

using namespace std;

int visit[20001];
int arr[20001][20001];

int solution(int n, vector<vector<int>> edge) 
{
	int answer = 0;
	int edge_size = edge.size();
	int count = 1;
	for (int i = 0; i < edge_size; i++)
	{
		arr[edge[i][0]][edge[i][1]]=1;
		arr[edge[i][1]][edge[i][0]]=1;
	}
	queue<int> q;
	q.push(1);
	visit[1] = 1;
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		for (int i = 1; i <= n; i++)
		{
			if (arr[v][i] == 1 && visit[i] == 0)
			{
				visit[i] = visit[v]+1;
				q.push(i);
			}
		}
		count++;
	}
	sort(visit + 1, visit + n + 1);
	int check = 0;
	int max = visit[n];
	for (int i = 1; i <= n; i++)
	{
		if (max == visit[i])
		{
			answer++;
		}
	}

	return answer;
}

int main()
{
	vector<vector<int>> edge = 
	{
		{3,6},
		{4,3},
		{3,2},
		{1,3},
		{1,2},
		{2,4},
		{5,2}
	};
	int n = 6;
	cout << solution(n, edge) << endl;
	return 0;
}