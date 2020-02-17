#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef struct node {
   int r;
   int c;
   int s;
}Node;

int init_arrays[101][101];
int arrays[101][101];
int rcs[6][3];
int r1[6], c1[6];
int r2[6], c2[6];
int check_arrays1;
int check_arrays2;
vector<int> V;
vector<Node> Vrcs;
vector<int>v2;
int rx, ry;
void check_circle_min(int n, int m)
{
   int result = 0;
   int result_sum = 0;
   for (int i = 1; i <= n; i++)
   {
      for (int j = 1; j <= m; j++)
      {
         result = arrays[i][j];
         result_sum += result;
      }
      V.push_back(result_sum);
      result = 0;
      result_sum = 0;
   }
}

void circle(int k)
{
   int dr, dc;
   
   for (int i = 0; i < k; i++)
   {
      dr = r1[i] + r2[i];
      dc = c1[i] + c2[i];
      while (true) 
      {
         if (dr / 2 == r1[i] && dc / 2 == c1[i])
         {
            break;
         }
         check_arrays1 = arrays[r1[i]][c1[i]];
         check_arrays2 = arrays[r1[i]][c1[i] + 1];
         arrays[r1[i]][c1[i] + 1] = check_arrays1;
         for (int j = c1[i]+1; j < c2[i]; j++)
         {
            if (j < c2[i])
            {
               check_arrays1 = check_arrays2;
               check_arrays2 = arrays[r1[i]][j + 1];
            }
            arrays[r1[i]][j + 1] = check_arrays1;
         }
         check_arrays1 = check_arrays2;
         check_arrays2 = arrays[r1[i] + 1][c2[i]];
         arrays[r1[i] + 1][c2[i]] = check_arrays1;
         for (int j = r1[i] + 1; j < r2[i]; j++)
         {
            if (j < r2[i])
            {
               check_arrays1 = check_arrays2;
               check_arrays2 = arrays[j + 1][c2[i]];
            }
            arrays[j + 1][c2[i]] = check_arrays1;
         }
         check_arrays1 = check_arrays2;
         check_arrays2 = arrays[r2[i]][c2[i] - 1];
         arrays[r2[i]][c2[i] - 1] = check_arrays1;
         for (int j = c2[i] - 1; j > c1[i]; j--)
         {
            if (j > c1[i])
            {
               check_arrays1 = check_arrays2;
               check_arrays2 = arrays[r2[i]][j - 1];
            }
            
            arrays[r2[i]][j - 1] = check_arrays1;
         }
         check_arrays1 = check_arrays2;
         check_arrays2 = arrays[r2[i] - 1][c1[i]];
         arrays[r2[i] - 1][c1[i]] = check_arrays1;
         for (int j = r2[i] - 1; j > r1[i]; j--)
         {
            if (j > r1[i])
            {
               check_arrays1 = check_arrays2;
               check_arrays2 = arrays[j - 1][c1[i]];
            }
            arrays[j - 1][c1[i]] = check_arrays1;
         }
         r1[i] = r1[i] + 1;
         c1[i] = c1[i] + 1;
         r2[i] = r2[i] - 1;
         c2[i] = c2[i] - 1;
      }
   }
}

void circle_rcs(int k)
{
   for (int i = 0; i < k; i++)
   {
      for (int j = 0; j < 2; j++)
      {
         if (j == 0)
         {
            r1[i] = Vrcs[v2[i]].r - Vrcs[v2[i]].s;
            r2[i] = Vrcs[v2[i]].r + Vrcs[v2[i]].s;
         }
         else if (j == 1)
         {
            c1[i] = Vrcs[v2[i]].c - Vrcs[v2[i]].s;
            c2[i] = Vrcs[v2[i]].c + Vrcs[v2[i]].s;
         }
      }
   }
   circle(k);
}

void init_ar(int n,int m)
{
   for (int i = 1; i <= n; i++)
   {
      for (int j = 1; j <= m; j++)
      {
         arrays[i][j] = init_arrays[i][j];
      }
   }
}

int main()
{
   int n, m, k;
   int r, c, s;
   cin >> n >> m >> k;
   for (int i = 1; i <= n; i++)
   {
      for (int j = 1; j <= m; j++)
      {
         cin >> arrays[i][j];
         init_arrays[i][j] = arrays[i][j];
      }
   }
   for (int i = 0; i < k; i++)
   {
      cin >> r>>c>>s;
      Vrcs.push_back({ r,c,s });
      v2.push_back(i);
   }
   sort(v2.begin(), v2.end());
   do
   {
      circle_rcs(k);
      check_circle_min(n, m);
      init_ar(n, m);
   } while (next_permutation(v2.begin(),v2.end()));
   sort(V.begin(), V.end());
   cout << V[0] << endl;
   return 0;
}