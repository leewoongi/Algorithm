#include <iostream>
using namespace std;

int solution(int n)
{
	int ans = 1;

	while (n > 1) {
		if (n % 2 == 0)
			n /= 2;
		else if (n % 2 == 1) {
			n--;
			ans++;
		}
	}

	return ans;
}