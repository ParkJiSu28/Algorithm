#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int map[1000][1000];
bool check[1000][1000];
int w, h;
queue<pair<int, int>>q;
bool check_tomato() {
	for(int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (map[j][i] == 0)return false;
		}
	}
	return true;
}

void bfs() {
	int day = 0;
	while (!q.empty()) {
		int Qsize = q.size();
		for (int i = 0; i < Qsize; i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && nx < w &&ny >= 0 && ny < h) {
					if (map[nx][ny] == 0 && !check[nx][ny]) {
						map[nx][ny] = 1;
						check[nx][ny] = true;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
		day++;
	}
	if (!check_tomato())cout << -1 << endl;
	else cout << day - 1 << endl;
}

int main() {
	cin >> w >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			map[j][i] = -1;
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> map[j][i];
			if (map[j][i] == 1) {
				q.push(make_pair(j, i));
				check[j][i];
			}
		}
	}
	bfs();
}