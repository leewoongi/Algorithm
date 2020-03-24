#include<iostream>
#include <string>
#include <vector>
#include<queue>
#include<functional>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int cnt=0;
    priority_queue< int, vector<int>, greater<int> > pq;
    
    for(int i=0;i<(int)scoville.size();i++){
        pq.push(scoville[i]);
    }
    
    while(true){
        int scov=0;
        if(pq.top()<K){
            if((int)pq.size()==1){
                cnt=-1;
                break;
            }
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            scov=x+(y*2);
            
            pq.push(scov);
            cnt++;
        }
        else{
            break;
        }
    }
    answer=cnt;
    return answer;
}

int main(){
    vector<int> v={1,2,3,9,10,12};
    cout<<solution(v, 7);
}
