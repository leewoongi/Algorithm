#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, m, u, v, counter, next_number;
bool nb[10002][10002];
bool visit[10002];

vector<int> vec;
vector<int> v_check;
vector<int> ex;

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &u, &v);

		nb[u][v] = true;
		nb[v][u] = true;
	}

	vec.push_back(1);
	v_check.push_back(1);

	while (v_check.size() < n)
	{
		if (!ex.empty())
		{
			vec.push_back(ex.back());
			v_check.push_back(ex.back());
			ex.pop_back();
		}

		while (!vec.empty())		
		{
			next_number = vec.back();
			vec.pop_back();
			visit[next_number] = true;

			for (int i = 1; i <= n; i++)
			{
				if (nb[next_number][i])
				{
					for (int j = 0; j < v_check.size(); j++)
					{
						if (v_check.at(j) == i && !visit[i]) // 값이 벡터에 있으면
						{
							visit[i] = true;
							vec.push_back(i);
						}
						else if(!visit[i])
						{
							visit[i] = true;
							vec.push_back(i);
							v_check.push_back(i);
						}
					}
				}
				else if(!nb[next_number][i] && next_number != i && !visit[i])
				{
					ex.push_back(i);
				}
			}
		}
		counter++;
	}

	while (!vec.empty())
	{
		vec.pop_back();
	}
	while (!v_check.empty())
	{
		v_check.pop_back();
	}
	while (!ex.empty())
	{
		ex.pop_back();
	}

	printf("%d",counter);
}