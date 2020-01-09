#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<stack>

using namespace std;
static const int dx[4] = { 1,0,-1,0 };
static const int dy[4] = { 0,1,0,-1 };
bool visit[16][16];
int miro[16][16];

stack<int> SX;
stack<int>SY;
int main()
{
	
	for (int i = 0; i < 10; i++)
	{
		int x = 1;
		int y = 1;
		int ok = 0;
		int n;
		cin >> n;
		for (int j = 0; j < 16; j++)
		{
			for (int z = 0; z < 16; z++)
			{
				scanf("%1d", &miro[j][z]);//1dÀÔ·ÂÆø
			}
		}
		for (int j = 0; j < 16; j++)
		{
			for (int z = 0; z < 16; z++)
			{
				visit[j][z] = false;
			}
		}
		SX.push(1);
		SY.push(1);
		while (!SX.empty() && !SY.empty())
		{
			x = SX.top();
			y = SY.top();
			SX.pop();
			SY.pop();
			visit[y][x] = true;
			for (int i = 0; i < 4; i++)
			{
				if (x >= 0 && x < 17 && y >= 0 && y < 16) 
				{
					if (miro[y][x + dx[i]] == 0 && visit[y][x + dx[i]] == false )
					{
						visit[y][x + dx[i]] = true;
						SX.push(x + dx[i]);
						SY.push(y);
					}
					else if (miro[y + dy[i]][x] == 0 && visit[y + dy[i]][x] == false )
					{
						visit[y + dy[i]][x] = true;
						SY.push(y + dy[i]);
						SX.push(x);
					}
					else if (miro[y][x + dx[i]] == 3|| miro[y + dy[i]][x] == 3)
					{
						ok = 1;
						break;
					}
				}
			}
		}
		cout << "#" << " " << n << " " << ok << endl;
	}
}