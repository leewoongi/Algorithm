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

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    vector<pair<int, int>> v;
    int counter = 0;
    int w;

    while (1)
    {
        w = 0;
        counter++;

        if (!v.empty())
        {
            if (v[0].second == bridge_length)
            {
                v.erase(v.begin());
            }

            for (int i = 0; i < v.size(); i++)
            {
                w += v[i].first;
            }
        }

        if (!truck_weights.empty())
        {
            if (w < weight)
            {
                if (w + truck_weights[0] <= weight)
                {
                    v.push_back(pair<int, int>(truck_weights[0], 0));
                    truck_weights.erase(truck_weights.begin());
                }
            }
        }

        for (int i = 0; i < v.size(); i++)
        {
            v[i].second++;
        }

        if (truck_weights.empty() && v.empty())
        {
            break;
        }
    }
    answer = counter;

    return answer;
}

int main()
{
    int a = 100;
    int b = 100;
    vector<int> v = { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };
    
    cout << solution(a, b, v);
}