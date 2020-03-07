
#include<iostream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;
bool visit[31];

int arr[31];
int result;
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int lo_size=lost.size();
    int re_size=reserve.size();
    for(int i=0;i<n;i++){
        arr[i]=i+1;
    }
    
    for(int j=0;j<lo_size;j++){
        arr[lost[j]-1]=0;
    }
    for(int j=0;j<re_size;j++){
        if(arr[reserve[j]-1]==0){
            arr[reserve[j]-1]=-1;
            visit[reserve[j]-1]=true;
        }
        else{
            arr[reserve[j]-1]=0;
            visit[reserve[j]-1]=true;
        }
    }
    for(int i=0; i<n;i++)//check
    {
        if(arr[i]!=0){
            visit[i]=true;
        }
    }
    for(int i=0;i<n;i++){
        if(i-1>0||i+1<=n){
            if(arr[i]==0&&visit[i]==false){//lost 배열요소
                if(arr[i-1]==0&&visit[i-1]==true){
                    visit[i]=true;
                    arr[i]=-1;
                    arr[i-1]=-1;
                    continue;
                }
                if(arr[i+1]==0&&visit[i+1]==true){
                    arr[i]=-1;
                    visit[i]=true;
                    arr[i+1]=-1;
                }
            }
            
        }
    }
    
    for(int i=0;i<n;i++){
        if(visit[i]==true){
            answer++;
        }
    }
    
    return answer;
}
