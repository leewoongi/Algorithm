#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    int size = times.size();

    long long left = 1;
    long long right = (long long)times[size-1] * n;

    long long mid = 0;
    long long res = right;

    while (left <= right) {

        long long sum = 0;
        mid = (left + right) / 2;

        for (int i = 0; i < size; i++) {
            sum = sum + (mid / times[i]);
        }

        if (n > sum) {
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    answer = left;
    return answer;
}
int main() {

    int n = 6;
    vector<int> time = {
        7,10
    };

    solution(n, time);
    return 0;
}