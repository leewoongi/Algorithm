#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;


priority_queue<int> pq;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    int size = supplies.size();
    int index = 0;
    int count = 0;

    for (int i = 1; i < k; i++) {
        stock--;
        if (stock == 0) {
            while (true) {
                if (index < size && dates[index] <= i) {
                    pq.push(supplies[index]);
                    index++;
                }
                else {
                    break;
                }
            }

            stock = pq.top();
            pq.pop();
            count++;
        }
    }

    answer = count;
    return answer;
}

int main() {

    int stock = 4; 
    vector<int> dates = {
        4,10,15
    };
    vector<int> supplies = {
        20,5,10
    };
    int k = 30;

    solution(stock, dates, supplies, k);

    return 0;
}