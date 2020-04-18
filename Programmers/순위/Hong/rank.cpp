#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cmath>
#include<stack>
#include<utility>
#include<string.h>

using namespace std;

set<int> win[110];
set<int> lose[110];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    int size = results.size();

    for (int i = 0; i < size; i++) {
        win[results[i][0]].insert(results[i][1]);
        lose[results[i][1]].insert(results[i][0]);
    }

    for (int i = 1; i <= n; i++) {
        for (auto it = win[i].begin(); it != win[i].end(); it++) {
            for (auto iter = lose[i].begin(); iter != lose[i].end(); iter++) {
                win[*iter].insert(*it);
            }
        }

        for (auto it = lose[i].begin(); it != lose[i].end(); it++) {
            for (auto iter = win[i].begin(); iter != win[i].end(); iter++) {
                lose[*iter].insert(*it);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (win[i].size() + lose[i].size() == n - 1) {
            answer++;
        }
    }

    return answer;
}

int main() {
    int n = 5;
    vector<vector<int>> results = { {4, 3},{4, 2},{3, 2},{1, 2},{2, 5} };

    cout << solution(n, results);
}

/*
win
1 (2)
2 (5)
3 (2)
4 (3, 2)
5 ()

lose
1 ()
2 (4, 3, 1)
3 (4)
4 ()
5 (2)
*/