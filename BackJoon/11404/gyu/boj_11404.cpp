#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int arr[101][101];
const static int INF = 21000000;

void init()
{
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			if (i == j)
			{
				continue;
			}
			
			arr[i][j] = INF;
			
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	init();
	for (int i = 0; i < m; i++)
	{
		int x, y, cost;
		cin >> x >> y >> cost;
		if (arr[x][y] < cost)
		{
			continue;
		}
		arr[x][y] = cost;
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i == j)
				{
					continue;
				}
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j] == INF)
			{
				cout << 0 << " ";
			}
			else
			{
				cout << arr[i][j] << " ";
			}
		}
		cout << endl;
	}

	return 0;
}