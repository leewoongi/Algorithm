#include <iostream>
#include <string>

using namespace std;

int n, k, counter;
int n_array[11];

int main()
{
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> n_array[i];
	}

	while (k > 0)
	{
		for (int i = n-1; i >= 0; i--)
		{
			int number = k / n_array[i];
			if (number != 0)
			{
				counter += number;
				k = k - (n_array[i] * number);
				break;
			}
		}
	}
	cout << counter;
}