#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

queue<int> q;
int arr[20001][20001];
int tmp[20001];
bool desc(int a, int b) {
   return a > b;
}
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int eg_size = (int)edge.size();
    for(int i=0;i<eg_size;i++){
        arr[edge[i][0]][edge[i][1]]=1;
        arr[edge[i][1]][edge[i][0]]=1;
    }
    tmp[1]=1;
    q.push(1);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        
        for(int i=1;i<=n;i++){
            if(arr[x][i]==1&&tmp[i]==0){
                tmp[i]=tmp[x]+1;
                q.push(i);
            }
        }
    }
    
    sort(tmp+1,tmp+n+1,desc);
    int tmp_max=tmp[1];
    for(int i=1;i<=n;i++){
        if(tmp[i]==tmp_max){
            answer++;
        }
    }
    return answer;
}

int main() {
   int n = 6;
   vector<vector<int>> ve = {
      {3,6},
      {4,3},
      {3,2},
      {1,3},
      {1,2},
      {2,4},
      {5,2}
   };
   cout << solution(n, ve);
}
