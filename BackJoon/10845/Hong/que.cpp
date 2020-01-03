#include <iostream>
#include <string>

using namespace std;

int stack[10001];

int main()
{
	int fcount = 0;
	int count = 0;
	int tcount = 0;
	int repeat;
	string input;
	bool bools = false;
	cin >> repeat;

	for (int i = 0; i <= repeat; i++)
	{

		getline(cin, input);

		if (input == "pop")
		{
			if (tcount == 0)
				cout << "-1" << '\n';
			else
			{
				cout << stack[fcount] << '\n';;
				fcount++;
				tcount--;
			}
		}
		else if (input == "size")
		{
			cout << tcount << '\n';
		}
		else if (input == "empty")
		{
			if (tcount == 0)
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (input == "front")
		{
			if (tcount == 0)
				cout << "-1" << '\n';
			else
				cout << stack[fcount] << '\n';;
		}
		else if (input == "back")
		{
			if (tcount == 0)
				cout << "-1" << '\n';
			else
				cout << stack[count - 1] << '\n';;
		}
		else if (bools)
		{
			int number;
			number = stoi(input.substr(5));
			stack[count] = number;
			count++;
			tcount++;
		}
		bools = true;
	}

}