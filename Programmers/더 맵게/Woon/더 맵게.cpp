#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

priority_queue<int> pq;
vector<int> v;
int solution(vector<int> scoville, int K) {
	int answer = 0;
	int size = scoville.size();

	for (int i = 0; i < size; i++) {
		pq.push(-scoville[i]);
	}


	while (true) {


		int first = (-pq.top());
		pq.pop();

		if (first >= K) {
			break;
		}
		else {
			if (pq.size() == 0) {
				answer = -1;
				break;
			}

			int second = (-pq.top());
			pq.pop();

			int p = first + (second * 2);
			pq.push(-p);
			answer++;
		}
	}


	return answer;
}

int main() {

	vector<int> scoville = {
		1, 2, 3, 9, 10, 12
	};

	int k = 7;


	solution(scoville, k);
	return 0;
}