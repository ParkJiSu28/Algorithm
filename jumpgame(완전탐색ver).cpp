/*#include<iostream>
#include<string.h>
using namespace std;

int n,TC;
int board[100][100];

bool jump(int y, int x) {
	//기저사례 :게임판 밖으로 벗어난 경우
	if (y >= n || x >= n)return false;
	//기저사례 좌표가 도착점인 경우 
	if (y == n - 1 && x == n - 1)return true;
	int jumpsize = board[y][x];
	return jump(y + jumpsize, x) || jump(y, x + jumpsize);
}

int main() {
	cin >> TC;
	while (TC--) {
		n = 0;
		cin >> n;
		memset(board, 0, sizeof(board));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
			}
		}
		if (!jump(0, 0))cout << "NO";
		else cout << "YES";
		
	}
}*/