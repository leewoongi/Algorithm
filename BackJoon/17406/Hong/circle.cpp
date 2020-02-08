#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M, K;
int ar[55][55];
int r_ar[55][55];
vector<int> add;
vector<vector<int>> cal;

void reset()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			ar[i][j] = r_ar[i][j];
		}
	}
}

void circle(int sx, int sy, int ex, int ey)
{
	int val = ar[sx][ey];
	for (int i = ey; i > sy; i--)
	{
		ar[sx][i] = ar[sx][i - 1];
	}
	for (int i = sx; i < ex; i++)
	{
		ar[i][sy] = ar[i + 1][sy];
	}
	for (int i = sy; i < ey; i++)
	{
		ar[ex][i] = ar[ex][i + 1];
	}
	for (int i = ex; i > sx; i--)
	{
		ar[i][ey] = ar[i - 1][ey];
	}
	ar[sx + 1][ey] = val;
}

void rcs(int r, int c, int s)
{
	int s_x = r - s;
	int s_y = c - s;
	int e_x = r + s;
	int e_y = c + s;
	int counter = (e_x - s_x) / 2;

	for (int i = 0; i < counter; i++)
	{
		circle(s_x, s_y, e_x, e_y);
		s_x++;
		s_y++;
		e_x--;
		e_y--;
	}
}

int main()
{
	cin >> N >> M >> K;
	int z, x, c;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> r_ar[i][j];
		}
	}
	reset();
	for (int i = 0; i < K; i++)
	{
		cin >> z >> x >> c;
		vector<int> temp;
		temp.push_back(z);
		temp.push_back(x);
		temp.push_back(c);
		cal.push_back(temp);
	}
	sort(cal.begin(), cal.end());
	do
	{
		reset();
		for (int i = 0; i < K; i++)
		{
			rcs(cal[i][0], cal[i][1], cal[i][2]);
		}

		for (int i = 1; i <= N; i++)
		{
			int sum = 0;
			for (int j = 1; j <= M; j++)
			{
				sum = sum + ar[i][j];
			}
			add.push_back(sum);
		}
	} while (next_permutation(cal.begin(), cal.end()));

	sort(add.begin(), add.end());

	cout << add[0];
}