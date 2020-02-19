#include<iostream>

using namespace std;

int arr[16][2];
int result[16];
int n;

int max(int a,int b){
    return a>b?a:b;
}
void quest(int n){
    for(int i=n-1;i>=0;i--){
        if(i+arr[i][0]>n){
            result[i]=result[i+1];
        }
        else{
            result[i]=max(result[i+1],result[i+arr[i][0]]+arr[i][1]);
        }
    }
    cout<<result[0]<<'\n';
}
int main(){
    cin>>n;
        
    for(int i=0;i<n;i++){
        cin>>arr[i][0]>>arr[i][1];
    }
    quest(n);
    
}                                             