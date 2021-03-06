#include <iostream>
#include <string>
#include <queue>

using namespace std;

int n, x, y, m, check, counter;
bool visit[101];
int parent[101];

queue<int> people[101];
queue<int> e_people;

int find(int x)
{
	if (parent[x] == x)
		return x;
	else
		return find(parent[x]);
}

void uni(int x, int y)
{
	int i = find(x);
	int j = find(y);

	parent[y] = i;
}

int main()
{
	cin >> n;

	cin >> x >> y;

	cin >> m;

	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;

		cin >> a >> b;

		uni(a, b);

		people[a].push(b);
		people[b].push(a);
	}

	if (parent[x] == parent[y])
	{
		while (!people[x].empty())
		{
			e_people.push(people[x].front());
			people[x].pop();
		}
		visit[x] = true;

		while (!e_people.empty())
		{
			counter++;

			int size = e_people.size();

			for (int i = 0; i < size; i++)
			{
				if (!visit[e_people.front()])
				{
					visit[e_people.front()] = true;

					if (e_people.front() == y)
					{
						check = true;
						while (!e_people.empty())
						{
							e_people.pop();
						}
						break;
					}
					else
					{
						while (!people[e_people.front()].empty())
						{
							e_people.push(people[e_people.front()].front());
							people[e_people.front()].pop();
						}
					}
				}
				e_people.pop();
			}
		}
		cout << counter;
	}
	else
		cout << -1;
}