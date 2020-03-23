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
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	for (auto command : commands) {
		vector<int > c = command;

		priority_queue<int, vector<int>, greater<int>> pq;

		for (int i = c[0] - 1; i < c[1]; i++) {
			pq.push(array[i]);
		}

		int cnt = 0;
		while (!pq.empty()) {
			if (cnt == c[2] - 1) {
				answer.push_back(array[cnt]);
				break;
			}
			cnt++;
		}
	}
	return answer;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<int> array = { 1,5,2,6,3,7,4 };
	vector<vector<int>> commands = { {2,5,3},{4,4,1},{1,7,3} };
	vector<int> s = solution(array, commands);
}