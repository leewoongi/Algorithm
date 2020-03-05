#include <iostream>
#include <string>
#include <vector>

using namespace std;

int student[31];

void init_student(int n) {
    // 처음 초기화 모두 1
    for (int i = 1; i <= n; i++) {
        student[i] = 1;
    }
}

void change_student(vector<int> lost) {
    int size = lost.size();
    //잃어버린 애들은 0
    for (int i = 0; i < size; i++) {
        student[lost[i]] = 0;
    }
}

void check_student(vector<int> reserve) {
    int size = reserve.size();
    //여벌이 있는 애들은 2
    for (int i = 0; i < size; i++) {
        if (student[reserve[i]] == 0) {
            student[reserve[i]] = 1;
        }
        else {
            student[reserve[i]] = 2;
        }
    }
}
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    init_student(n);
    change_student(lost);
    check_student(reserve);

    for (int i = n; i >= 1; i--) {
        if (student[i] == 0) {
            if (student[i - 1] == 2) {
                student[i] = 1;
                student[i - 1] = 1;
            }
        }
        else if (student[i] == 1) {
            continue;
        }
        else {
            if (student[i - 1] == 0) {
                student[i] = 1;
                student[i - 1] = 1;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (student[i] == 1 || student[i] == 2) {
            answer++;
        }
    }


    return answer;
}

int main() {

    /*int n = 5;
    vector<int> lost = {
        2,4
    };
    vector<int> reserve = {
        1,3,5
    };*/
    
    
    /*int n = 5;
    vector<int> lost = {
        2,4
    };
    vector<int> reserve = {
        3
    };*/

    
    int n = 10;
    vector<int> lost = {
       3,9,10
    };
    vector<int> reserve = {
        3,8,9
    };


    cout << solution(n, lost, reserve);

    return 0;
}