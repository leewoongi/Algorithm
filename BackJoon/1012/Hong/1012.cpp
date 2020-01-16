#include <iostream>
#include <string>
#include <stack>

using namespace std;

struct node {
	int x;
	int y;
};

int pool[51][51];
bool bpool[51][51];
int ci[4] = { -1,0,1,0 };
int cj[4] = { 0,1,0,-1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;

	for (int tc = 1; tc <= t; tc++)
	{
		for (int j = 0; j < 51; j++)
		{
			for (int r = 0; r < 51; r++)
			{
				pool[j][r] = 0;
				bpool[j][r] = false;
			}
		}

		int counter = 0;
		int x, y, n;
		cin >> x >> y >> n;

		for (int j = 0; j < n; j++)
		{
			int ox, oy;

			cin >> ox >> oy;

			pool[ox][oy] = 1;
		}


		for (int j = 0; j < x; j++)
		{
			for (int r = 0; r < y; r++)
			{
				if (pool[j][r] == 1 && bpool[j][r] == false)
				{
					stack<node> st;
					counter++;
					st.push({ j,r });
					bpool[j][r] = true;

					while (!st.empty())
					{
						node start = st.top();
						st.pop();

						for (int q = 0; q < 4; q++)
						{
							int rx = start.x + ci[q];
							int ry = start.y + cj[q];

							if (pool[rx][ry] == 1 && bpool[rx][ry] == false && rx >= 0 && ry >= 0 && rx < x && ry < y)
							{
								bpool[rx][ry] = true;
								st.push({ rx,ry });
							}
						}
					}
				}
			}
		}
		cout << counter << '\n';
	}
}