#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cmath>
#include<stack>
#include<utility>
#include<string.h>

using namespace std;

struct node {
	int x;
	int y;
};

bool cmp(node n1, node n2) {
	return n1.x < n2.x;
}

int main(){
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		vector<node> f_con;
		int fri[510];
		vector<int> v;
		int N, M;
		cin >> N >> M;
		for (int i = 0; i <= N; i++)
		{
			fri[i] = i;
		}

		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;

			f_con.push_back({ a,b });
		}

		sort(f_con.begin(), f_con.end(), cmp);
		for (int i = 0; i < f_con.size(); i++){
			if (f_con[i].x == 1){
				fri[f_con[i].y] = 1;
				v.push_back(f_con[i].y);
			}
			else if(f_con[i].y == 1){
				fri[f_con[i].x] = 1;
				v.push_back(f_con[i].x);
			}

			for (int j = 0; j < v.size(); j++){
				if (v[j] == f_con[i].x){
					fri[f_con[i].y] = 1;
				}
				else if (v[j] == f_con[i].y) {
					fri[f_con[i].x] = 1;
				}
			}
		}

		int res = 0;

		for (int i = 2; i <= N; i++){
			if (fri[i] == 1) {
				res++;
			}
		}
		cout << "#" << t + 1 << " " << res << '\n';
	}

}