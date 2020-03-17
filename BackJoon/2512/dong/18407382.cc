#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct NODE{
    int x;
    int y;
}node;

vector<node> nv;
int n,m;
vector<int> v;
bool tmp(const node &a,const node &b){
    return a.y<b.y;
}
int main() {
    cin>>n;
    
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        v.push_back(num);
    }
    
    sort(v.begin(),v.end());
    cin>>m;
    
    int left=0;
    int right=v[v.size()-1];
    while(left<=right){
        int mid=(left+right)/2;
        int result=0;
        
        for(int i=0;i<n;i++){
            if(v[i]>=mid){
                result=result+mid;
            }
            else{
                result=result+v[i];
            }
        }
        
        
        if(result<=m){
            left=mid+1;
            nv.push_back({mid,abs(result-m)});
        }
        
        if(result>m){
            right=mid-1;
        }
    }
    sort(nv.begin(),nv.end(),tmp);
    
    cout<<nv[0].x;
    
}
