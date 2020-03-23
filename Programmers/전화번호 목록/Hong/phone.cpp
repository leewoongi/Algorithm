#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cmath>
#include<stack>

using namespace std;

bool cmp(string s1, string s2)
{
    return s1.size() < s2.size();
}

bool solution(vector<string> phone_book) 
{
    sort(phone_book.begin(), phone_book.end(),cmp);

    for (int i = 0; i < phone_book.size(); i++)
    {
        for (int j = i+1; j < phone_book.size(); j++)
        {
            string s;
            for (int r = 0; r < phone_book[i].size(); r++)
            {
                s += phone_book[j][r];
            }
            if (phone_book[i] == s)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    vector<string> pb = { "123","456","789" };

    cout << solution(pb);
}