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

//0에서 왼쪽으로 갈때, 알파벳크기 이상으로 넘어갔을때
int find_index(string name, int index) {
	int n_size = name.size();
	if (index < 0)
		return n_size - 1;
	if (index >= n_size)
		return 0;
	return index;
}
//현재 알파벳과 A와의 거리 차이
int dis(string & name, int index, char alpa) {
	name[index] = 'A';
	if (alpa <= 'M') {
		return alpa - 'A';
	}
	return 26 - (alpa - 'A');
}

//왼쪽으로 이동
pair<int, int> move_left(string name, int index) {
	int cnt = 1;

	while (1) {
		if (name[index = find_index(name, index - 1)] != 'A')
			break;
		cnt++;
	}

	return{ index,cnt };
}

//오른쪽으로 이동
pair<int, int> move_right(string name, int index) {
	int cnt = 1;
	while (1) {
		if (name[index = find_index(name, index + 1)] != 'A')
			break;
		cnt++;
	}

	return{ index,cnt };
}

int solution(string name) {
	int index = 0, cnt = dis(name, index, name[0]);
	string judge(name.size(), 'A');
	while (name != judge) {
		int left, right; left = right = index;

		int l_index, l_cnt, r_index, r_cnt;
		tie(l_index, l_cnt) = move_left(name, index);
		tie(r_index, r_cnt) = move_right(name, index);
		//left가 더 짧을 때
		if (l_cnt < r_cnt) {
			cnt += l_cnt + dis(name, l_index, name[l_index]);
			index = l_index;
		}
		//right가 더 짧을 때
		else {
			cnt += r_cnt + dis(name, r_index, name[r_index]);
			index = r_index;
		}
	}

	return cnt;
}



int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s; cin >> s;

	cout << solution(s);
}