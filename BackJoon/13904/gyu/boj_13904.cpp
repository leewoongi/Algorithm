#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct node
{
	int day;
	int socre;
}Node;

vector<Node> homework;
int dp[1001];
bool compare1(Node n1, Node n2)
{
	return n1.socre > n2.socre;
}

bool compare2(Node n1, Node n2)
{
	return n1.day > n2.day;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int day, score;
		cin >> day >> score;
		homework.push_back({ day,score });
	}
	sort(homework.begin(), homework.end(), compare1);
	for (int i = 0; i < n; i++)
	{
		int index = homework[i].day;
		if (dp[index]==0)
		{
			dp[index] = homework[i].socre;
		}
		else
		{
			while (dp[index]!=0)
			{
				index--;
			}
			if (index != 0)
			{
				dp[index] = homework[i].socre;
			}
		}
	}
	int result=0;
	sort(homework.begin(), homework.end(), compare2);
	int endend = homework[0].day;
	for (int i = 1; i <= endend; i++)
	{
		result += dp[i];
	}

	cout << result<<endl;
}