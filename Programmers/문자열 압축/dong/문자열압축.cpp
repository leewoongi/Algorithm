#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;
typedef struct NODE{
    int x;
    string y;
}node;

vector<string> v;
vector<node> nv;
vector<int>v_length;
int cutting(int i,int s_size,string s){
    int st=0;
    int v_size=0;
    if(s_size%i==0){
        s_size=s_size/i;
    }
    else{
        s_size=s_size/i+1;
    }
    for(int j=0;j<s_size;j++){
        string str=s.substr(st,i);
        st=st+i;
        v.push_back(str);
        v_size++;
    }
    return v_size;
}
int solution(string s) {
    
    int s_size=(int)s.length();
    
    int answer = 0;
    for(int i=1;i<=s_size;i++){//몇 자릿수로 짜르는지
        int cnt=1;
        int v_size=cutting(i,s_size,s);
        for(int j=0;j<v_size;j++){
                if(j+1<v_size){
                    if(v[j]==v[j+1]){
                        if(cnt>1){
                            nv.pop_back();
                            cnt++;
                            nv.push_back({cnt,v[j]});
                        }
                        else{
                            cnt++;
                            nv.push_back({cnt,v[j]});
                        }
                    }
                    else if(cnt==1&&v[j]!=v[j+1]){
                        cnt=1;
                        nv.push_back({cnt,v[j]});
                    }
                    else{
                        cnt=1;
                    }
                }
                else if(j==v_size-1&&cnt==1&&v[j]!=v[j-1]){
                    cnt=1;
                    nv.push_back({cnt,v[j]});
                    
                }
                
            }
        int nv_size=(int)nv.size();
        int len=0;
        for(int k=0;k<nv_size;k++){
            if(nv[k].x==1){
                len+=(int)nv[k].y.length();
            }
            else{
                if(nv[k].x<10){
                    len+=(int)nv[k].y.length()+1;
                }
                else if(nv[k].x>=10&&nv[k].x<100){
                    len+=(int)nv[k].y.length()+2;
                }
                else if(nv[k].x>=100&&nv[k].x<1000){
                    len+=(int)nv[k].y.length()+3;
                }
                else{
                    len+=(int)nv[k].y.length()+4;
                }
            }
        }
        v_length.push_back(len);
        
        while(!v.empty())v.pop_back();
        while(!nv.empty())nv.pop_back();
        
    }
    
    
    sort(v_length.begin(),v_length.end());
    answer=v_length[0];
    return answer;
}
int main(){
    string s="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    
    cout<<solution(s);
}
