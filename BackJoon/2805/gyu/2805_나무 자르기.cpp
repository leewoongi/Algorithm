#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<long long> tree;

int soulution(int n,int m)
{
	long long result = 0;
	long long left = 0;
	long long right = tree[n-1];
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		long long height = 0;
		for (int i = 0; i < n; i++)
		{
			if (tree[i] > mid)
			{
				height += (tree[i] - mid);
			}
		}
		if (m > height)
		{
			right = mid - 1;
		}
		if (m <= height)
		{
			left = mid + 1;
			if (mid > result)
			{
				result = mid;
			}
		}
	}
	return result;
}

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		tree.push_back(x);
	}
	sort(tree.begin(), tree.end());
	cout<<soulution(n,m);
	return 0;
}