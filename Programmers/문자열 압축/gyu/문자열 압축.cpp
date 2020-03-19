#include<iostream>
#include<vector>
#include<string>
using namespace std;

typedef struct node
{
	int cnt;
	string a;
}Node;


string array_string[1010];
vector<Node> V;

int min(int a, int n)
{
	return a > n ? n : a;
}

void init_array_string(int s_size)
{
	for (int i = 0; i < s_size; i++)
	{
		array_string[i] = "";
	}
}

int solution(string s)
{
	int answer = 9999;
	int s_size = s.size();
	int c = 0;
	int n = 0;
	int size_check = 0;
	
	for (int i = 0; i < s_size; i++)
	{
		init_array_string(s_size);
		size_check = 0;
		c = 0;
		for (int j = 0; j < s_size; j++)
		{
			if (j + c >= s_size)
			{
				break;
			}
			if (i == 0)
			{
				array_string[j] = s.substr(j, i + 1);
				size_check++;
			}
			else
			{
				array_string[j] = s.substr(j + c, i + 1);
				c = c + n;
				size_check++;
			}
		}
		n++;
		int check = 1;
		int check_point = 0;
		int check_count_solo = 0;
		V.push_back({ 1,array_string[0] });
		for (int j = 0; j < size_check; j++)
		{
			if (V[check_point].a == array_string[j + 1] && V[check_point].cnt >= 2)
			{
				check++;
				V.pop_back();
				V.push_back({ check,array_string[j + 1] });
			}
			else if (V[check_point].a == array_string[j + 1] && V[check_point].cnt == 1)
			{
				check++;
				V.pop_back();
				V.push_back({ check,array_string[j + 1] });
			}
			else if (array_string[j] == array_string[j + 1])
			{
				check++;
				V.push_back({ check,array_string[j] });
				check_point++;
			}
			else if (V[check_point].a != array_string[j + 1])
			{
				check = 1;
				V.push_back({ check,array_string[j + 1] });
				check_point++;
			}
		}
		int v_size = V.size();
		int result = 0;
		for (int i = 0; i < v_size - 1; i++)
		{
			if (V[i].cnt == 1)
			{
				string s = V[i].a;
				result += s.size();
			}
			else if (V[i].cnt < 10 && V[i].cnt>1)
			{
				result++;
				string s = V[i].a;
				result += s.size();
			}
			else if (V[i].cnt < 100 && V[i].cnt>=10)
			{
				result = result + 2;
				string s = V[i].a;
				result += s.size();
			}
			else if(V[i].cnt<1000&&V[i].cnt>=100)
			{
				result = result + 3;
				string s = V[i].a;
				result += s.size();
			}
			else
			{
				result = result + 4;
				string s = V[i].a;
				result += s.size();
			}
		}
		answer = min(answer, result);
		V.clear();
	}
	return answer;
}

int main()
{
	string s = "aaaaaaaaaabbb";
	cout << solution(s) << endl;
	return 0;
}