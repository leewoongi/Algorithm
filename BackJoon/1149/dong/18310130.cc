#include<iostream>
#include <vector>
#include<queue>
#include<algorithm>
using namespace std;

typedef struct NODE{
    int x; //index
    int cnt; //r,g,b
}node;
int arr[1001][1001];
int dp[1001][1001];
/*
 3
 26 40 83
 49 60 57
 13 89 99
 ----------
 3
 1 2 20
 997 1001 996
 5 4 1
 */

int n;
int result=2100000000;
bool tmp(const node &a,const node &b){
    return a.cnt<b.cnt;
}
int search(){
    for(int i=1;i<n;i++){
        for(int k=0;k<3;k++){//다음 인덱스
            if(k==0){
                dp[i][k]=min(dp[i-1][1]+dp[i][k],dp[i-1][2]+dp[i][k]);
            }
            if(k==1){
                dp[i][k]=min(dp[i-1][0]+dp[i][k],dp[i-1][2]+dp[i][k]);
            }
            if(k==2){
                dp[i][k]=min(dp[i-1][0]+dp[i][k],dp[i-1][1]+dp[i][k]);
            }
                
        }
        
    }
    for(int i=0;i<3;i++){
        if(dp[n-1][i]<result){
            result=dp[n-1][i];
        }
    }
    return result;
}
int main(){
    cin>>n;
    
    
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            
            cin>>arr[i][j];
            dp[i][j]=arr[i][j];
            //배열의 r=0,g=1,b=2 번째
        }
    }
    cout<<search();
    
}
