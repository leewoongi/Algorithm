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
	bool b;
};

int N, d, w, day, sum;
vector<node> v;

bool cmp(node n1, node n2)
{
	if (n1.y == n2.y)
	{
		return n1.x > n2.x;
	}
	return n1.y > n2.y;
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b,false });
		day = max(day, a);
	}

	sort(v.begin(), v.end(), cmp);

	while (day > 0)
	{
		int val = 0;

		for (int i = 0; i < v.size(); i++)
		{
			if (v[i].x >= day && !v[i].b)
			{
				sum += v[i].y;
				v[i].b = true;
				break;
			}
		}
		day--;
	}

	cout << sum;
}