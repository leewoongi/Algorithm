#include <iostream>
#include <string>

using namespace std;

int main()
{
	int number, n;
	int ar[1000];
	cin >> number;
	ar[1] = 1;
	ar[2] = 2;
	ar[3] = 4;

	for (int j = 0; j < number; j++)
	{
		cin >> n;
		if (n == 1)
		{
			cout << ar[1] << '\n';;
		}
		else if (n == 2)
		{
			cout << ar[2] << '\n';;
		}
		else if (n == 3)
		{
			cout << ar[3] << '\n';;
		}
		else
		{
			for (int i = 4; i <= n; i++)
			{
				ar[i] = (ar[i - 3] + ar[i - 2] + ar[i - 1]);
			}
			cout << ar[n]<<'\n';
		}
	}
}