#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> solution(vector<int> heights)
{
	vector<int> answer;
	int check = 1;
	int heights_size = heights.size();
	bool check_zero = false;
	for (int i = 0; i < heights_size; i++)
	{
		check_zero = false;
		if (i == 0)
		{
			answer.push_back(0);
			continue;
		}
		else
		{
			for (int j = i; j >= 0; j--)
			{
				if (heights[check] < heights[j])
				{
					answer.push_back(j + 1);
					check_zero = true;
					break;
				}
			}
			if (!check_zero)
			{
				answer.push_back(0);
			}
		}
		check++;
	}
	return answer;
}

int main()
{
	vector<int> heights = { 1,5,3,6,7,6,5 };
	vector<int>answer = solution(heights);
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << " ";
	}
	return 0;
}