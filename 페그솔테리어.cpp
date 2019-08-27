#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

char board[5][9];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int T;
int answer;
int pinNum;

void backtrack(int cnt, char board[][9]) {
	char cBoard[5][9];
	bool flag = false;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j] == 'o') {
				for (int pos = 0; pos < 4; pos++) {
					int nx = j + dx[pos];
					int ny = i + dy[pos];
					int nxx = nx + dx[pos];
					int nyy = ny + dy[pos];
					if (nxx >= 0 && nxx < 9 && nyy >= 0 && nyy < 5) {
						if (board[nyy][nxx] == '.'&&board[ny][nx]=='o') {
							for (int i = 0; i < 5; i++) {
								for (int j = 0; j < 9; j++) {
									cBoard[i][j] = board[i][j];
								}
							}
							cBoard[nyy][nxx] = 'o';
							cBoard[ny][nx] = '.';
							cBoard[i][j] = '.';
							flag = true;
							backtrack(cnt + 1, cBoard);
						}
					}
				}
			}
		}
	}
	if (flag == false) {
		int num=0;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j]=='o')num++;
			}
		}
		if (pinNum > num) {
			pinNum = num;
			answer = cnt;
		}
		else if (pinNum == num && answer > cnt) {
			answer = cnt;
		}
		return;
	}
}
int main() {
	cin >> T;
	while (T--) {
		memset(board, '.', sizeof(board));
		int totalPin = 0;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 9; j++) {
				cin >> board[i][j];
			}
		}
		pinNum = 999999999;
		backtrack(0, board);
		cout << pinNum << " " <<answer <<endl;
	}
}