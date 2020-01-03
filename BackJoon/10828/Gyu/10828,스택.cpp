#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
	stack<int> s;
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
			s.push(num);
		}
		if (str == "pop")
		{
			if (s.empty() == true)
			{
				cout << -1 << endl;
			}
			else
			{
				cout << s.top() << endl;
				s.pop();
			}
		}
		if (str == "top")
		{
			if (s.empty() == true)
			{
				cout << -1 << endl;
			}
			else
			{
				cout << s.top() << endl;
				
			}
		}
		if (str == "empty")
		{
			cout<<s.empty()<<endl;
		}
		if (str == "size")
		{
			cout << s.size() << endl;
		}
	}
}