#include<iostream>
#include<algorithm>
using namespace std;
#include<vector>

vector<int>a[2000001];
int check[2000001];
void dfs(int start,int color) {
	check[start] = color;

	for (int i = 0; i < a[start].size(); i++) {
		int next = a[start][i];

		if (check[next] == 0) {
			dfs(next,3-color);
		}
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int k, m;
		cin >> k >> m;
		for (int i = 1; i <= k; i++) {
			a[i].clear();
			check[i] = 0;
		}

		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			a[u].push_back(v);
			a[v].push_back(u);
		}

		for (int i = 1; i <= k; i++) {
			if (check[i] == 0) {
				dfs(i, 1);
			}
		}
		bool answer = true;

		for (int i = 1; i <= k; i++) {

			for (int l = 0; l<a[i].size(); l++) {

				int j = a[i][l];

				if (check[i] == check[j]) {

					answer = false;
				}

			}

		}
		if (answer == false) {
			cout << "NO" << endl;
		}
		else
			cout << "YES" << endl;
	}
	
	return 0;
}