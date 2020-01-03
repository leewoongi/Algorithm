#include<iostream>

using namespace std;

int main()
{
	int T[1000];
	T[1] = 1;
	T[2] = 3;
	int i;
	int n;
	cin >> n;
	if (n == 1)
	{
		cout << T[1]<<endl;
	}
	else if (n == 2)
	{
		cout << T[2]<<endl;
	}
	else 
	{
		for (i = 3; i <= n; i++)
		{
			T[i] = (T[i - 2] + T[i - 2] + T[i - 1]) % 10007;
		}
		cout << T[i-1] << endl;
	}
	
}