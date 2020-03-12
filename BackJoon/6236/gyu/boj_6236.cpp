#include<iostream>
#include<vector>

using namespace std;

int cost[100000];
int sum;

int main()
{
	int n, k, left, right;
	cin >> n >> k;
	left = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> cost[i];
		sum += cost[i];
		if (cost[i] > left)
		{
			left = cost[i];
		}
	}
	
	right = sum;
	int num;
	int check_sum;
	int result = 0;
	bool flag = false;
	while (left <= right)
	{
		flag = false;
		int mid = (left + right) / 2;
		check_sum = mid;
		num = 1;
		for (int i = 0; i < n; i++)
		{
			
			if (check_sum - cost[i] < 0)
			{
				check_sum = mid;
				num++;
			}
			check_sum -= cost[i];
		}
		if (k >= num)
		{
			result = mid;
			right = mid - 1;
		}
		else if(flag)
		{
			left = mid + 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	cout << result << endl;
}