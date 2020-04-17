#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef struct NODE {
    int data;
    int dis;
}node;

bool visit[20001];
queue<node> q;
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    int size = edge.size();
    vector<vector<int>> v(size);
    
    for (int i = 0; i < size; i++) {
        v[edge[i][0]].push_back(edge[i][1]);
        v[edge[i][1]].push_back(edge[i][0]);
    }

    q.push({ 1,1 });
    visit[1] = true;
    int result = 0;

    while (!q.empty()) {

        node p = q.front();
        q.pop();
        
        if (result <= p.dis) {
            if (result == p.dis) {
                answer++;
            }
            else {
                result = p.dis;
                answer = 1;
            }
        }


        int len = v[p.data].size();
        for (int i = 0; i < len; i++) {
            if (visit[v[p.data][i]] == false) {
                q.push({ v[p.data][i],p.dis + 1 });
                visit[v[p.data][i]] = true;
            }
        }
    }

    
    return answer;
}

int main() {

    int n = 6;
    vector<vector<int>> edge = {
        {3,6},
        {4,3},
        {3,2},
        {1,3},
        {1,2},
        {2,4},
        {5,2}
    };

    solution(n, edge);
    return 0;
}