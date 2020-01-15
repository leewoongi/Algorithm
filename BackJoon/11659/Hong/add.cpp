#include <iostream>
#include <string>

using namespace std;

int n, m, x, y;
int n_array[100001], r_array[100001];

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &n_array[i]);
		r_array[i] = r_array[i - 1] + n_array[i];
	}

	for (int i = 0; i < m; i++)
	{
		int result = 0;
		scanf("%d %d", &x, &y);

		result = r_array[y] - r_array[x - 1];

		printf("%d\n", result);
	}
}