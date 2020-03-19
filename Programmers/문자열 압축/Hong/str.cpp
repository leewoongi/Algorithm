#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<functional>
#include<cmath>
#include<stack>

using namespace std;

string sam, s_next;
vector<int> com_len;
string st;
int len;

void com(int n)
{
    int index = 0;
    string result;
    while(index <= len-n)
    {
        int counter = 1;
        string sam;

        for (int s = 0; s < n; s++)
        {
            sam += st[index];
            index++;
        }

        while (1)
        {
            string s_next;
            for (int s = 0; s < n; s++)
            {
                if (st[index + s] == '\0')
                {
                    result += s_next;
                    break;
                }
                s_next += st[index + s];
            }

            if (sam == s_next)
            {
                counter++;
                index = index + n;
                continue;
            }
            else
            {
                if (counter > 1)
                {
                    result += to_string(counter) + sam;
                }
                else
                {
                    result += sam;
                }
                break;
            }
        }
    }
    com_len.push_back(result.length());
}

int solution(string s) {
    int answer = 0;
    len = s.length();
    for (int l = 1; l <= len; l++)
    {
        st = s;
        com(l);
    }
    sort(com_len.begin(), com_len.end());
    answer = com_len[0];

    return answer;
}

int main()
{
    string s = "aabbaccc";

    cout << solution(s);
}