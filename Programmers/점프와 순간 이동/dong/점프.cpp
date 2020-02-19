#include <iostream>
using namespace std;
int n;
int solution(int n)
{
    int ans = 0;
    while (0 < n) {

        if (n % 2 == 0) {
            n = n / 2;
        }
        else {
            n--;
            ans++;
        }
    }

    return ans;
}

int main() {

    n = 5;
    cout << solution(n) << '\n';
    n = 6;
    cout << solution(n) << '\n';
    n = 5000;
    cout << solution(n) << '\n';
}