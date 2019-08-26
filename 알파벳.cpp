#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
char board[20][20];
char MemLoad[30];
int R, C;
int nx[4] = { 1,-1,0,0 };
int ny[4] = { 0,0,1,-1 };
int step=0;


void backtrack(int x,int y,int count) {
	step = max(step, count);
	for (int i = 0; i <= step; i++) {
		cout << MemLoad[i] << endl;
	}
	for (int pos = 0; pos < 4; pos++) {
		int nextx = x + nx[pos];
		int nexty = y + ny[pos];
		if (nextx >= 0 && nexty >= 0 && nextx < R && nexty < C) {
			bool check = true;
			for (int i = 0; i < count; i++) {
				if (MemLoad[i] == board[nextx][nexty]) {
					check = false;
					break;
				}
			}
			if (check) {
				MemLoad[count] = board[nextx][nexty];
				backtrack(nextx, nexty, count+1);
				MemLoad[count] = NULL;
			}
		}
	}
	//cout << count << step;
}


int main() {
	int i,j;
	cin >> R >> C;
	for (i = 0; i < R; i++) {
		for (j = 0; j < C; j++) {
			cin >> board[i][j];
		}
	}
	MemLoad[0] = board[0][0];
	backtrack(0, 0,1);
	cout << step;
}