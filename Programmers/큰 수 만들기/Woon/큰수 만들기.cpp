#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

stack<char> st;
string solution(string number, int k) {
	string answer = "";

	int size = number.size();

	int max_size = size - k;
	int st_size = 0;

	for (int i = 0; i < size; i++) {
	
		if (st.empty()) {
			st.push(number[i]);
			st_size++;
			continue;
		}

		while (st.top() < number[i] && max_size - st_size < size - i) {
			if (st.top() < number[i]) {
				st.pop();
				st_size--;
			}

			if (st.empty()) {
				break;
			}
		}

		if (st_size < max_size) {
			st.push(number[i]);
			st_size++;
		}
	}

	while (!st.empty()) {
		answer = st.top() + answer;
		st.pop();
	}

	
	return answer;
}
int main() {

	string number = "4177252841";
	int k = 4;

	//string number = "1111";
	//int k = 2;

	//string number = "1924";
	//int k = 2;
	cout << solution(number, k);

	return 0;	
}
