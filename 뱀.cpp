#include<iostream>
#include<string.h>
using namespace std;

int d[100][100];
bool apple[100][100];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };


int main() {
	int n;
	cin >> n;
	int k;
	cin >> k;
	while (k--) {
		int x, y;
		cin >> x >>y;
		apple[x - 1][y - 1] = true;
	}
	memset(d, -1, sizeof(d));
	int x = 0;int y = 0;
	int dir = 0;
	int len = 1;
	d[x][y] = 0;
	int l;
	cin >> l;
	int now = 0;
	for (int k = 0; k <= l; k++) {
		int t = n*n*+1;
		char ch = 'L';
		cin >> t >> ch;
		while (now < t) {
			x = x + dx[dir];
			y = y + dy[dir];
			now += 1;
			//범위를 벗어나면 시간을 출력하고 종료한다.
			if (x < 0 || y < 0 || x > n - 1 || y > n - 1) {
				cout << now << endl;
				return 0;
			}//사과가 있으면 사과를 먹고 칸에 사과를 지운 다음 몸길이를 1늘린다.
			if (apple[x][y]) {
				apple[x][y] = false;
				len += 1;
			}// 방문한 적이 있고 자기자신의몸에 충돌하면 시간을 출력하고 종료한다.
			//now-d[x][y]== 방문하려고 하는 칸이 몇초에 방문한지 알수 있는게 d[x][y]이고 그걸 현재 시간에서 빼면 몸의 길이가 나온다
			//그 길이가 현재 몸의 길이보다 크다면 충돌한다 
			if (d[x][y] != -1 && now - d[x][y] <= len) {
				cout << now << endl;
				return 0;
			}
			d[x][y] = now;
		}
		if (ch == 'L') {
			dir = (dir + 3) % 4;
		}
		else {
			dir = (dir + 1) % 4;
		}
	}
	return 0;
}