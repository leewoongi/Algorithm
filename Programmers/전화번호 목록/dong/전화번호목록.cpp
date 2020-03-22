#include<iostream>
#include<string>
#include<vector>
#include<algorithm>


using namespace std;
char p_cut[1000001][20];
bool solution(vector<string> phone_book) {
    bool answer = true;
    int p_size=(int)phone_book.size();
    for(int i=0;i<p_size;i++){
        for(int j=0;j<phone_book[i].size();j++){
            p_cut[i][j]=phone_book[i][j];
        }
        
    }
    bool result=true;
    for(int i=0;i<p_size-1;i++){
        
        for(int j=i+1;j<p_size;j++){
            int cnt=0;
            int p2_size=min((int)phone_book[i].size(),(int)phone_book[j].size());
            for(int k=0;k<p2_size;k++){
                if(p_cut[i][k]==p_cut[j][k]){
                    cnt++;
                    if(cnt==p2_size){
                        result=false;
                        break;
                    }
                }
                else{
                    cnt=0;
                }
            }
            if(result==false){
                break;
            }
        }
        if(result==false){
            break;
        }
    }
    answer=result;
    
    return answer;
}
int main(){
    
    vector<string> p={"119","1195524421"};
    cout<<solution(p);
}
