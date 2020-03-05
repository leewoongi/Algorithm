#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<functional>
#include<cmath>

#define SIZE 1010
const int INF = 2000000000;

using namespace std;

typedef long long int ll;


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for(int i =1 ; ;i++) {
		int L, P, V; cin >> L >> P >> V;
		if (!L && !P && !V) break;
		int res = (V / P)*L + ((V%P < L ? V%P : L));
		cout << "Case " << i << ": " << res << "\n";
	}
}