#include<iostream>

using namespace std;

int soulution(int n)
{
	int ans=0;
	int check_tel = n;
	while(0 < check_tel)
	{
		int check = check_tel / 2;
		if (check_tel % 2 == 0)
		{
			check_tel = check;
		}
		else
		{
			check_tel = check;
			ans++;
		}
	}
	return ans;
}

int main()
{
	int n;
	cin >> n;
	cout << soulution(n) << endl;

}