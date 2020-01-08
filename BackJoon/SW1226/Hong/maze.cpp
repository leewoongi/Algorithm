#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	int maze[16][16];
	int tc_number, oi, oj, ri, rj;
	int ci[4] = { -1,0,1,0 };
	int cj[4] = { 0,1,0,-1 };
	bool bmaze[16][16];

	vector<int> i_vector;
	vector<int> j_vector;

	for (int t = 0; t < 10; t++)
	{
		for (int i = 0; i < 16; i++)
		{
			for (int j = 0; j < 16; j++)
			{
				bmaze[i][j] = false;
			}
		}
		i_vector.clear();
		i_vector.clear();
		

		scanf("%d", &tc_number);

		for (int i = 0; i < 16; i++)
		{
			for (int j = 0; j < 16; j++)
			{
				scanf("%1d", &maze[i][j]);
				if (maze[i][j] == 2)
				{
					i_vector.push_back(i);
					j_vector.push_back(j);
				}
			}
		}

		while (1)
		{
			oi = i_vector.back();
			oj = j_vector.back();
			bmaze[oi][oj] = true;
			i_vector.pop_back();
			j_vector.pop_back();

			for (int i = 0; i < 4; i++)
			{
				ri = oi + ci[i];
				rj = oj + cj[i];

				if (ri > 0 && rj > 0 && ri < 16 && rj < 16 && !(bmaze[ri][rj]) && maze[ri][rj] != 1 && maze[ri][rj] != 2)
				{
					i_vector.push_back(ri);
					j_vector.push_back(rj);
				}
			}

			if (maze[oi][oj]==3)
			{
				cout << "#" << tc_number << " 1\n";
				break;
			}
			else if (i_vector.empty())
			{
				cout << "#" << tc_number << " 0\n";
				break;
			}
		}
	}
	return 0;
}