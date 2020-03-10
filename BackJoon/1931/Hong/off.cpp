#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct node
{
    int x;
    int y;
};

bool cmp(node n1, node n2)
{
    if (n1.y != n2.y)
    {
        return n1.y < n2.y;
    }
    else
    {
        return n1.x < n2.x;
    }
}

vector<node> v;
int start, counter;

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({ a,b });
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < N; i++)
    {
        if (v[i].x >= start)
        {
            start = v[i].y;
            counter++;
        }
    }

    cout << counter;
}