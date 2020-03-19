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

string st[30];
vector<int> index;
vector<int> er; // 후보키
vector<int> sample;

bool cmp(int size, string n_str)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (st[i] == st[j])
			{
				return true;
			}
		}
	}

	int nsize = n_str.length();
	//n_str의 부분집합중에 er이 속하면 true
	//atoi(number.c_str())
	for (int q = 0; q < (1<<nsize); q++) 
	{
		string com;
		for (int z = 0; z < nsize; z++) 
		{
			if (q & (1 << z))
			{
				com += n_str[z];
			}
		}

		for (int z = 0; z < er.size(); z++)
		{
			if (to_string(er[z]).compare(com) == 0)
			{
				return true;
			}
		}
	}

	return false;
}

void st_clear(int size)
{
	for (int i = 0; i < size; i++)
	{
		st[i] = '\0';
	}
}

void comb(int n, int c)
{
	index.clear();

	for (int i = 0; i < n - c; i++)
	{
		index.push_back(0);
	}

	for (int i = 0; i < c; i++)
	{
		index.push_back(1);
	}
}

int solution(vector<vector<string>> relation) {
	int answer = 0;

	for (int i = 1; i <= relation[0].size(); i++)
	{
		if (!sample.empty())
		{
			for (int q = 0; q < sample.size(); q++)
			{
				er.push_back(sample[q]);
			}
			sample.clear();
		}
		sort(er.begin(), er.end());
		comb(relation[0].size(), i);

		do
		{
			st_clear(relation.size());
			string test_number;
			for (int j = 0; j < relation.size(); j++) //행
			{
				for (int r = 0; r < relation[0].size(); r++) //열
				{
					if (index[r] == 1)
					{
						st[j] += relation[j][r] + " ";
					}
				}
			}

			for (int r = 0; r < relation[0].size(); r++) //열
			{
				if (index[r] == 1)
				{
					test_number += to_string(r + 1);
				}
			}

			if (!cmp(relation.size(),test_number))
			{
				string number;
				for (int r = 0; r < relation[0].size(); r++) //열
				{
					if (index[r] == 1)
					{
						number += to_string(r+1);
					}
				}

				sample.push_back(atoi(number.c_str()));
				answer++;
			}

		} while (next_permutation(index.begin(), index.end()));
	}

	return answer;
}

int main()
{
	vector<vector<string>> relation = {
		{"a", "1", "4"},{"2", "1", "5"},{"a", "2", "4"}
	};

	cout << solution(relation);

}