#include<iostream>
#include<vector>
using namespace std;

bool check[8];
int ans[8];

void dfs(int start ,int destination,int n) {
	ans[destination] = start;

	if (destination == n) {
		for (int i = 1; i <= n; i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (check[i])continue;
		check[i] = true;
		dfs(i, destination + 1, n);
		check[i] = false;
	}
}


int main() {
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		check[i] = true;
		dfs(i,1,n);
		check[i] = false;
	}
}