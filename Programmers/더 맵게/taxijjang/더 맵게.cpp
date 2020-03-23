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
#include<stack>

#define SIZE 1010
const int INF = 2000000000;

using namespace std;

typedef long long int ll;
priority_queue<int> pq;
int solution(vector<int> scoville, int K) {
	for (auto sco : scoville) {
		pq.push(-sco);
	}
	int cnt = 0;
	while (-pq.top() < K) {
		if (pq.size() == 1) {
			return -1;
		}
		cnt++;
		int a = -pq.top(); pq.pop();
		int b = -pq.top(); pq.pop();

		int sco = a + (2 * b);

		pq.push(-sco);
	}

	return cnt;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<int> scoville = { 1,2,3,9,10,12 };
	int k = 7;
	cout << solution(scoville, k);
}