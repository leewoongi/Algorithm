#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

void q_push(int x) {
	v.push_back(x);
}

int q_pop() {
	int size = v.size();

	if (size == 0) {
		return -1;
	}
	else {
		int result = v.front();
		auto iter = v.begin();
		v.erase(iter);
		return result;
	}
}

int q_size() {

	return v.size();
}

int q_empty() {
	int size = v.size();
	if (size == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int q_front() {

	int size = v.size();
	if (size == 0) {
		return -1;
	}
	else {
		return v.front();
	}
}

int q_back() {

	int size = v.size();
	if (size == 0) {
		return -1;
	}
	else {
		return v.back();
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
			q_push(x);
		}
		else if (s == "pop") {
			cout << q_pop() << endl;
		}
		else if (s == "size") {
			cout << q_size() << endl;
		}
		else if (s == "empty") {
			cout << q_empty() << endl;
		}
		else if (s == "front") {
			cout << q_front() << endl;
		}
		else {
			cout << q_back() << endl;
		}
	}


	return 0;
}