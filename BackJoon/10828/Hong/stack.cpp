#include <iostream>
#include <string>

using namespace std;

int stack[10001];

int main()
{
	int count = 0;
	int repeat;
	string input;
	bool bools = false;
	cin >> repeat;

	for (int i = 0; i <= repeat; i++)
	{

		getline(cin, input);

		if (input == "pop")
		{
			if (count == 0)
				cout << "-1" << '\n';
			else
			{
				cout << stack[count - 1] << '\n';;
				count--;
			}
		}
		else if (input == "size")
		{
			cout << count << '\n';
		}
		else if (input == "empty")
		{
			if (count == 0)
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (input == "top")
		{
			if (count == 0)
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
		}
		bools = true;
	}

}