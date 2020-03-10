#include<iostream>
#include<algorithm>
using namespace std;

int result_map[1000][3];
int result;
int main()
{
   int n;
   cin >> n;
   for (int i = 0; i < n; i++)
   {
      int red, green, blue;
      cin >> red >> green >> blue;
      result_map[i][0] = red;
      result_map[i][1] = green;
      result_map[i][2] = blue;
   }
   for (int i = n - 1; i > 0; i--)
   {
      result_map[i-1][0] = min(result_map[i-1][0] + result_map[i][1], result_map[i-1][0] + result_map[i][2]);
      result_map[i-1][1] = min(result_map[i-1][1] + result_map[i][0], result_map[i-1][1] + result_map[i][2]);
      result_map[i-1][2] = min(result_map[i-1][2] + result_map[i][0], result_map[i-1][2] + result_map[i][1]);
   }
   result = min(result_map[0][0], min(result_map[0][1], result_map[0][2]));
   cout << result << endl;
   return 0;
}