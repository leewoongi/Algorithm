#include<iostream>
#include<vector>

using namespace std;

int max(int x, int y)
{
	return x > y ? x : y;
}
int result[100000];
int sti[100000];
int solution(vector<int> sticker)
{
	int answer = 36;
	int vector_size = sticker.size();
	for (int i = 0; i < vector_size; i++)
	{
		sti[i] = sticker[i];
	}
	if (vector_size == 1)
	{
		answer = sti[0];
	}
	else if (vector_size == 2)
	{
		answer = max(sti[0], sti[1]);
	}
	else
	{
		result[0] = sti[0];
		result[1] = sti[0];
		for (int i = 2; i < vector_size; i++)
		{
			result[i] = max(result[i - 2] + sti[i], result[i - 1]);
		}
		answer = result[vector_size - 2];
		for (int i = 0; i < vector_size; i++)
		{
			result[i] = 0;
		}
		result[0] = 0;
		result[1] = sti[1];
		for (int i = 2; i < vector_size; i++)
		{
			result[i] = max(result[i - 2] + sti[i], result[i - 1]);
		}
		answer = max(answer, result[vector_size - 1]);
	}
	return answer;
}

int main()
{
	vector<int>v = { 14, 6, 5, 11, 3, 9, 2, 10 };
	cout << solution(v);
	return 0;
}