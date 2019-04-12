#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int map[51][51];
int dx[] = { 1,-1,0,0,1,1,-1,-1 };
int dy[] = { 0, 0,1,-1,1,-1,1,-1 };
//int dist[51][51];
int w, h;
bool check[51][51];

void dfs(int x, int y) {
	if (check[x][y])return;
	
	check[x][y] = true;

	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < w && ny >= 0 && ny < h) {
			if (map[nx][ny] == 1 && !check[nx][ny]) {
				dfs(nx, ny);
			}
		}
	}
}

int main() {
	while (true) {
		w = 0; h = 0;
		cin >> w >> h;
		if (w == 0 && h == 0) {
			return 0;
		}
		int cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				map[j][i] = 0;
				check[j][i] = 0;
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[j][i];
			}
		}
	
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[j][i] == 1 && !check[j][i]) {
					dfs(j, i);
					cnt++;
				}
			}
		}
		cout << cnt << endl;

	}
	return 0;
}