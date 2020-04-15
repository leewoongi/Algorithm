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

using namespace std;

bool visit[20010];

struct val {
    int x;
    int d;
};

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    vector<int> res;
    vector<int> node[20010];
    queue<val> q;

    for (int i = 0; i < edge.size(); i++) {
        node[edge[i][0]].push_back(edge[i][1]);
        node[edge[i][1]].push_back(edge[i][0]);
    }

    visit[1] = true;
    for (int i = 0; i < node[1].size(); i++) {
        q.push({ node[1][i],1 });
        visit[node[1][i]] = true;
    }

    while (!q.empty()) {
        val sample = q.front();
        q.pop();
        visit[sample.x] = true;
        res.push_back(sample.d);

        for (int i = 0; i < node[sample.x].size(); i++) {
            if (!visit[node[sample.x][i]]) {
                visit[node[sample.x][i]] = true;
                q.push({ node[sample.x][i] , sample.d + 1 });
            }
        }
    }

    sort(res.begin(), res.end(), greater<int>());
    int max = res[0];

    for (int i = 0; i < res.size(); i++) {
        if (max == res[i]) {
            answer++;
        }
        else {
            break;
        }
    }
    return answer;
}

int main() {
    int n = 6;
    vector<vector<int>> edge = { {3, 6},{4, 3},{3, 2},{1, 3},{1, 2},{2, 4},{5, 2} };

    cout << solution(n, edge);
}