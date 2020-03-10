#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int house[1005][3];
int dp[1005][3];

void search(int x, int y)
{
	if (y == 0)
		dp[x][y] = min(dp[x - 1][2] + house[x][y], dp[x - 1][1] + house[x][y]);
	else if (y == 1)
		dp[x][y] = min(dp[x - 1][0] + house[x][y], dp[x - 1][2] + house[x][y]);
	else if (y == 2)
		dp[x][y] = min(dp[x - 1][0] + house[x][y] , dp[x - 1][1] + house[x][y]);
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> house[i][0] >> house[i][1] >> house[i][2];
	}

	dp[0][0] = house[0][0];
	dp[0][1] = house[0][1];
	dp[0][2] = house[0][2];

	for (int i = 1; i < N; i++)
	{
		search(i, 0);
		search(i, 1);
		search(i, 2);
	}

	cout << min(min(dp[N - 1][0], dp[N - 1][1]), dp[N - 1][2]);
}


/*
3
1 2 20
997 1001 996
5 4 1
*/

/*
3
5 4 1
997 1001 996
1 2 20
*/