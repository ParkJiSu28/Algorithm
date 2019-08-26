#include<iostream>
#include<string.h>
using namespace std;
int R, C;
int ans = 0;
int dx[3] = { 1,1,1 };
int dy[3] = { -1,0,1 };
bool check[10000][500];
char board[10000][500];
bool flag = false;

void backtrack(int y , int x) {
	if (x == C - 1) {
		ans++;
		flag = true;
		return;
	}
		for (int pos = 0; pos < 3; pos++) {
			int nx = x + dx[pos];
			int ny = y + dy[pos];
			if (nx >= 0 && ny >= 0 && ny < R && nx < C && check[ny][nx] == false&&board[y][x] != 'x') {
				check[y][x] = true;
				backtrack(ny, nx);
				if (flag==true)return;
			}
		}
	}


int main() {
	cin >> R >> C;
	memset(check, false, sizeof(check));
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < R; i++) {
		flag = false;
		backtrack(i,0);
	}
	cout << ans;
}
