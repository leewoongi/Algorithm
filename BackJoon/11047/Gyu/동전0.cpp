#include<iostream>

using namespace std;

int tama[10];
int main()
{
   int n;
   int k;
   int count = 0;
   int result = 0;
   cin >> n >> k;
   for (int i = 0; i < n; i++)
   {
      cin >> tama[i];
   }
   while (k > 0)
   {
      for (int i = 0; i < n; i++)
      {
         if (tama[i] > k)
         {
            break;
         }
         count++;
      }
      count--;
      k = k - tama[count];
      result++;
      count = 0;
   }
   cout << result << endl;
}