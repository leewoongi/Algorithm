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

using namespace std;

struct node
{
    int date;
    int sup;
    bool check;
};

bool cmp(node n1, node n2)
{
    return n1.sup > n2.sup;
}

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    int day = stock;
    vector<node> v;
    for (int i = 0; i < dates.size(); i++)
    {
        v.push_back({ dates[i],supplies[i],false });
    }

    sort(v.begin(), v.end(), cmp);

    while (day < k)
    {
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].date <= day && !v[i].check)
            {
                day += v[i].sup;
                v[i].check = true;
                answer++;
                break;
            }
        }
    }

    return answer;
}

int main()
{
    int st = 4;
    vector<int> d = { 4,10,15 };
    vector<int> s = { 20,5,10 };
    int k = 30;
    
    cout << solution(st, d, s, k);
}