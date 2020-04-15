#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define SIZE 20010
using namespace std;
vector<int> arr[SIZE];
bool visited[SIZE];
int solution(int n, vector<vector<int>> edge) {
	for (auto e : edge) {
		arr[e[0]].push_back(e[1]);
		arr[e[1]].push_back(e[0]);
	}

	queue<pair<int,int>> q;
	q.push(make_pair(1,0));
	
	pair<int, int> res = { 0,0 };
	while (!q.empty() ){
		pair<int, int> h = q.front(); q.pop();
		visited[h.first] = true;

		for (auto next : arr[h.first]) {
			if (visited[next] == true)
				continue;

			pair<int, int> n = { next, h.second + 1 };

			if (res.first == n.second)
				res.second++;
			else if (res.first < n.second) {
				res.first = n.second; res.second = 1;
			}

			visited[next] = true;
			q.push(n);
		}
	}

	return res.second;
}
int main(void) {
	int n; n = 6;

	vector<int> a;
	vector<vector<int>> edge = { {3,6},{4,3},{3,2},{1,3},{1,2},{2,4},{5,2} };

	cout << solution(n, edge);
}