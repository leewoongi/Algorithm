#include <iostream>
using namespace std;

int solution(int n)
{
  
    int ans = 0;

    int left = 0;
    int right = 0;
    if (n % 2 == 0) {
        right = n;
    }
    else {
        right = n - 1;
        ans++;
    }
    
    
    while (left <= right) {

        if (right == 0) {
            break;
        }

        int mid = (left + right) / 2;
        if (mid % 2 != 0) {
            ans++;
            right = mid - 1;
        }
        else {
            right = mid;
        }    
    }

    return ans;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    //cout << solution(5);
    //cout << solution(6);
    cout << solution(5000);
    

    return 0;
}