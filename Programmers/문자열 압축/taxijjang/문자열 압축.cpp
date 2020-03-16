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

#define SIZE 1010
const int INF = 2000000000;

using namespace std;

typedef long long int ll;

int solution(string s) {
	int s_size = s.size();

	int res = s_size;
	for (int i = 1; i <= s_size / 2; i++) {
		int word_cnt = 1;
		string tmp = "";
		string left, right;
		int j;
		for ( j = i; j < s_size; j+=i) {
			left = s.substr(j - i, i);
			right = s.substr(j, i);

			if (left == right) {
				word_cnt++;
			}
			else if (left != right) {
				if (word_cnt != 1) {
					tmp += to_string(word_cnt);
				}
				tmp += left;
				word_cnt = 1;
			}
		}
		if (word_cnt != 1) {
			tmp += to_string(word_cnt);
			tmp += left;
		}
		else if (word_cnt == 1) {
			tmp += right;
		}

		res = min(res,(int) tmp.size());
	}
	return res;
}