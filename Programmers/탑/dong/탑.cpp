#include<iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    vector<int> result;
    int h_size=(int)heights.size();
    
    for(int i=h_size-1;i>=0;i--){
        if(i==0){
            result.push_back(0);
        }
        else{
            for(int j=i-1;j>=0;j--){
                if(heights[i]<heights[j]){
                    result.push_back(j+1);
                    break;
                }
                else{
                    if(j==0){
                        result.push_back(0);
                    }else{
                        continue;
                    }
                    
                }
            }
        }
        
    }
    int re_size=(int)result.size();
    for(int i=re_size-1;i>=0;i--){
        answer.push_back(result[i]);
        cout<<result[i]<<" ";
    }
    
    return answer;
}
int main(){
    //vector<int> v={6,9,5,7,4};
    //vector<int> v={3,9,9,3,5,7,2};
    vector<int> v={1,5,3,6,7,6,5};
    solution(v);
}
