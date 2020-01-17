#include<iostream>
#include<vector>

using namespace std;

vector<int> V[1000];
bool visit[1000];
void dfs(int n)
{
   if (n == NULL)
   {
      return;
   }
   visit[n] = true;
   for (int i = 0; i < V[n].size(); i++)
   {
      int N = V[n][i];
      if (!visit[N])
      {
         dfs(N);
      }
   }
}
int main()
{
   int n, m;
   cin >> n >> m;
   for (int i = 0; i < m; i++)
   {
      int u, v;
      cin >> u >> v;
      V[u].push_back(v);
      V[v].push_back(u);
   }
   int result = 0;
   for (int i = 1; i <= n; i++)
   {
      if (!visit[i])
      {
         dfs(i);
         result++;
      }
   }
   cout << result << endl;
}