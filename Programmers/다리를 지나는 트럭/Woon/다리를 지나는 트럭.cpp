#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

queue<int> q;
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int size = truck_weights.size();

    for (int i = 0; i < bridge_length; i++) {
        q.push(0);
    }

    int i = 0;
    int sum = 0;
    int time = 0;
    int count = 0;

    while (true) {

        if (i == size) {

            if (q.front() != 0) {
                count++;
                sum = sum - q.front();
                if (count == size) {
                    time++;
                    break;
                }
            }
            q.pop();
            q.push(0);
            time++;
        }
        else {
            // 더할 때 무게를 넘지 않을때
            if (sum + truck_weights[i] <= weight) {
                if (q.front() != 0) {
                    count++;
                    sum = sum - q.front();
                }
                q.pop();
                q.push(truck_weights[i]);
                sum = sum + truck_weights[i];
                i++;
                time++;
            }
            // 더 다리에 못 올라갈 경우
            else {
                if (q.front() != 0) {
                    count++;
                    sum = sum - q.front();
                    q.pop();
                    if (sum + truck_weights[i] <= weight) {
                        q.push(truck_weights[i]);
                        sum = sum + truck_weights[i];
                        i++;
                    }
                    else {
                        q.push(0);
                    } 
                }
                else {
                    q.pop();
                    q.push(0);
                }
                time = time + 1;
            }
        }
    }

    answer = time;
    return answer;
}

int main() {

    int bridge_length = 2;
    int weight = 10;
    vector<int> truck_weights = {
        7,4,5,6
    };

    /*int bridge_length = 100;
    int weight = 100;
    vector<int> truck_weights = {
        10
        //10,10,10,10,10,10,10,10,10,10
    };*/

    /*int bridge_length = 10;
    int weight = 10;
    vector<int> truck_weights = {
        1,1,1,1,1,1,1,1,1,1
    };*/

    solution(bridge_length, weight, truck_weights);

    return 0;
}