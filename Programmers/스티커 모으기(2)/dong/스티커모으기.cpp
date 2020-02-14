#include <iostream>
#include <vector>
using namespace std;
int n = 100001;
int arr[100001];
int result[100001];
int tmp_result[100001];
int max(int a, int b) {
    return a > b ? a : b;
}
int solution(vector<int> sticker)
{
    int answer = 0;
    n = sticker.size();
    if (n == 1) {
        answer = sticker[0];
    }
    else if (n == 2) {
        answer = max(sticker[0], sticker[1]);
    }
    else if (n == 3) {
        for (int i = 0; i < 3; i++) {
            if (answer < sticker[i]) {
                answer = sticker[i];
            }
        }
    }
    else {
        result[n - 1] = 0;
        result[n - 2] = sticker[n - 2];
        tmp_result[n-1] = sticker[n-1];
        tmp_result[n-2] = sticker[n-2];
        for (int i = n - 2; i >= 0; i--) {

            result[n - 1] = 0;
            result[1] = 0;
            if (i == 0) {
                result[i] = sticker[i] + result[i + 2];
            }
            else {
                result[i] = max(result[i + 1], result[i + 2] + sticker[i]);
            }
        }
        for (int i = n - 1; i >= 1; i--) {
            
            if (i == 1) {
                tmp_result[i] = sticker[i] + tmp_result[i + 2];
            }
            else {
                tmp_result[i] = max(tmp_result[i + 1], tmp_result[i + 2] + sticker[i]);
            }
        }
        answer = max(result[0], tmp_result[1]);
    }
    return answer;

}
int main() {
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    cout << solution(v) << '\n';
}