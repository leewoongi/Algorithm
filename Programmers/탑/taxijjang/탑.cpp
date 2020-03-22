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
typedef pair<int, int> pii;

stack<pii> _stack;
vector<int> solution(vector<int> heights) {
	vector<int> answer(heights.size(), 0);
	for (int i = heights.size() - 1; i >= 0; i--) {
		if (_stack.empty()) {
			_stack.push(make_pair(heights[i], i));
			continue;
		}

		if (heights[i] <= _stack.top().first) {
			_stack.push(make_pair(heights[i], i));
		}
		
		while (!_stack.empty() && heights[i] > _stack.top().first) {
			pii h = _stack.top(); 
			_stack.pop();

			answer[h.second] = i + 1;
		}
		_stack.push(make_pair(heights[i], i));
	}
	
	return answer;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<int> heights = { 6,9,5,7,4 };

	vector<int> res = solution(heights);

	for (auto r : res) {
		cout << r << " ";
	}

	return 0;
}