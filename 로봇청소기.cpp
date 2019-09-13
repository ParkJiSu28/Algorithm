#include<iostream>
using namespace std;

int N, M;
int map[51][51];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,-1,0 };

int main() {
	cin >> N >> M;
	int x, y ,dir;
	cin >> x >>y>>dir;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin>>map[i][j];
		}
	}

	while (true) {
		//map[x][y]=0 청소 X
		//map[x][y]=1 벽
		//map[x][y]=2 청소 O
		if (map[x][y] == 0) {
			map[x][y] = 2;//1.현재위치를 청소한다.
		}
		if (map[x - 1][y] != 0 && map[x + 1][y] != 0 && map[x][y - 1] != 0 && map[x][y + 1] != 0) {
			//네방향 모두 청소가 이미 되어있거나 벽이면
			if (map[x - dx[dir]][y - dy[dir]] == 1) {
				//한 칸 후잔했는데도 벽이면 종료한다.
				break;
			}
			else {
				x -= dx[dir];
				y -= dy[dir];
			}
		}
		else {
			dir = (dir + 3) % 4;// 2-1,2-2조건 모두  지정한 방향으로 회전해야한다
			//회전하고 다음 방향을 구한다.
			if (map[x + dx[dir]][y + dy[dir]] == 0) {
				x += dx[dir];
				y += dy[dir]; //한칸을 전진하고 다시 1번부터 진행한다.
			}
		}
	}
	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 2)answer+=1;
		}
	}
	cout << answer << endl;
	return 0;
}