#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int group[101][101];
bool visit[101][101];
int N;

void dfs(int x, int y, int cnt) {
	group[x][y] = cnt;
	visit[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx&&nx < N &&ny >= 0 && ny < N) {
			if (group[nx][ny]&& !visit[nx][ny]) {
				dfs(nx, ny, cnt);
			}
		}
	}
}

int bfs(int cnt) {
	queue<pair<int, int>>q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (group[j][i] == cnt) {
				visit[j][i] = true;
				q.push(make_pair(j, i));
			}
		}
	}
	int result = 0;
	while (!q.empty()) {
		int Q = q.size();
		for (int i = 0; i < Q; i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && nx < N&&ny < N&&ny >= 0) {
					if (group[nx][ny] && group[nx][ny] != cnt) {
						return result;
					}
					else if (!group[nx][ny] && !visit[nx][ny]) {
						visit[nx][ny] = true;
						q.push(make_pair(nx, ny));
					}
					
				}
			}
		}
		result++;
	}

}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> group[j][i];
		}
	}
	int cnt = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (group[j][i] && !visit[j][i]) 
				dfs(j, i, cnt++);
			}
		
	}
	int result = 987654321;
	for (int i = 1;i < cnt; i++) {
		memset(visit, false, sizeof(visit));
		result = min(result, bfs(i));
	}
	cout << result << endl;
	return 0;
}