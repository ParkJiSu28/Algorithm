#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int map[30][30];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n;
int ans[25 * 25];
int check[30][30];


void dfs(int x, int y,int cnt) {
	check[x][y] = cnt;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0<=nx && nx < n  && 0<=ny && ny < n) {
			if (map[nx][ny] == 1 && check[nx][ny]==0) {
				dfs(nx, ny,cnt);
			}
		}
	}
}




int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf_s("%1d", &map[i][j]);
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 && check[i][j]==0) {
				
				dfs(i, j,++cnt);
			}
		}
	}
	cout << cnt << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans[check[i][j]] += 1;
		}
	}

	sort(ans + 1, ans + cnt + 1);
	for (int i = 1; i <= cnt; i++) {
		cout << ans[i] << endl;
	}

	return 0;
}