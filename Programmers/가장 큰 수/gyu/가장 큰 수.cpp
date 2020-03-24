#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

bool compare(string s1, string s2)
{
	return s1 + s2 > s2 + s1;
}

string solution(vector<int> numbers)
{
	string answer = "";
	vector<string> result;
	for (int i = 0; i < numbers.size(); i++)
	{
		result.push_back(to_string(numbers[i]));
	}
	sort(result.begin(), result.end(), compare);
	int check=0;
	for (int i = 0; i < result.size(); i++)
	{
		if (result[i] == "0")
		{
			check++;
		}
	}
	if (check == result.size())
	{
		return "0";
	}
	else
	{
		for (int i = 0; i < result.size(); i++)
		{
			answer += result[i];
		}
	}
	return answer;
}