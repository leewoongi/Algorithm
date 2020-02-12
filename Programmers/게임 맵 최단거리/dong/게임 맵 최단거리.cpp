#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n = 100, m = 100;
bool visit[101][101];
int arr[101][101];
int answer = 0;
int dir_x[4] = { 0,1,0,-1 };
int dir_y[4] = { 1,0,-1,0 };
typedef struct NODE {
    int x;
    int y;
    int cnt;
}node;
queue<node> q;
int solution(vector<vector<int> > maps)
{
    n = maps.size();
    m = maps[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = maps[i][j];
            if (maps[i][j] == 0) {
                visit[i][j] = true;
            }
        }
    }
    q.push({ 0,0 ,1 });
    visit[0][0] = true;
    while (!q.empty()) {
        node nd = q.front();
        q.pop();


        if (nd.x == n - 1 && nd.y == m - 1) {
            answer = nd.cnt;
        }
        for (int i = 0; i < 4; i++) {
            int x = nd.x + dir_x[i];
            int y = nd.y + dir_y[i];
            int cnt2 = nd.cnt + 1;
            if (x >= 0 && x < n && y >= 0 && y < m) {

                if (visit[x][y] == false) {
                    visit[x][y] = true;
                    arr[x][y] = cnt2;
                    q.push({ x,y,cnt2 });


                }

            }

        }
    }

    if (answer == 0) {
        return -1;
    }
    else {
        return answer;
    }
}
int main() {
    vector<vector<int>> maps;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        vector<int> v;
        for (int j = 0; j < m; j++) {
            int num;
            cin >> num;
            v.push_back(num);
        }
        maps.push_back(v);
    }

    cout << solution(maps) << '\n';

}