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

priority_queue<int > pq;
int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int milgaru = 0;
	int day = stock;
	int total_index = 0;
	int cnt = 0;
	while (day < k) {
		if (milgaru == 0) {
			while (total_index < dates.size() && dates[total_index] <= day) {
				pq.push(supplies[total_index++]);
			}
			milgaru = pq.top(); pq.pop();
			cnt++;
		}		
		milgaru--;
		day++;
	}

	return cnt;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int stock = 4;
	vector<int> dates = { 4,10,15 };
	vector<int> supplies = { 20,5,10 };
	int k = 30;
	cout << solution(stock, dates, supplies, k);
}