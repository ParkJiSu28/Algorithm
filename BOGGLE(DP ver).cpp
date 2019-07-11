#include<iostream>
#include<string.h>
#include<string>
#pragma warning(disable:4996)
using namespace std;
int TC;
int N;
char board[5][5];
int cache[5][5][10];
const int dx[8] = { -1,-1,-1,1,1,1,0,0 };
const int dy[8] = { -1,0,1,-1,0,1,-1,1 };
string word;

int canFindWord(int y, int x,int wordIndex) {
	if (y < 0 || x<0 || y > 4 ||x > 4)return 0;
	int &ret = cache[y][x][wordIndex];
	if (ret != -1)return ret;
	if (word.at(wordIndex) != board[y][x])return ret = 0;
	wordIndex++;
	if (wordIndex >= word.size())return ret = 1;
	return ret = (
		canFindWord(y - 1, x - 1, wordIndex) || canFindWord(y - 1, x, wordIndex) || canFindWord(y - 1, x + 1, wordIndex)
		|| canFindWord(y, x - 1, wordIndex) || canFindWord(y, x + 1, wordIndex)
		|| canFindWord(y + 1, x - 1, wordIndex) || canFindWord(y + 1, x, wordIndex) || canFindWord(y + 1, x + 1, wordIndex)
		);
	
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
			memset(cache, -1, sizeof(cache));
			word.clear();
			cin >> word;
			int check = 0;
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					if (canFindWord(i, j, 0)==1) {
						check = 1;
						break;
					}
				}
				if (check==1)break;
			}
			if (check)cout << word << " YES\n";
			else cout << word << " NO\n";
		}
	}
}