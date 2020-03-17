#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    
    int length = s.length();
    int answer = length;

    for (int i = 1; i <= length / 2; i++) {
        string tmp = "";
       
        int count = 1;
        string s1 = s.substr(0, i);

        for (int j = i; j <= length; j = j + i) {
            string s2 = s.substr(j, i);
            if (s1 == s2) {
                count++;
            }
            else {

                if (count == 1) {
                    tmp = tmp + s1;
                }
                else {
                    tmp = tmp + to_string(count) + s1;
                }
                count = 1;
                s1 = s2;
            }          
        }

        if (length % i != 0) {
            tmp = tmp + s.substr((length / i) * i);
        }

        int size = tmp.length();
       
        if (answer > size) {
            answer = size;
        }
        
    }

    return answer;
}

int main() {



    string s = "a";
    solution(s);

    return 0;
}