#include<iostream>

using namespace std;
int l,p,v;
int re,sh;//나머지와 몫
int i;
int main(){
    while(cin>>l>>p>>v){
        i++;
        if(l==0&&p==0&&v==0){
            break;
        }
        else{
            
            re=v%p; //나머지
            sh=v/p; //몫
            if(re>l&&re<p){
                re=l;
            }
            cout<<"Case "<<i<<": "<<(sh*l)+re<<'\n';
            
        }
    }
    
}
