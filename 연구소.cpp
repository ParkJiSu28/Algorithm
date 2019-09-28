#include<string>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<tuple>
using namespace std;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n, m;
int map[9][9];
int copy_map[9][9];
int result = 0;

void bfs() {
	int Wall3Map[9][9];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			Wall3Map[i][j] = copy_map[i][j];

	queue<pair<int,int>>q;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			if (Wall3Map[y][x] == 2)q.push(make_pair(y, x));
		}
	}
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >=0 && ny >= 0 && nx < m && ny < n) {
				if (Wall3Map[ny][nx]==0) {
					Wall3Map[ny][nx] = 2;
					q.push(make_pair(ny, nx));
				}
			}
		}
	}
	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (Wall3Map[i][j] == 0)answer += 1;
		}
	}
	result = max(result, answer);
}


void make_wall(int cnt) {
	if (cnt == 3) {
		bfs();
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (copy_map[i][j] == 0) {
				copy_map[i][j] = 1;
				make_wall(cnt + 1);
				copy_map[i][j] = 0;
			}
		}
	}
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if(map[i][j]==0){
				for (int k = 0; k < n; k++) {
					for (int l = 0; l < m; l++) {
						copy_map[k][l] = map[k][l];
					}
				}
				copy_map[i][j] = 1;
				make_wall(1);
				copy_map[i][j] = 0;

			}
		}
	}
	cout << result << endl;
}