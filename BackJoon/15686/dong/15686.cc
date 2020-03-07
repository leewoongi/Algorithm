
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int n,m;
int map[51][51];
int result=100000000;
int ho_c;
int ch_c;
typedef struct NODE{
    int x;
    int y;
    int dis;
}node;
vector<node> ch;//치킨
vector<node> ho;//집
vector<int> v;
bool cmp(const node &a,const node &b){
    return a.dis<b.dis;
}
/*bool desc(const node &a,const node &b){
    if(a.x==b.x){
        return a.y<b.y;
    }
    else{
        return a.x<a.x;
    }
}*/
void search(){
    int r=0;
    
    vector<node> ho_ch;//집에서 가까운 치킨집
    for(int j=0;j<ho_c;j++){ //각각의 집에서 치킨집 거리

        vector<node> ho_ch2;//집에서 가까운 치킨집
        for(int i=0;i<ch_c;i++){//조합 m만큼
            if(v[i]==1){
                int abs_r=(abs(ch[i].x-ho[j].x)+abs(ch[i].y-ho[j].y));
                ho_ch2.push_back({0,0,abs_r});
            }
        }
        
        sort(ho_ch2.begin(),ho_ch2.end(),cmp);
        ho_ch.push_back({0,0,ho_ch2[0].dis});
    }
    
    for(int i=0;i<ho_c;i++){
        r+=ho_ch[i].dis;
    }
    
    if(r<result){
        result=r;
    }
}
int main(){
    
    cin>>n>>m;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>map[i][j];
            if(map[i][j]==1){
                ho.push_back({i,j,0});
                ho_c++;
            }
            else if(map[i][j]==2){
                ch.push_back({i,j,0});
                ch_c++;
            }
        }
    }
    for(int i=0;i<ch_c-m;i++){
        v.push_back(0);
    }
    for(int i=0;i<m;i++){
        v.push_back(1);
    }
    do{
        search();
    }while(next_permutation(v.begin(),v.end()));
    
    cout<<result;
    
}
