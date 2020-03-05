#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long lr[101][101];
long long ud[101][101];

int map[101][101];

void init_map(int m, int n, vector<vector<int>> puddles) {

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 && j == 1) {
                lr[i][j] = 1;
                ud[i][j] = 1;
            }
        }
    }

    int size = puddles.size();
    for (int i = 0; i < size; i++) {
        int x = puddles[i][0];
        int y = puddles[i][1];

        map[x][y] = 1;
    }
}



int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    init_map(m, n, puddles);

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {

            if (i == 1 && j == 1) {
                continue;
            }
            else if (map[i][j] != 1) {
                lr[i][j] = (lr[i][j - 1] + ud[i - 1][j]) % 1000000007;
                ud[i][j] = (lr[i][j - 1] + ud[i - 1][j]) % 1000000007;
            }
            else if (map[i][j] == 1) {
                lr[i][j] = 0;
                ud[i][j] = 0;
            }
        }
    }

    answer = lr[m][n];

    return answer;
}

int main() {

    int m = 4;
    int n = 3;

    vector<vector<int>> v = {
        {2,2}
    };

    cout << solution(m, n, v);
    return 0;
}