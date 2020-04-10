#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cmath>
#include<stack>
#include<utility>

using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;
	int right = people.size() - 1;
	int left = 0;
	sort(people.begin(), people.end());

	while (right >= left)
	{
		if (limit >= people[right] + people[left])
		{
			answer++;
			right--;
			left++;
		}
		else
		{
			right--;
			answer++;
		}
	}

	return answer;
}

int main()
{
	vector<int> people = { 70, 50, 80, 50 };
	int limit = 100;

	cout << solution(people, limit);
}