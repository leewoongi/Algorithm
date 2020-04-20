#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cmath>
#include<stack>
#include<utility>
#include<string.h>

#define INF 210000000

using namespace std;

int pa[205];
set<int> s;
bool visit[205];

void reset() {
	for (int i = 0; i <= 205; i++) {
		pa[i] = i;
	}
}

int find(int x) {
	if (pa[x] == x) {
		return x;
	}
	else
		return pa[x] = find(pa[x]);
}

void uni(int x, int y) {
	x = find(x);
	y = find(y);

	if (x != y)
	{
		pa[y] = x;
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	int counter = 0;
	reset();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (computers[i][j] == 1) {
				if (find(i) != find(j)) {
					uni(i, j);
					counter++;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		s.insert(pa[i]);
	}
	
	return answer = n - counter;
}

int main() {
	int n = 3;
	//vector<vector<int>> computers = { {1, 1, 0},{1, 1, 0},{0, 0, 1} };
	//vector<vector<int>> computers = { {1, 1, 0},{1, 1, 1},{0, 1, 1} };
	//vector<vector<int>> computers = { {1, 0, 0, 1},{0, 1, 1, 1},{0, 1, 1, 0},{1, 1, 0, 1} };
	vector<vector<int>> computers = { {1, 0, 1},{1, 0, 1},{0, 1, 0} };

	cout << solution(n, computers);
}