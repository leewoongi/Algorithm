#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
typedef struct NODE{
    int x;
    int y;
    int brk;
    int cnt;
}node;
queue<node> q;
int dir_x[4]={0,-1,0,1};
int dir_y[4]={-1,0,1,0};

int map[1001][1001];
bool visit[1001][1001];
int result=2100000000;
int n,m;
int copy_map[1001][1001];
void search(){
    q.push({0,0,0,1});
    visit[0][0]=true;
    
    while(!q.empty()){
        node nd=q.front();
        q.pop();
        
        if(nd.x==n-1&&nd.y==m-1){
            result=nd.cnt;
            break;
        }
        for(int i=0;i<4;i++){
            int x=nd.x+dir_x[i];
            int y=nd.y+dir_y[i];
            
            
            if(x>=0&&x<n&&y>=0&&y<m){
                if(visit[x][y]==false){
                    if(map[x][y]==0){//벽이 아닐때
                        q.push({x,y,nd.brk,nd.cnt+1});
                        copy_map[x][y]=nd.brk;
                        visit[x][y]=true;
                    }
                    else {//벽일때
                        if(nd.brk == 0){
                            q.push({x,y,nd.brk+1,nd.cnt+1});
                            visit[x][y]=true;
                            copy_map[x][y]= nd.brk;
                        }
                        
                    }
                }
                else{
                    if(copy_map[x][y]>nd.brk){
                        q.push({x,y,nd.brk,nd.cnt+1});
                        copy_map[x][y]=nd.brk;
                    }
                }
            }
        }
    }
}
int main(){
    cin>>n>>m;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%1d",&map[i][j]);
        }
    }
    
    search();
    if(result==2100000000){
        result=-1;
    }
    cout<<result;
}
