#include<iostream>
using namespace std;
#pragma warning(disable : 4996)

int number[100000];
int main()
{

   int n, m;
   int num;
   scanf("%d %d", &n, &m);
   number[0]=0;
   for (int i = 1; i <= n; i++)
   {
      scanf("%d", &num);
      number[i] = number[i - 1] + num;
   }
   for (int z = 0; z < m; z++)
   {
      int i, j;
      scanf("%d %d", &i, &j);
      printf("%d\n", number[j] - number[i - 1]);
   }
}