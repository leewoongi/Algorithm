#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>


using namespace std;
string solution(vector<string> participant, vector<string> completion) {
    map<string,int> m;
    string answer = "";
    int c_size = (int)completion.size();
    int p_size = (int)participant.size();
    
    pair<map<string, int>::iterator, bool > pr;
    for(int i=0;i<p_size;i++){ //map생성
       pr=m.insert(pair<string,int>(participant[i],1));
       
       if(pr.second==true){
           continue;
           
       }else{
           m[pr.first->first]+=1;
       }
    }

    for(int i=0;i<c_size;i++){
        pr=m.insert(pair<string,int>(completion[i],0));
        
        if(pr.second==true){
            continue;
        }else{
            m[pr.first->first]-=1;
        }
    }
    map<string, int>::iterator iter;

    for(iter=m.begin();iter!=m.end();++iter){
        if(iter->second!=0){
            answer=iter->first;
        }
        

    }
    
    




    return answer;
}
int main(){
    /*vector<string> t = { "marina","josipa","nikola","vinko","filipa" };
    vector<string> c = { "josipa","filipa","marina","nikola" };
    /*vector<string> t = { "mislav","stanko","mislav","ana" };
    vector<string> c = { "stanko","ana","mislav" };*/
    vector<string> t = { "leo","kiki","eden"};
    vector<string> c = { "eden","kiki" };
    cout<<solution(t, c);
}
