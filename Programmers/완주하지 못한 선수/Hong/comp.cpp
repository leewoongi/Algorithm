#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cmath>
#include<stack>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
	string answer = "";
	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());

	for (int i = 0; i < completion.size(); i++)
	{
		if (participant[i] == completion[i])
			continue;
		else
			return participant[i];
	}

	return participant[participant.size() - 1];
}

int main()
{
	vector<string> a = { {"leo"}, {"kiki"}, {"eden"} };
	vector<string> b = { {"kiki"}, {"eden"} };

	solution(a, b);
}