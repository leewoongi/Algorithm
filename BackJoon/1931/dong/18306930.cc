#include<iostream>
#include <vector>
#include<queue>
#include<algorithm>
using namespace std;

typedef struct NODE{
    int x; //시작시간
    int y; //종료시간
    int cnt; //그 값의 횟수
}node;

vector<node> v;
int n;
bool tmp(const node &a,const node &b){
    if(a.y==b.y){
        return a.x<b.x;
    }
    else{
        return a.y<b.y;
    }
}
bool desc(const node &a,const node &b){
    return a.cnt>b.cnt;
}
void check(){
    int x_index=0;
    int y_index=v[0].y;
    for(int i=0;i<n;i++){
        
        if(i+1<n){
            if(v[i+1].x>=y_index){
                v[i +1].cnt+=v[x_index].cnt;
                x_index=i+1;
                y_index=v[i+1].y;
                
            }
            
        }
    }
    
    sort(v.begin(),v.end(),desc);
    
}
int main(){
    cin>>n;
    
    for(int i=0;i<n;i++){
        int s,e;
        cin>>s>>e;
        v.push_back({s,e,1});
        
    }
    
    sort(v.begin(),v.end(),tmp);
    
    check();
    
    cout<<v[0].cnt;
}
