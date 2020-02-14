#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int dp1[100005];
int dp2[100005];

int solution(vector<int> sticker)
{
    int answer;

    dp1[0] = sticker[0];
    dp1[1] = sticker[0];

    if (sticker.size() == 1)
        return sticker[0];
    else if (sticker.size() == 2)
        return max(sticker[0], sticker[1]);

    for (int i = 2; i < sticker.size(); i++)
    {
        dp1[i] = max(dp1[i - 1], dp1[i - 2] + sticker[i]);
    }

    dp2[1] = sticker[1];
    for (int i = 2; i < sticker.size(); i++)
    {
        dp2[i] = max(dp2[i - 1], dp2[i - 2] + sticker[i]);
    }

    answer = max(dp1[sticker.size() - 2], dp2[sticker.size() - 1]);
    return answer;
}

int main()
{
	vector<int> sticker =
	{
		{10,5,5,40,5}
	};

	cout << solution(sticker);
}