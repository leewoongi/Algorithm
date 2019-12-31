#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> v;

void st_push(int x) {
	v.push_back(x);
}

int st_top() {

	int size = v.size();
	if (size == 0) {
		return -1;
	}
	else {
		return v.back();
	}
}

int st_size() {

	return v.size();
}

int st_empty() {
	int size = v.size();
	if (size == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int st_pop() {
	int size = v.size();

	if (size == 0) {
		return -1;
	}
	else {
		int result = v.back();
		v.pop_back();
		return result;
	}
}

int main() {


	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s; int x;
		cin >> s;

		if (s == "push") {
			cin >> x;
			st_push(x);
		}
		else if (s == "top") {
			cout << st_top() << endl;
		}
		else if (s == "size") {
			cout << st_size() << endl;
		}
		else if (s == "empty") {
			cout << st_empty() << endl;
		}
		else {
			cout << st_pop() << endl;
		}
	}


	return 0;
}