#include<iostream>

using namespace std;

int coin[101];
int arr[10001];
int min(int n, int m)
{
   return n > m ? m:n;
}


int main()
{
   int n, k;
   cin >> n >>k;
   fill(arr + 1, arr + 10001, 10001);
   coin[0] = 0;
   arr[0] = 0;
   for (int i = 1; i <=n; i++)
   {
      cin >> coin[i];
   }
   for (int i = 1; i <= n; i++)
   {
      for (int j = coin[i]; j <= k; j++)
      {
         arr[j] = min(arr[j],arr[j-coin[i]]+1);
      }
   }
   if (arr[k] == 10001)
   {
      cout << -1 << endl;
   }
   else
   {
      cout << arr[k] << endl;
   }
   return 0;
}