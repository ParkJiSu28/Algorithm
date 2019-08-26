#include<iostream>
#include<string.h>
using namespace std;

bool Row[10][10];
bool Col[10][10];
bool Square[10][10];
int board[10][10];

void backtrack(int cnt) {
	int x = cnt / 9;
	int y = cnt % 9;

	if (cnt == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
		exit(0);
	}
	if (board[x][y] == 0) {
		for (int i = 1; i <= 9; i++) {
			if (Row[x][i] == false && Col[y][i]==false && Square[(x / 3) * 3 + (y / 3)][i]==false) {
				Row[x][i] = true;
				Col[y][i] = true;
				Square[(x / 3) * 3 + (y / 3)][i] = true;
				board[x][y] = i;
				backtrack(cnt + 1);
				Row[x][i] = false;
				Col[y][i] = false;
				Square[(x / 3) * 3 + (y / 3)][i] = false;
				board[x][y] = 0;
			}
		}
	}
	else { backtrack(cnt + 1); }
}


int main() {
	memset(Row, false, sizeof(Row));
	memset(Col, false, sizeof(Col));
	memset(Square, false, sizeof(Square));
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
			if (board[i][j] != 0) {
				Row[i][board[i][j]] = true;
				Col[j][board[i][j]] = true;
				Square[(i / 3) * 3 + (j / 3)][board[i][j]] = true;
			}
		}
	}
	backtrack(0);

	return 0;
}