#include<iostream>
#include<queue>
#include<string>
using namespace std;

int main()
{
	queue<int> q;
	int num;
	int check;
	string str;

	cin >> check;

	for (int i = 0; i < check; i++)
	{
		cin >> str;
		if (str == "push")
		{
			cin >> num;
			q.push(num);
		}
		else if (str == "pop")
		{
			if (q.empty() == true)
			{
				cout << -1 << endl;
			}
			else
			{
				cout << q.front() << endl;
				q.pop();
			}
		}
		else if (str == "fromt")
		{
			if (q.empty() == true)
			{
				cout << -1 << endl;
			}
			else
			{
				cout << q.front() << endl;

			}
		}
		else if (str == "back")
		{
			if (q.empty() == true)
			{
				cout << -1 << endl;
			}
			else
			{
				cout << q.back() << endl;
			}
		}
		else if (str == "empty")
		{
			cout << q.empty() << endl;
		}
		else if (str == "size")
		{
			cout << q.size() << endl;
		}
	}
}