#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int parent[101];
bool check = false;

bool cmp(const vector<int> x, const vector<int> y) {
    return x[2] < y[2];
}

int find(int x)
{
    if (parent[x] == x)
        return x;
    else
        return find(parent[x]);
}

void uni(int x, int y)
{
    x = find(x);
    y = find(y);

    if (parent[y] != x)
    {
        parent[y] = x;
        check = true;
    }
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    int loop = 1;
    vector<int> counter;

    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    // 가중치 오름차순 정렬
    sort(costs.begin(), costs.end(), cmp);
    
    for (int i = 0; i < costs.size(); i++)
    {
        check = false;
        uni(costs[i][0], costs[i][1]);
        if (check)
        {
            answer += costs[i][2];
        }
    }
    
    return answer;
}

int main() {

    int n = 4;

    vector<vector<int>> costs = {
       {0,1,1},
       {0,2,2},
       {1,2,5},
       {1,3,1},
       {2,3,8}
    };

    solution(n, costs);
}