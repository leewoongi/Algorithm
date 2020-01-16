#include <iostream>
#include <string>
#include <vector>
using namespace std;


vector<int> v[27];
bool check[27] = { true,false, };

string pre = "";
void preorder(int x) {

	int size = v[x].size();
	for (int i = 0; i < size; i++) {
		if (v[x][i] != -18) {
			char tmp = v[x][i] + 65 - 1;
			
			if (check[v[x][i]] == false) {
				pre = pre + tmp;

				check[v[x][i]] = true;
			}
			preorder(v[x][i]);
		}
	}
}

string in = "";
void inorder(int x) {

	int size = v[x].size();
	if (size == 0) {
		char tmp = x + 65 - 1;
		if (check[x] == false) {
			in = in + tmp;
			check[x] = true;
		}
	}
	else {
		for (int i = 0; i < size; i++) {
			if (v[x][i] != -18) {
				inorder(v[x][i]);

				char tmp = x + 65 - 1;
				if (check[x] == false) {
					in = in + tmp;
					check[x] = true;
				}

			}
			else {
				char tmp = x + 65 - 1;
				if (check[x] == false) {
					in = in + tmp;
					check[x] = true;
				}

			}
		}
	}
}

string post = "";
void postorder(int x) {

	int size = v[x].size();
	for (int i = 0; i < size; i++) {
		if (v[x][i] != -18) {
	
			postorder(v[x][i]);
			char tmp = v[x][i] + 65 - 1;

			if (check[v[x][i]] == false) {
				post = post + tmp;

				check[v[x][i]] = true;
			}
			
		}
	}

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;


	for (int i = 0; i < n; i++) {
		char a, b, c;
		cin >> a >> b >> c;

		if (i == 0) {
			v[0].push_back(a - 65 + 1);
		}

		v[a - 65 + 1].push_back(b - 65 + 1);
		v[a - 65 + 1].push_back(c - 65 + 1);
	}



	preorder(0);
	cout << pre << endl;
	for (int i = 1; i <= 26; i++) {
		check[i] = false;
	}

	inorder(0);
	cout << in << endl;
	for (int i = 1; i <= 26; i++) {
		check[i] = false;
	}

	postorder(0);
	cout << post << endl;
	for (int i = 1; i <= 26; i++) {
		check[i] = false;
	}

	return 0;
}

