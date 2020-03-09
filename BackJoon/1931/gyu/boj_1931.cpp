#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct node 
{
	int begin;
	int end;
}Node;

vector<Node> v;

bool compare(Node n1, Node n2)
{
	if (n1.end == n2.end)
	{
		return n1.begin < n2.begin;
	}
	else
	{
		return n1.end < n2.end;
	}
}


int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int start, end;
		cin >> start >> end;
		v.push_back({ start,end });
	}
	sort(v.begin(), v.end(), compare);
	int result = 0;
	int check = 0;
	int v_size = v.size();
	for (int i = 0; i < v_size; i++)
	{
		if (check <= v[i].begin)
		{
			check = v[i].end;
			result++;
		}
	}
	cout << result << endl;

	return 0;
}