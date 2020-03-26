#include<iostream>
#include<vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	vector<int> v;
	int sum = 0;
	int truck_check = 0;
	while (1)
	{
		answer++;
		if (v.size() == bridge_length)
		{
			sum -= v[0];
			v.erase(v.begin());
		}

		if (sum + truck_weights[truck_check] <= weight)
		{
			if (truck_check == truck_weights.size() - 1)
			{
				answer += bridge_length;
				break;
			}

			v.push_back(truck_weights[truck_check]);
			sum += truck_weights[truck_check];
			truck_check++;
		}
		else
		{
			v.push_back(0);
		}
	}
	return answer;
}

int main()
{
	int bridge_length = 2;
	int weight = 10;
	vector<int> truck_weights = { 7,4,5,6 };
	cout << solution(bridge_length, weight, truck_weights)<<endl;
	return 0;
}