#include<iostream>
#include<algorithm>
using namespace std;
#define INF 210000000

int arr[101][101];
int main() {
   int n, m;
   cin >> n;
   cin >> m;
   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
         if (i == j)
            continue;
         arr[i][j] = INF;

      }
   }
   for (int i = 0; i < m; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      if (arr[b][a] < c) {
         continue;
      }
      else {
         arr[b][a] = c;
      }
   }
   for (int k = 1; k <= n; k++) {
      for (int i = 1; i <= n; i++) {
         for (int j = 1; j <= n; j++) {
            if (i == j)
               continue;
            arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
         }
      }
   }
   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
         if (arr[j][i] == INF) {
            cout << 0<<" ";
         }
         else {
            cout << arr[j][i] << " ";
         }
      }
      cout << '\n';
   }

   return 0;

}
