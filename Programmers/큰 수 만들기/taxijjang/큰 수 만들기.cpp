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


stack<char> _stack;
string solution(string number, int k) {
	int number_size = number.size();
	int correct_cnt = number_size - k;
	int find_cnt = 0;
	for (int i = 0; i < number_size; i++) {
		if (_stack.empty()) {
			_stack.push(number.at(i));
			find_cnt++;
			continue;
		}
		

		while (_stack.top() < number.at(i) && correct_cnt - find_cnt < number_size - i) {
			if (_stack.top() < number.at(i)) {
				_stack.pop(); find_cnt--;
			}

			if (_stack.empty()) {
				break;
			}
		}
		
		if (correct_cnt - find_cnt <= number_size-i) {
			
			_stack.push(number.at(i));
			find_cnt++;

			if (correct_cnt - find_cnt < 0) {
				_stack.pop(); find_cnt--;
			}
				
		}
		
	}

	string res; 
	while (!_stack.empty()) {
		res = _stack.top() + res;
		_stack.pop();
	}
	return res;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string number; int k; cin >> number >> k;
	cout << solution(number, k);
}