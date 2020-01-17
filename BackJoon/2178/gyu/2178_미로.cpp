#include<iostream>
#include<queue>
#pragma warning(disable : 4996)
using namespace std;

typedef struct node {
   int y;
   int x;
}Node;

int miro[100][100];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int check[100][100];
int main()
{
   int n, m;
   int x=0;
   int y = 0;
   int cx = 0;
   int cy = 0;
   cin >> n >> m;
   check[cy][cx]= 1;
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         scanf("%1d", &miro[i][j]);
      }
   }
   queue<Node> Q;
   Q.push({ 0,0 });
   while (!Q.empty())
   {
      cx = Q.front().x;
      cy = Q.front().y;
      Q.pop();
      if (y == n - 1 && x == m - 1)
      {
         break;
      }
      for (int i = 0; i < 4; i++)
      {
         x = dx[i] + cx;
         y = dy[i] + cy;
         if (x<m&&y<n&&x>-1 && y>-1)
         {
            if (check[y][x] == 0 && miro[y][x] == 1)
            {
               Q.push({ y,x });
               check[y][x] = check[cy][cx] + 1;
            }
         }
      }
   }
   cout << check[n - 1][m - 1] << endl;
}