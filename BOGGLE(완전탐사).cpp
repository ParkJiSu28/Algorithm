#include<iostream>
#include<string.h>
#include<string>
#pragma warning(disable:4996)
using namespace std;
int TC;
int N;
char board[5][5];
const int dx[8] = { -1,-1,-1,1,1,1,0,0 };
const int dy[8] = { -1,0,1,-1,0,1,-1,1 };


bool hasWord(int y, int x, string &word) {
	if (y < 0 && x>0 && y > 4 && x > 4)return false;
	if (board[y][x] != word[0])return false;
	if (word.size() == 1)return true;
	for (int dir = 0; dir < 8; dir++) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (hasWord(ny, nx, word.substr(1))){
			return true;
		}
	}
	return false;
}

int main() {
	cin >> TC;
	while (TC--) {
		memset(board, 0, sizeof(board));
		for (int i = 0; i < 5; i++) {
			cin >> board[i];
		}
		N = 0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			string word;
			cin >> word;
			bool check = false;
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					if (hasWord(i, j, word)) {
						check = true;
						break;
					}
				}
				if (check)break;
			}
			if (check)cout << word << " YES\n";
			else cout << word << " NO\n";
		}
	}
}