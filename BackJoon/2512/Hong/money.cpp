#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M, Left, Right, Mid, add;
vector<int> v;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
		Right = max(a, Right);
	}
	cin >> M;

	while (Left <= Right)
	{
		Mid = (Left + Right) / 2;
		add = 0;
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] >= Mid)
			{
				add += Mid;
			}
			else
			{
				add += v[i];
			}
		}

		if (add > M)
		{
			Right = Mid - 1;
		}
		else
		{
			Left = Mid + 1;
		}
	}

	cout << Right;
}