#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int n, m, k;
int arr[51][51];
int tmp_arr[51][51];
int first_xy[2];
int end_xy[2];
int tmp;
int tmp_result[51];
int result = 210000000;
typedef struct NODE {
    int r;
    int c;
    int s;

}node;
vector<node> v;
vector<int> v2;
void reset_arr() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = tmp_arr[i][j];

        }
    }
}
void reset_re() {
    for (int i = 0; i < n; i++) {
        tmp_result[i] = 0;
    }
}
void arr_lotation(int k) {
    
    reset_arr();
    for (int i = 0; i < k; i++) {
        
        first_xy[0] = v[v2[i]].r - v[v2[i]].s - 1;
        first_xy[1] = v[v2[i]].c - v[v2[i]].s - 1;
        end_xy[0] = v[v2[i]].r + v[v2[i]].s - 1;
        end_xy[1] = v[v2[i]].c + v[v2[i]].s - 1;
        int cnt = (end_xy[0] - first_xy[0]) / 2;//시계방향으로 몇개를 돌리는지
        for (int z = 0; z < cnt; z++) {
            tmp = arr[first_xy[0]][first_xy[1]];
            for (int j = first_xy[0]; j <= end_xy[0]; j++) {//왼쪽 끝을 위로 올리기
                arr[j][first_xy[1]] = arr[j + 1][first_xy[1]];


            }
            for (int j = first_xy[1]; j <= end_xy[1]; j++) {//아래줄을 왼쪽으로 땡겨오기
                arr[end_xy[0]][j] = arr[end_xy[0]][j + 1];
            }
            for (int j = end_xy[0]; j > first_xy[0]; j--) {//오른쪽 끝을 아래로 내리기
                arr[j][end_xy[1]] = arr[j - 1][end_xy[1]];
            }
            for (int j = end_xy[1]; j > first_xy[1]; j--) {//윗줄 오른쪽으로 땡기기
                arr[first_xy[0]][j] = arr[first_xy[0]][j - 1];
            }

            arr[first_xy[0]][first_xy[1] + 1] = tmp;
            first_xy[0]++;
            first_xy[1]++;
            end_xy[0]--;
            end_xy[1]--;
        }

        
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            tmp_result[i] += arr[i][j];
        }
    }

    sort(tmp_result, tmp_result +n);
    if (result > tmp_result[0]) {
        result = tmp_result[0];
    }
}
int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            cin >> arr[i][j];
            tmp_arr[i][j] = arr[i][j];
        }
    }
    for (int i = 0; i < k; i++) {
        int r, c, s;
        cin >> r >> c >> s;
        v.push_back({ r,c,s });
        v2.push_back(i);
    }
    do {
        arr_lotation(k);
        reset_re();
    } while (next_permutation(v2.begin(), v2.end()));
    cout << result << '\n';
}