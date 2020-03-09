#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int>V_cost;

int solution(int n,int max_cost)
{
	int left = 0;
	int right = V_cost[n - 1];
	int result = 0;
	int mid = 0;
	while (left <= right)
	{
		mid = (right + left) / 2;
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += (V_cost[i] > mid) ? mid : V_cost[i];
		}
		if (sum == max_cost)
		{
			result = mid;
			return result;
		}
		if (sum > max_cost)
		{
			right = mid - 1;
		}
		else
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
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int cost;
		cin >> cost;
		V_cost.push_back(cost);
	}
	int max_cost;
	cin >> max_cost;
	sort(V_cost.begin(), V_cost.end());
	cout << solution(n,max_cost) << endl;
	return 0;
}