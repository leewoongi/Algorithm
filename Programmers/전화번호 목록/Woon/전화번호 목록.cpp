#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


map<int, string> m;
bool solution(vector<string> phone_book) {
	bool answer = true;

	int size = phone_book.size();

	for (int i = 0; i < size; i++) {
		m.insert({ i,phone_book[i] });
	}

	int tmp = 0;
	for (int i = 0; i < size-1; i++) {
		int len = m[i].size();
		int len1 = m[i + 1].size();

		tmp = len;
		if (len1 < len) {
			tmp = len1;
		}

		for (int j = i + 1; j < size; j++) {
			string s = m[i];
			string s1 = m[j];

			if (s.substr(0, tmp) == s1.substr(0, tmp)) {
				answer = false;
				break;
			}
		}

		if (answer == false) {
			break;
		}
	}


	return answer;
}

int main() {

	int bridge_length = 2;
	int weight = 10;


	vector<string> phone_book = {
		"97674223", "1195524421","119"
	};
	solution(phone_book);
	return 0;
}