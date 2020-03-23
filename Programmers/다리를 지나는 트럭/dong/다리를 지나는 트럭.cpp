#include<iostream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;
int arr[10001];
int solution(int bridge_length, int weight, vector<int> truck_weights) {
   int answer = 0;
   int t_size = truck_weights.size();
   int t_cnt_end = 0;
   int t_cnt_start = 0;
   vector<int> v;
   int i = 1;
   while (true) {
      int t_w = 0;
      int v_size = v.size();
      if (v_size > 0) {
         for (int j = 0; j < v_size; j++) {
            t_w += v[j];
         }
      }
      if (t_cnt_end < t_size) {
         if (t_w + truck_weights[t_cnt_end] <= weight) {
            v.push_back(truck_weights[t_cnt_end]);
            t_cnt_end++;
         }
      }
      int max_ar = 0;
      for (int k = t_cnt_start; k < t_cnt_end; k++) {
         arr[k] = arr[k] + 1;
         max_ar = max(max_ar, arr[k]);
      }
      if (max_ar == bridge_length) {

         v.erase(v.begin());
         t_cnt_start++;
      }
      int v_copysize = v.size();
      if (v_copysize == 0 && t_cnt_end == t_size) {
         answer = i + 1;
         break;
      }
      i++;
   }
   return answer;
}

int main() {
   vector<int> v = { 7,4,5,6 };

   cout << solution(2, 10, v);
}
