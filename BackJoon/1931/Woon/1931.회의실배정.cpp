#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct NODE {

	int start;
	int end;
}node;

bool cmp(const node &x1, const node &x2) {

	if (x1.end == x2.end) {
		return x1.start < x2.start;
	}
	return x1.end < x2.end;
}

vector<node> v;
int main() {
	

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;

		v.push_back({ s,e });
	}

	sort(v.begin(), v.end(), cmp);

	int count = 1;
	int x = v[0].end;

	for (int i = 1; i < n; i++) {
		if (x > v[i].start) {
			continue;
		}
		else {
			x = v[i].end;
			count = count + 1;
		}
	}
	

	cout << count;
	return 0;
}