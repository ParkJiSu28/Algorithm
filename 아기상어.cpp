#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

struct SHARK {
	int y,  x, time;
};

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int map[20][20];
bool visited[20][20];
int shark_size;
int shark_eat;
int n;
SHARK shark;

void bfs() {
	bool is_updated = true;
	while (is_updated) {
		is_updated = false;
		memset(visited, false, sizeof(visited));
		queue<SHARK>q;
		q.push(shark);
		visited[shark.y][shark.x] = true;

		SHARK candi;
		candi.y = 20; //���ʺ��� Ž���� ����
		candi.x = 0;//������ ���� ����;
		candi.time = -1;

		while (!q.empty()) {
			SHARK cur = q.front();
			q.pop();
			if (candi.time != -1 && candi.time < cur.time)
				break; // ���̻� ã�� �� ���� ����⸦ �ٸԾ��ų� ���� �� �ִ°� ����

			if (map[cur.y][cur.x] != 0 && map[cur.y][cur.x] < shark_size) {
				is_updated = true;
				if (cur.y < candi.y || (candi.y == cur.y && candi.x > cur.x))
					candi = cur;
			}
			for (int dir = 0; dir < 4; dir++) {
				SHARK next;
				next.x = cur.x + dx[dir];
				next.y = cur.y + dy[dir];
				next.time = cur.time + 1;
				if (next.x < 0 || next.x >= n || next.y >= n || next.y < 0) 
					continue;
				if (!visited[next.y][next.x] && shark_size >= map[next.y][next.x]) {
					visited[next.y][next.x] = true;
					q.push(next);
				}
			}
			
		}
		if (is_updated) {
			shark = candi;
			++shark_eat;
			if (shark_eat == shark_size) {
				++shark_size;
				shark_eat = 0;
			}
			map[shark.y][shark.x] = 0;
		}
	}
}

int main() {
	cin >> n;
	memset(visited, false, sizeof(visited));
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> map[y][x];
			if (map[y][x] == 9) {
				shark.x = x, shark.y = y, shark.time = 0;
				shark_size = 2, shark_eat = 0;
				map[y][x] = 0;
			}
		}
	}
	bfs();
	cout << shark.time << endl;
	return 0;
}