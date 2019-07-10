#include<iostream>
#include<string.h>
using namespace std;

int n, TC;
int board[100][100];
int cache[100][100];

int jump2(int y, int x) {
	//기저사례 :게임판 밖으로 벗어난 경우
	if (y >= n || x >= n)return 0;
	//기저사례 좌표가 도착점인 경우 
	if (y == n - 1 && x == n - 1)return 1;
	int &ret = cache[y][x];
	if (ret != -1)return ret;
	int jumpsize = board[y][x];
	return ret = jump2(y + jumpsize, x) || jump2(y, x + jumpsize);
}

int main() {
	cin >> TC;
	while (TC--) {
		n = 0;
		cin >> n;
		memset(board, 0, sizeof(board));
		memset(cache, -1, sizeof(cache));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
			}
		}
		if (jump2(0, 0) ==1)cout << "YES";
		else cout << "NO";

	}
}