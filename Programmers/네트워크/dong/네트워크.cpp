#include<iostream>
#include <string>
#include <vector>
#include<queue>
#include<algorithm>

using namespace std;
#define INF 210000000
vector<int> v[201];
queue<int>q;
bool visit[201];
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for (int i = 0; i < (int)computers.size(); i++) {
        for (int j = 0; j < (int)computers[i].size(); j++) {
            if (i == j)
                continue;
            if(computers[i][j]==0){
                continue;
            }
            else{
                v[i+1].push_back(j+1);
            }
            
        }
    }
    
    for(int i=1;i<=n;i++){
        if(visit[i]==true){
            continue;
        }
        q.push(i);
        answer++;
        while(!q.empty()){
            int x=q.front();
            visit[x]=true;
            q.pop();
            int cnt=(int)v[x].size();
            for(int j=cnt-1;j>=0;j--){
                q.push(v[x][j]);
                v[x].pop_back();
            }
        }
    }
    

    return answer;
}
int main(){
    int n=3;
    vector<vector<int>> v={
        {1,1,0},{1,1,0},{0,0,1}
    };
    cout<<solution(n, v);
}
