#include<iostream>

using namespace std;

int days[16];
int pay[16];
int result[16];

int max(int x, int y)
{
	return x > y ? x : y;
}
void solution(int n)
{
	for (int i = n; i > 0; i--)
	{
		if (i + days[i] > n + 1)
		{
			result[i] = result[i + 1];
		}
		else
		{
			result[i] = max(result[i + 1], result[i + days[i]] + pay[i]);
		}
	}
	cout << result[1] << endl;
}

int main()
{
	int n;
	cin >> n;
	days[0] = pay[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> days[i] >> pay[i];
	}
	solution(n);
}