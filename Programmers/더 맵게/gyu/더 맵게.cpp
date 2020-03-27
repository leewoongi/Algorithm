#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;


priority_queue<int> pq;
int solution(vector<int> scoville, int k)
{
	int answer = 0;
	int scoville_size = scoville.size();
	for (int i = 0; i < scoville_size; i++)
	{
		pq.push(-scoville[i]);
	}

	while (-pq.top()<k)
	{
		if (pq.size() == 1)
		{
			return -1;
		}
		int one = (-pq.top());
		pq.pop();
		int two = (-pq.top());
		pq.pop();
		int sum = one + (two * 2);
		pq.push(-sum);
		answer++;
	}
	return answer;
}

int main()
{
	vector<int> scoville = { 1};
	int k = 7;
	cout << solution(scoville, k);
	return 0;
}