#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int size = people.size();
    sort(people.begin(), people.end());

    int left = 0;
    int right = size - 1;
    int count = 0;

    while (left<=right) {

        if (left == right) {
            count++;
            break;
        }
        int tmp = people[left] + people[right];
        if (tmp > limit) {
            right = right - 1;
            count++;
        }
        else {
            left = left + 1;
            right = right - 1;
            count++;
        }
    }

    answer = count;
    return answer;
}

int main() {

    vector<int> people = {
        70,50,80,50
    };
    int limit = 100;
    solution(people, limit);

    return 0;
}