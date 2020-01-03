#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	int ar[1000];
	cin >> n;
	ar[1] = 1;
	ar[2] = 3;

	if (n == 1)
	{
		cout << ar[1];
	}
	else if (n == 2)
	{
		cout << ar[2];
	}
	else
	{
		for (int i = 3; i <= n; i++)
		{
			ar[i] = (ar[i - 2] + ar[i - 2] + ar[i - 1]) % 10007;
		}
		cout << ar[n];
	}
}