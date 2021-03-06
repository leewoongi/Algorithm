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

#define SIZE 15
const int INF = 2000000000;

using namespace std;

typedef long long int ll;

map<string, int> _map;

bool cmp(string s1, string s2) {
	if (s1.size() == s2.size()) {
		return s1 > s2;
	}
	return s1.size() > s2.size();
}
struct Trie {
	Trie *node[SIZE];
	bool finish, child;

	Trie() {
		fill(node, node + SIZE, nullptr);
		finish = child = false;
	}

	~Trie() {
		for (int i = 0; i < SIZE; i++) {
			if (node[i])
				delete node[i];
		}
	}

	bool insert(string phone, int index) {
		if (index >= phone.size()) {
			finish = true;

			if (child) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			int here = phone.at(index) - '0';
			if (node[here] == NULL) {
				node[here] = new Trie();
			}
			child = true;
			bool tmp = node[here]->insert(phone, index + 1);

			return finish || tmp;
		}
	}
};

Trie root;
bool solution(vector<string> phone_book) {
	sort(phone_book.begin(), phone_book.end(), cmp);

	bool answer = true;
<<<<<<< HEAD

=======
	
>>>>>>> a3894adcafb8b1802b8c26cade42ddd56d77907b
	for (auto phone : phone_book) {
		bool check = root.insert(phone, 0);

		if (check) {
<<<<<<< HEAD
			return false;
		}
	}
	return true;
=======
			return true;
		}
	}
	return false;
>>>>>>> a3894adcafb8b1802b8c26cade42ddd56d77907b
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

<<<<<<< HEAD
	vector<string> phone_book = { "12","123","1234" };
=======
	vector<string> phone_book = { "12","123","1234"};
>>>>>>> a3894adcafb8b1802b8c26cade42ddd56d77907b

	bool res = solution(phone_book);

	if (res)
<<<<<<< HEAD
		cout << "true\n";
	else
		cout << "false\n";
=======
		cout << "false\n";
	else
		cout << "true\n";
>>>>>>> a3894adcafb8b1802b8c26cade42ddd56d77907b

}