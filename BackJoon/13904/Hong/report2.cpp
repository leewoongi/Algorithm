#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


int N, d, w, day, result;
vector<int> v[1001];
priority_queue<int> pq;

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}

	for (int i = 1; i <= 1001; i++)
	{
		int size = v[i].size();
		for (int j = 0; j < size; j++)
		{
			pq.push(-v[i][j]);
		}

		while (pq.size() > i)
		{
			pq.pop();
		}
	}

	while (!pq.empty())
	{
		result += (-pq.top());
		pq.pop();
	}

	cout << result;
}