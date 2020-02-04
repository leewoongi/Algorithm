#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long N, M, result, val, answer, R, Left, Right, Mid;

vector<int> tree;

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int tr;
		cin >> tr;

		tree.push_back(tr);
	}

	sort(tree.begin(), tree.end());
	Left = 0;
	Right = tree[tree.size() - 1];
	Mid = (Left + Right) / 2;

	while (Left <= Right)
	{
		result = 0;

		for (int i = 0; i <= tree.size() - 1; i++)
		{
			if (tree[i] > Mid)
			{
				result += tree[i] - Mid;
			}
		}

		if (result >= M)
		{
			Left = Mid + 1;
			Mid = (Left + Right) / 2;
		}
		else if (result < M)
		{
			Right = Mid - 1;
			Mid = (Left + Right) / 2;
		}
	}

	cout << Mid;
}