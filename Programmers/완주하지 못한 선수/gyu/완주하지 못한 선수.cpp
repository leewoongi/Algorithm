#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) 
{
	string answer = "";
	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());
	int completion_size=completion.size();
	for (int i = 0; i < completion_size; i++)
	{
		if (participant[i] == completion[i])
		{
			continue;
		}
		else
		{
			return participant[i];
		}
	}
	return participant[participant.size() - 1];
}
int main()
{
	
	vector<string> participant = { "leo","kiki","eden" };
	vector<string> completion = { "eden","kiki" };
	string a = solution(participant, completion);
	return 0;
}