#include<iostream>
#include<vector>

using namespace std;

int map[101][101];

int solution(int m, int n, vector<vector<int>> puddles)
{
	int answer = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			map[i][j] = 1;
		}
	}

	for (int i = 0; i < puddles.size(); i++)
	{
		map[puddles[i][1]][puddles[i][0]] = 0;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (i == 1 && j == 1)
			{
				continue;
			}

			if (map[i][j] == 0)
			{
				continue;
			}
			else
			{
				map[i][j] = (map[i - 1][j] + map[i][j - 1]) % 1000000007;
			}
			
		}
	}
	 answer = map[n][m];
	return answer;
}

int main()
{
	int m, n;
	m = 4;
	n = 3;
	vector<vector<int>>puddles = {{2,2}};
	cout<<solution(m, n, puddles)<<endl;
	return 0;
}