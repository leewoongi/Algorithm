#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int root[101];

bool compare(vector<int>x, vector<int>y)
{
   return x[2] < y[2];
}

int find(int x)
{
   if (root[x] == x)
   {
      return x;
   }
   else 
   {
      return root[x] = find(root[x]);
   }
}

bool union2(int x, int y)
{
   x = find(x);
   y = find(y);
   if (x == y) 
   {
      return false;
   }
   else {
      if (x > y)
      {
         root[x] = y;
      }
      else
      {
         root[y] = x;
      }
   }
   return true;
}

int solution(int n, vector<vector<int>> costs)
{
   int answer = 0;
   for (int i = 0; i < 101; i++)
      root[i] = i;
   sort(costs.begin(), costs.end(), compare);
   for (int i = 0; i < costs.size(); i++)
   {
      if (union2(costs[i][0], costs[i][1]))
      {
         answer += costs[i][2];
      }
   }
   return answer;
}

int main()
{
   vector<vector<int>> costs = 
   {
       {0,1,1}
      ,{0,2,2}
      ,{1,2,5}
      ,{1,3,1}
      ,{2,3,8}
   };
   cout << solution(4, costs);
}