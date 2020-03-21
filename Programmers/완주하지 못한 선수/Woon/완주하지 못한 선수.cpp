#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<string,int> m;
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    int p_size = participant.size();
    for (int i = 0; i < p_size; i++) {
        if (m.find(participant[i]) == m.end()) {
            m.insert({ participant[i],1});
        }
        else {
            m[participant[i]]++;
        }
    }

    int c_size = completion.size();
    for (int i = 0; i < c_size; i++) {
        if (m.find(completion[i]) != m.end()) {
            m[completion[i]]--;
        }
    }

    for (int i = 0; i < p_size; i++) {
        if (m[participant[i]] != 0) {
            answer = participant[i];
            break;
        }
    }

    return answer;
}

int main() {

    vector<string> participant = {
        //"leo", "kiki", "eden"
        "mislav", "stanko", "mislav", "ana"
    };

    vector<string> completion = {
        //"eden", "kiki"
        "stanko", "ana", "mislav"

    };

    solution(participant, completion);

    return 0;
}