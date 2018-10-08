#include<iostream>
#include<algorithm>
using namespace std;

int p[1001];
bool check[1001];
void dfs(int start) {
	if (check[start]) {
		return;
	}
	check[start] = true;
	dfs(p[start]);
}
int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		for (int j = 1; j <= m; j++) {
			cin >> p[j];
			check[j] = false;
		}
		int ans=0;
		for (int i = 1; i <= m; i++) {
			if (check[i] == false) {
				dfs(i);
				ans += 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
	
}