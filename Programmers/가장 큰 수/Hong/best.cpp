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

int cal(int x)
{
    int a = x;

    if (a == 1000)
    {
        a;
    }
    else if (a >= 100)
    {
        a = (a*10) + a / 100;
    }
    else if (a >= 10)
    {
        a = (a * 100) + ((a / 10)*10) + (a - (a / 10) * 10);
    }
    else
    {
        a = (a * 1000) + (a * 100) + (a * 10) + a;
    }

    return a;
}

struct node
{
    int x;
    int y;
};

bool cmp(node n1, node n2)
{
    return n1.y > n2.y;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<node> v;
    bool check = false;
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] != 0)
            check = true;
        v.push_back({ numbers[i], cal(numbers[i]) });
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); i++)
    {
        answer += to_string(v[i].x);
    }

    if (!check)
        return "0";

    return answer;

}

int main()
{
    vector<int> v = { 0,0 };
    
    cout << solution(v);

}