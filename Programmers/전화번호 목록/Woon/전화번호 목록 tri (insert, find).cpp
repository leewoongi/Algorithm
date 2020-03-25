#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct Trie {

	Trie *node[10];
	bool finish;

	Trie() {
		for (int i = 0; i < 10; i++) {
			node[i] = NULL;
		}
		finish = false;
	}


	void insert(const char *key) {
	
		if (*key == NULL) {
			finish = true;
		}
		else {
			int index = *key - '0';
			if (node[index] == NULL) {
				node[index] = new Trie();
			}
			node[index]->insert(key + 1);
		}
	}

	bool find(const char *key) {
		if (*key == NULL) {
			return true;
		}
		if (finish == true) {
			return false;
		}

		int index = *key - '0';
		return node[index]->find(key + 1);
	}
};


bool solution(vector<string> phone_book) {
	bool answer = true;

	Trie *trie = new Trie;

	int size = phone_book.size();

	//트라이 구성
	for (int i = 0; i < size; i++) {
		const char * c = phone_book[i].c_str();
		trie->insert(c);
	}

	//탐색
	for (int i = 0; i < size; i++) {
		const char * c = phone_book[i].c_str();
		if (trie->find(c) == false) {
			answer = false;
			break;
		}
	}

	return answer;
}
int main() {


	vector<string> phone_book = {
		//"119", "97674223", "1195524421"
		//"123", "456", "789"
		"12","123","1235","567","88"
	};


	solution(phone_book);

	return 0;
}