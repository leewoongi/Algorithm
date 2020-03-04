#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int L, P, V;
	int ca = 1;

	cin >> L >> P >> V;

	while (L != 0 && P != 0 && V != 0)
	{
		int c = V / P;
		int a = V % P;
		
		if (a > L)
		{
			a = L;
		}
		int result = (c * L) + a;

		cout << "Case " << ca << ": " << result << '\n';
		ca++;

		cin >> L >> P >> V;
	}
}