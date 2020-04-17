#include<iostream>
#include <string>
#include <vector>
#include<set>

using namespace std;

int solution(int n, vector<vector<int>> results)
{
	int answer = 0;
	set<int> win[101];
	set<int> lose[101];
	int result_size = results.size();
	for (int i = 0; i < result_size; i++)
	{
		lose[results[i][0]].insert(results[i][1]);
		win[results[i][1]].insert(results[i][0]);
	}
	for (int i = 1; i <= n; i++) 
	{
		for (auto j : lose[i]) 
		{
			for (auto k : win[i]) 
			{
				win[j].insert(k);
			}
		}
		for (auto j : win[i]) 
		{
			for (auto k : lose[i]) 
			{
				lose[j].insert(k);
			}
		}
	}

	for (int i = 1; i <= n; i++) 
	{
		if (win[i].size() + lose[i].size() == n - 1) 
		{
			answer++;
		}
	}
	return answer;
}

int main()
{
	int n = 5;
	vector<vector<int>> results=
	{
		{4,3},
		{4,2},
		{3,2},
		{1,2},
		{2,5}
	};
	cout << solution(n, results)<<endl;
	return 0;
}