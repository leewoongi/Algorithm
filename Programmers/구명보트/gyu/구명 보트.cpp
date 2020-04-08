#include<iostream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int solution(vector<int> people, int limit)
{
	int answer = 0;
	sort(people.begin(), people.end());
	int people_size = people.size();
	int i = 0;
	int j = 0;
	for (i = people_size - 1; i > j; i--)
	{
		if (people[i] + people[j] <= limit)
		{
			j++;
			answer++;
		}
		else
		{
			answer++;
		}
	}
	if (i == j)
	{
		answer++;
	}
	return answer;
}

int main()
{
	vector<int> peple = {40,40,50,40,40};
	int limit = 100;
	cout << solution(peple, limit) << endl;
	return 0;
}