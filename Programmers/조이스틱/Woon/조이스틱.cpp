#include <iostream>
#include <string>
#include <vector>

using namespace std;

int left_count(string name, int index) {

	int size = name.size();
	int count = 0;
	while (true) {


		if (count == size - 1) {
			break;
		}

		index--;
		if (index < 0) {
			index = size - 1;
		}

		if (name[index] == 'A') {
			count++;
		}
		else {
			count++;
			break;
		}
	}

	return count;
}

int right_count(string name, int index) {

	int size = name.size();
	int count = 0;
	while (true) {

		if (count == size - 1) {
			break;
		}

		index++;
		if (index > size-1) {
			index = 0;
		}

		if (name[index] == 'A') {
			count++;
		}
		else {
			count++;
			break;
		}
	}

	return count;
}

bool a_check(string name) {
	int size = name.size();
	bool check = true;
	for (int i = 0; i < size; i++) {
		if (name[i] != 'A') {
			check = false;
			break;
		}
	}
	return check;
}


int solution(string name) {
	int answer = 0;

	int size = name.size();
	int count = 0;
	for (int i = 0; i < size; i++) {
		int x = name[i] - 65;

		if (x < 13) {
			count = count + x;
		}
		else {
			count = count + (26 - x);
		}
	}

	int left = 0;
	int right = 0;
	int index = 0;
	int move = 0;

	while (true) {
		
	
		if (index < 0) {
			index = size- 1;
		}
		if (index > size - 1) {
			index = 0;
		}

		if (name[index] == 'A') {
			left = left_count(name, index);
			right = right_count(name, index);
		}
		else {
			name.replace(index, 1, "A");
			left = left_count(name, index);
			right= right_count(name, index);
		}

		if (left < right) {
			index--;
		}
		else {
			index++;
		}

		move++;
		if (a_check(name) == true) {
			break;
		}
	}

	answer = move + count - 1;


	return answer;
}
int main() {


	string name = "JAN";
	cout << solution(name);

	return 0;	
}
