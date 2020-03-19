#include<iostream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;


vector<vector<string>> relation={//16
    {"a","1","4"},
    {"2","1","5"},
    {"a","2","4"}
};
int result;
vector<int> v;
vector<int> v2;
vector<string> v3;
vector<vector<int>>check_v;
int check2(int v2_size){
    int cnt_result=0;
    int cnt=0;
    int v3_size=(int)v3.size();
    int check_size=(int)check_v.size();
    bool visit=false;
    if(check_size>0){
        for(int i=0;i<check_size;i++){
            int ch_cnt=0;
            for(int j=0;j<(int)check_v[i].size();j++){
                
                for(int k=0;k<v2_size;k++){
                    
                    if(check_v[i][j]==v2[k]){
                        
                        ch_cnt++;
                        if(ch_cnt<=v2_size&&ch_cnt>=(int)check_v[i].size()){
                            visit=true;
                        }
                    }
                }
            }
        }
    }
    if(visit==false){
        for(int i=0;i<v3_size-1;i++){
            for(int j=i+1;j<v3_size;j++){
                if(v3[i]==v3[j]){
                    cnt++;
                }
                
            }
        }
        
        if(cnt==0){
            cnt_result++;
            vector<int>ch_v;
            for(int i=0;i<v2_size;i++){
                ch_v.push_back(v2[i]);
                cout<<v2[i]<<"=\n";
            }
            check_v.push_back(ch_v);
        }
    }
    return cnt_result;
}
void check(int v_size){
    int v2_size=(int)v2.size();
    int cnt=0;
    
    for(int j=0;j<v_size;j++){//6
        
        string str="";
        for(int i=0;i<v2_size;i++){
            
            str+=relation[j][v2[i]];
            
            
        }
        if(str!=""){
            v3.push_back(str);
        }
        
    }
    cnt=check2(v2_size);
    result+=cnt;
    while(!v3.empty())v3.pop_back();
    
}
int solution(vector<vector<string>> relation) {
    int answer = 0;
    
    int v_size=(int)relation.size();//row 6
    int v_size2=(int)relation[0].size();//column 4
    for(int i=1;i<=v_size2;i++){//1234
        for(int j=v_size2;j>=1;j--){//4321
            if(j>i){
                v.push_back(0);
            }else{
                v.push_back(1);
            }
            
        }
        do{//조합으로 가지수 체크

            for(int i=0;i<v_size2;i++){
                if(v[i]==1){
                    v2.push_back(i);
                }
            }
            check(v_size);
            while(!v2.empty())v2.pop_back();
            
        }while(next_permutation(v.begin(), v.end()));
        while(!v.empty())v.pop_back();
    }
    answer=result;
    
    return answer;
}

int main(){
    cout<<solution(relation);
}
