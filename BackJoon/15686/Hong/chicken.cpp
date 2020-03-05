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
	int d;
};

int N, M, c_counter, sum=999999, result = 999999;
int p_map[60][60];
vector<node> v, chicken;
vector<int> n, k;

void com()
{
	for (int i = 0; i < c_counter - M; i++)
	{
		k.push_back(0);
	}

	for (int i = 0; i < M; i++)
	{
		k.push_back(1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int a;
			cin >> a;
			p_map[i][j] = a;

			if (p_map[i][j] == 1)
			{
				v.push_back({ i,j,0 });
			}
			else if (p_map[i][j] == 2)
			{
				n.push_back(c_counter);
				c_counter++;
				chicken.push_back({ i,j,0 });
			}
		}
	}

	com();

	do
	{
		sum = 0;

		for (int i = 0; i < v.size(); i++)
		{
			int tmp = 9999999;
			for (int j = 0; j < k.size(); j++)
			{
				if (k[j] == 1)
				{
					tmp = min(tmp, abs(v[i].x - chicken[j].x) + abs(v[i].y - chicken[j].y));
				}
			}
			sum += tmp;
		}
		result = min(result, sum);
	} while (next_permutation(k.begin(), k.end()));

	cout << result;
}