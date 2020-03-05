#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<functional>
#include<cmath>

#define SIZE 40
const int INF = 2000000000;

using namespace std;

typedef long long int ll;

int check[SIZE];
int solution(int n, vector<int> lost, vector<int> reserve) {

	for (int i = 0; i < SIZE; i++) {
		check[i] = 1;
	}

	for (auto l : lost) {
		check[l]--;
	}
	for (auto r : reserve) {
		check[r]++;
	}

	int answer = 0;

	for (int i = 1; i <= n; i++) {
		if (check[i] == 2) {
			if (check[i - 1] == 0) {
				check[i]--; check[i + 1]++;
			}
			else if (check[i + 1] == 0) {
				check[i]--; check[i + 1]++;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (check[i])
			answer++;
	}
	return answer;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//int n; cin >> n;
	vector<int> lost = { 2,4 };
	vector<int> reserve = { 3 };

	cout << solution(5, lost, reserve);

}