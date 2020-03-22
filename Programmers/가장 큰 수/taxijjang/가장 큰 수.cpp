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

bool cmp(string n1, string n2) {
	return n1 + n2 > n2 + n1;
}
string solution(vector<int> numbers) {
	vector<string> num;
	for (int i = 0; i < numbers.size(); i++) {
		num.push_back(to_string(numbers[i]));
	}

	sort(num.begin(), num.end(), cmp);

	string answer = "";
	for (auto n : num) {
		answer = answer + n;
	}

	if (answer[0] == '0')
		return "0";
	return answer;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<int> numbers = {0,0,0,0 };
	cout << solution(numbers);

}