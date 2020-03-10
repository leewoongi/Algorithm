#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M, counter, result = 2100000000;
int mo[100005];
int Left = 210000000;
int Right;

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> mo[i];
		Left = min(Left, mo[i]);
		Right = Right + mo[i];
	}

	while (Left <= Right)
	{
		bool check = true;
		counter = 0;
		int mid = (Left + Right) / 2;
		int val = 0;
		for (int i = 0; i < N; i++)
		{

			if (mid < mo[i])
			{
				check = false;
				break;
			}
			else {

				if (val >= mo[i])
				{
					val = val - mo[i];
				}
				else
				{

					counter++;
					val = mid;
					val = val - mo[i];
				}
			}
		}

		if (M < counter || !check)
		{
			Left = mid + 1;
		}
		else
		{

			if (result > mid)
			{
				result = mid;
			}
			Right = mid - 1;
		}
	}
	cout << result;
}