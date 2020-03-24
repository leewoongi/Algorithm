#include<iostream>
#include<algorithm>
#include <string>
#include <vector>

using namespace std;
bool tmp(string a,string b){
    string str=a+b;
    string str2=b+a;
    int num1=atoi(str.c_str());
    int num2=atoi(str2.c_str());
    
    if(num1>num2){
        return true;
    }
    else{
        return false;
    }
}
string solution(vector<int> numbers) {
    string answer = "";
    int n_size=(int)numbers.size();
    int cnt=0;
    vector<string> v;
    
    for(int i=0;i<n_size;i++){
        v.push_back(to_string(numbers[i]));
        if(to_string(numbers[i])=="0"){
            cnt++;
        }
    }
    sort(v.begin(),v.end(),tmp);
    for(int i=0;i<n_size;i++){
        if(cnt==n_size){
            answer="0";
            break;
        }
        answer+=v[i];
    }
    
    return answer;
}
int main(){
    vector<int> a={3,30,34,5,9};
    //vector<int> a={6,10,2};
    
    solution(a);
}
