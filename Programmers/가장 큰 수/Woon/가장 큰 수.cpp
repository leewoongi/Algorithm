#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> v;
bool cmp(const string& n1, const string& n2) {
	
	return n2 + n1 < n1 + n2;
}

string solution(vector<int> numbers) {
	string answer = "";
	int size = numbers.size();

	for (int i = 0; i < size; i++) {
		v.push_back(to_string(numbers[i]));
	}
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < size; i++) {
		if (i == 0) {
			if (v[i] == "0") {
				answer = answer + '0';
				break;
			}
		}
		answer = answer + v[i];
	}


	return answer;
}

int main() {


	vector<int> numbers = {
	
		//2,6
		//6,10,2
		//3,30,34,5,9
		//13,131
		//1000, 121, 800,9
		0,0,0,0,0
	};
	


	solution(numbers);
	return 0;
}