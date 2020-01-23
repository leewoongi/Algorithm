#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n;
int m;
int x, y;
int rx, ry;
vector<int> family[101];
int result[101];
int bfs(void)
{
   queue<int>q;
   q.push(rx);
   while (!q.empty())
   {
      int node = q.front();
      q.pop();

      if (node == ry) 
      {
         return result[ry];
      }
      for (int i = 0; i < family[node].size(); i++)
      {
         int next = family[node][i];
         if (result[next] == 0)
         {
            q.push(next);
            result[next] = result[node] + 1;
         }
      }
   }
   return -1;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);
   cin >> n;
   cin >> rx >> ry;
   cin >> m;
   for (int i = 0; i < m; i++)
   {
      cin >> x >> y;
      
      family[x].push_back(y);
      family[y].push_back(x);
      
   }
   cout << bfs() << endl;
}