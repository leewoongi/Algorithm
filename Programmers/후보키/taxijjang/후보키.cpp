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

set<vector<int>> key;

map<int, vector<int>> check;
int solution(vector<vector<string>> relation) {
	int c_size = relation[0].size();
	int r_size = relation.size();
	for (int i = 1; i < (1<<c_size); i++) {
		vector<int> index;
		for (int j = 0; (1<<j) <= i; j++) {
			if ((i & (1<<j)) == (1<<j))
				index.push_back(j);
		}
		set<vector<string>> tmp_key;
		for (int k = 0; k < r_size; k++) {
			vector<string> s;
			for (int j = 0; j < index.size(); j++) {
				s.push_back(relation[k][index[j]]);
			}
			tmp_key.insert(s);
		}

		if (tmp_key.size() == r_size) {
			check[index.size()].push_back(i);
		}
	}

	int cnt = 0;
	for (int i = 1; i <= r_size; i++) {
		for (auto c : check[i]) {
			if (c == 0)
				continue;

			cnt++;

			for (int j = i + 1; j <= r_size; j++) {
				for (int jj = 0; jj < check[j].size(); jj++) {
					if ((c&check[j][jj]) == c) {
						check[j][jj] = 0;
					}
				}
			}
		}
	}
	
	return cnt;
}