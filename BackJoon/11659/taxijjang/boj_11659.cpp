#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>

#define INF 2e9
#define SIZE 101000

using namespace std;

typedef long long int ll;

int arr[SIZE];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M; cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}

	for (int i = 0; i < M; i++) {
		int left, right; cin >> left >> right;

		cout << arr[right] - arr[left - 1] << "\n";
	}

}