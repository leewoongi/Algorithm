#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>
#include<string>

#define arrx 51
#define arry 51
using namespace std;

typedef struct Node {
	int y;
	int x;
}node;

int y = 0;
int x = 0;
int check = 0;
int DX;
int DY;
int farm[arrx][arry];
bool visit[arrx][arry];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	int cabbage;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		check = 0;
		cin >> y >> x >> cabbage;
		DX = x;
		DY = y;

		for (int j = 0; j < x; j++)
		{
			for (int z = 0; z < y; z++)
			{
				farm[j][z] = 0;
				visit[j][z] = false;
			}
		}

		for (int j = 0; j < cabbage; j++)
		{
			cin >> x >> y;
			farm[x][y] = 1;
		}

		stack<node> ST;
		for (int j = 0; j < DY; j++)
		{
			for (int z = 0; z < DX; z++)
			{
				if (visit[j][z] == false && farm[j][z] == 1)
				{
					ST.push({ j,z });
					while (!ST.empty())
					{
						node N;
						N = ST.top();
						ST.pop();
						visit[j][z] = true;

						for (int g = 0; g < 4; g++)
						{
							int X = N.x + dx[g];
							int Y = N.y + dy[g];


							if (X >= 0 && Y >= 0 && X <= DX && Y <= DY)
							{
								if (farm[Y][X] == 1 && visit[Y][X] == false)
								{
									ST.push({ Y,X });
									visit[Y][X] = true;
								}
							}

						}
					}
					check++;
				}
			}
		}
		cout << check << endl;
	}
	return 0;
}