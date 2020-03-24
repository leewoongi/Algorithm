#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
string map[1000000];
bool solution(vector<string> phone_book)
{
	bool answer = true;
	int phone_size = phone_book.size();
	sort(phone_book.begin(), phone_book.end());
	for (int i = 0; i < phone_size-1; i++)
	{
		int check_size=0;
		string s = phone_book[i];
		int s_size = s.size();
		
		string s_check = phone_book[i + 1];
		int s_check_size = s_check.size();
		for (int j = 0; j < s_check_size; j = j + s_size)
		{
			map[check_size] = s_check.substr(j, s_size);
			check_size++;
		}
		for (int j = 0; j < check_size; j++)
		{
			if (map[j] == s)
			{
				return false;
			}
			else
			{
				continue;
			}
		}
	}
	return answer;
}

int main()
{
	vector<string> phone_book = {"12","123","1235","567","88"};
	if (solution(phone_book))
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	return 0;
}