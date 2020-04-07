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
typedef pair<int, int> pii;
int solution(vector<int> people, int limit) {
	sort(people.begin(), people.end());

	int left = 0, right = people.size() - 1;

	int answer = 0;
	while (left <= right) {
		if (left == right) {
			answer++;
			break;
		}
		if (people[left] + people[right] <= limit) {
			answer++;
			left++; right--;
		}
		else {
			answer++;
			right--;
		}
	}
	return answer;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	vector<int> people = { 70,50,80,50 };
	int limit = 100;
	cout << solution(people, limit);

}