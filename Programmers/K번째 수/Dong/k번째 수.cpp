#include<iostream>
#include <string>
#include <vector>
#include<queue>


using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    //int ar_size=(int)array.size();
    int cm_size=(int)commands.size();
    
    for(int z=0;z<cm_size;z++){
        priority_queue< int, vector<int>, greater<int> > pq;
        int num=0;
        int i=commands[z][0];
        int j=commands[z][1];
        int k=commands[z][2];
        for(int t=i-1;t<j;t++){
            pq.push(array[t]);
            
        }
        for(int t=0;t<k-1;t++){
            pq.pop();
        }
        num=pq.top();
        answer.push_back(num);
        
    }
    
    for(int i=0;i<(int)answer.size();i++){
        cout<<answer[i]<<" ";
    }
    return answer;
}
int main(){
    vector<int> v={1,5,2,6,3,7,4};
    
    vector<vector<int>> v2={
        {2,5,3},
        {4,4,1},
        {1,7,3}
    };
    
    solution(v, v2);
}
