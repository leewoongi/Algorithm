#include<iostream>
#include<string>

using namespace std;

int main()
{
	int check;
	int j;
	int num[11];

	num[0] = 0;
	num[1] = 1;
	num[2] = 2;
	num[3] = 4;
	cin >> check;
	for (int i = 0; i < check; i++)
	{
		int number;
		cin >> number;
		if (number == 0)
		{
			cout << num[0] << endl;
		}
		else if (number == 1)
		{
			cout << num[1] << endl;
		}
		else if (number == 2)
		{
			cout << num[2] << endl;
		}
		else if (number == 3)
		{
			cout << num[3] << endl;
		}
		else
		{
			for (j = 4; j <= number; j++)
			{
				num[j] = num[j - 3] + num[j - 2] + num[j - 1];
			}
			cout << num[j-1] << endl;
		}
	}
	
}
