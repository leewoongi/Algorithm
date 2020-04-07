#include<iostream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;

long long solution(int n, vector<int> times) 
{
	long long answer = 0;
	int times_size = times.size();
	sort(times.begin(), times.end());
	long long left = 0;
	long long right = (long long)(times[times_size - 1]) * n;
	answer = right;
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		long long sum = 0;
		for (int i = 0; i < times_size; i++)
		{
			sum += mid / times[i];
		}
		if (n > sum)
		{
			left = mid + 1;
		}
		else
		{
			if (mid <= answer)
			{
				answer = mid;
			}
			right = mid - 1;
		}
	}
	return answer;
}

int main()
{
	int n = 6;
	vector<int> times = { 7,10 };
	cout << solution(n, times) << endl;
	return 0;
}