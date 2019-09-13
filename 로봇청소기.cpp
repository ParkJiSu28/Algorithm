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
		//map[x][y]=0 û�� X
		//map[x][y]=1 ��
		//map[x][y]=2 û�� O
		if (map[x][y] == 0) {
			map[x][y] = 2;//1.������ġ�� û���Ѵ�.
		}
		if (map[x - 1][y] != 0 && map[x + 1][y] != 0 && map[x][y - 1] != 0 && map[x][y + 1] != 0) {
			//�׹��� ��� û�Ұ� �̹� �Ǿ��ְų� ���̸�
			if (map[x - dx[dir]][y - dy[dir]] == 1) {
				//�� ĭ �����ߴµ��� ���̸� �����Ѵ�.
				break;
			}
			else {
				x -= dx[dir];
				y -= dy[dir];
			}
		}
		else {
			dir = (dir + 3) % 4;// 2-1,2-2���� ���  ������ �������� ȸ���ؾ��Ѵ�
			//ȸ���ϰ� ���� ������ ���Ѵ�.
			if (map[x + dx[dir]][y + dy[dir]] == 0) {
				x += dx[dir];
				y += dy[dir]; //��ĭ�� �����ϰ� �ٽ� 1������ �����Ѵ�.
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