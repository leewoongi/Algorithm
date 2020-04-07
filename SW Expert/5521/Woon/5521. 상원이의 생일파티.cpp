#include <iostream>
#include <string>
#include <vector>
#include<queue>
#include <algorithm>
#include <map>

using namespace std;
typedef struct NODE {
    int num;
    int count;
}node;

queue<node> q;
bool visit[501];

void init_visit(int n) {

    for (int i = 0; i <= n; i++) {
        visit[i] = false;
    }
}

int main() {

    int t, tc;
    cin >> t;

    for (int tc = 1; tc <= t; tc++) {

        vector<int> v[501];
        int n, m;
        cin >> n >> m;

        init_visit(n);

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;

            v[a].push_back(b);
            v[b].push_back(a);
        }

        q.push({ 1,0 });
        visit[1] = true;

        int result = 0;
        while (!q.empty()) {

            node p = q.front();
            q.pop();

            if (p.count == 2) {
                continue;
            }

            int size = v[p.num].size();
            for (int i = 0; i < size; i++) {
                int value = v[p.num][i];
                if (visit[value] == false) {
                    q.push({ value, p.count + 1 });
                    visit[value] = true;
                    result = result + 1;
                }
            }
        }


        cout << "#" << tc << " " << result << endl;
    }


    return 0;
}