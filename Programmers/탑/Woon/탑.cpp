#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;


vector<int> st;
vector<int> solution(vector<int> heights) {
	vector<int> answer;

	int size = heights.size();

	for (int i = size-1; i >=0; i--) {

		for (int j = i - 1; j >= 0; j--) {
			if (heights[i] < heights[j]) {
				st.push_back(j+1);
				break;
			}
			else {
				if (j == 0) {
					st.push_back(0);
				}
			}
		}
	}

	int len = st.size();
	answer.push_back(0);
	for (int i = len-1; i >= 0; i--) {
		answer.push_back(st[i]);
	}



	return answer;
}

int main() {


	vector<int> heights = {
		//6,9,5,7,4
		1,5,3,6,7,6,5
	};
	solution(heights);
	return 0;
}