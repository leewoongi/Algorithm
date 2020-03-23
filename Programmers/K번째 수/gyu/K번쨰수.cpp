#include<iostream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;
int command_map[50][3];
vector<int> solution(vector<int> array_s, vector<vector<int>> commands) {
	vector<int> answer;
	int commands_y_size = commands.size();

	for (int i = 0; i < commands_y_size; i++)
	{
		vector<int> v;
		for (int j = commands[i][0] - 1; j < commands[i][1]; j++)
		{
			v.push_back(array_s[j]);
		}
		sort(v.begin(), v.end());
		answer.push_back(v[commands[i][2]-1]);
	}
	return answer;
}

int main()
{
	vector<int>array_s = { 1,5,2,6,3,7,4 };
	vector<vector<int>> commands = 
	{
		{2,5,3},
		{4,4,1},
		{1,7,3}
	};
	vector<int>result=solution(array_s,commands);
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i];
		cout << " ";
	}
	return 0;
}