#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    bool check[31][31] = {};
    int dx[3] = { 1,0,1 };
    int dy[3] = { 0,1,1 };
    char ch;
    bool a_check= true;

    while (a_check)
    {
        a_check = false;
        for (int i = 0; i < m - 1; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ch = board[i][j];
                if (ch == board[i + dx[0]][j + dy[0]] && ch == board[i + dx[1]][j + dy[1]]
                    && ch == board[i + dx[2]][j + dy[2]] && ch != NULL)
                {
                    check[i][j] = true;
                    check[i + dx[0]][j + dy[0]] = true;
                    check[i + dx[1]][j + dy[1]] = true;
                    check[i + dx[2]][j + dy[2]] = true;
                    a_check = true;
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (check[i][j])
                {
                    check[i][j] = false;
                    answer++;
                    for (int r = i - 1; r >= 0; r--)
                    {
                        board[r + 1][j] = board[r][j];
                        board[r][j]=NULL;
                    }
                }
            }
        }
    }
    return answer;
}

int main() {

    int m = 4;
    int n = 5;


    vector<string> board = {
        "CCBDE", "AAADE", "AAABF", "CCBBF"
    };

    solution(m, n, board);

    return 0;
}