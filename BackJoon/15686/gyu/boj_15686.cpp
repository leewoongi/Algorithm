#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;

typedef struct node 
{
	int y;
	int x;
}Node;
int map[51][51];
vector<Node> house;
vector<Node> chiken;
vector<int> m_c;
vector<int>result_final;
int sum = INT32_MAX;
int result;
int result_test;

int min(int a, int b)
{
	return a > b ? b : a;
}

int main()
{
	int m_c_counter=0;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int map_input;
			cin >> map_input;
			map[i][j] = map_input;
			if (map_input == 1)
			{
				house.push_back({ i,j });
			}
			else if (map_input == 2)
			{
				chiken.push_back({ i,j });
				m_c_counter++;
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		m_c.push_back(1);
	}
	for (int i = 0; i < m_c_counter - m; i++)
	{
		m_c.push_back(0);
	}
	sort(m_c.begin(), m_c.end());
	do 
	{
		int house_size = house.size();
		int m_c_size = m_c.size();
		result = 0;
		for (int i = 0; i < house_size; i++) 
		{
			sum = INT32_MAX;
			for (int j = 0; j < m_c_size; j++)
			{
				if (m_c[j] == 1)
				{
					result_test = abs(house[i].y - chiken[j].y) + abs(house[i].x - chiken[j].x);
					sum = min(result_test, sum);
				}
			}
			result += sum;
		}
		result_final.push_back(result);
	} while (next_permutation(m_c.begin(), m_c.end()));
	sort(result_final.begin(), result_final.end());
	cout << result_final[0] << endl;

	return 0;
}