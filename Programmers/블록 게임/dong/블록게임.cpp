#include<iostream>
#include <string>
#include <vector>

using namespace std;
int n;
vector<vector<int>> v;

typedef struct NODE{
    int x;
    int y;
}node;
int dir_x[6]={0,0,1,1,2,2};//세로
int dir_y[6]={0,1,0,1,0,1};//세로

int dir_x2[6]={0,0,0,1,1,1};//가로
int dir_y2[6]={0,1,2,0,1,2};//가로

int map[51][51];
int tmp_map[51][51];
void copy_map(int b_size){
    
    for(int i=0;i<b_size;i++){
        for(int j=0;j<b_size;j++){
            
            tmp_map[i][j]=map[i][j];
        }
    }
}
int check1(int n){//세로
    int result=0;
    for(int i=0;i<n-2;i++){
        for(int j=0;j<n-1;j++){
            vector<node> v;
            int minus_cnt=0;
            int plus_cnt=0;
            int sm=-2;
            bool visit=false;
            for(int k=0;k<6;k++){
                
                int x=i+dir_x[k];
                int y=j+dir_y[k];
                if(tmp_map[x][y]==0){
                    break;
                }
                else if(tmp_map[x][y]==-1){
                    v.push_back({x,y});
                    minus_cnt++;
                }
                else if(tmp_map[x][y]!=-1&&visit==false){
                    v.push_back({x,y});
                    sm=tmp_map[x][y];
                    visit=true;
                    plus_cnt++;
                }
                else if(tmp_map[x][y]!=-1&&tmp_map[x][y]==sm){
                    v.push_back({x,y});
                    plus_cnt++;
                }
                
            }
            if(minus_cnt==2&&plus_cnt==4){
                for(int z=0;z<6;z++){
                    map[v[z].x][v[z].y]=0;
                }
                result++;
            }
        }
    }
    return result;
}
int check2(int n){//가로
    int result=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-2;j++){
            vector<node> v;
            int minus_cnt=0;
            int plus_cnt=0;
            int sm=-2;
            bool visit=false;
            for(int k=0;k<6;k++){
                
                int x=i+dir_x2[k];
                int y=j+dir_y2[k];
                if(tmp_map[x][y]==0){
                    break;
                }
                else if(tmp_map[x][y]==-1){
                    v.push_back({x,y});
                    minus_cnt++;
                }
                else if(tmp_map[x][y]!=-1&&visit==false){
                    v.push_back({x,y});
                    sm=tmp_map[x][y];
                    visit=true;
                    plus_cnt++;
                }
                else if(tmp_map[x][y]!=-1&&tmp_map[x][y]==sm){
                    v.push_back({x,y});
                    plus_cnt++;
                }
                
            }
            if(minus_cnt==2&&plus_cnt==4){
                for(int z=0;z<6;z++){
                    map[v[z].x][v[z].y]=0;
                }
                result++;
            }
        }
    }
    return result;
}
int solution(vector<vector<int>> board) {
    int answer = 0;
    int b_size=(int)board.size();
    
    for(int i=0;i<b_size;i++){
        for(int j=0;j<b_size;j++){
            
            map[i][j]=board[i][j];
        }
    }
    
    
    while(true){
        int result=0;
        copy_map(b_size);
        
        for(int i=0;i<b_size;i++){
            for(int j=0;j<b_size;j++){
                if(tmp_map[j][i]==0){
                    tmp_map[j][i]=-1;
                }
                else{
                    break;
                }
            }
        }
        result+=check1(b_size);
        copy_map(b_size);
        for(int i=0;i<b_size;i++){
            for(int j=0;j<b_size;j++){
                if(tmp_map[j][i]==0){
                    tmp_map[j][i]=-1;
                }
                else{
                    break;
                }
            }
        }
        result+=check2(b_size);
        if(result==0){
            break;
        }
        else{
            answer+=result;
        }
        
    };
    
    
    
    return answer;
}

int main(){
    cin>>n;
    
    
    for(int i=0;i<n;i++){
        vector<int> v2;
        for(int j=0;j<n;j++){
            int num;
            cin>>num;
            v2.push_back(num);
        }
        v.push_back(v2);
    }
    
    cout<<solution(v);
}
