#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

int n, l, r;
int map[50][50];
struct PO {
	int y, x;
};


void create_area(int y, int x,int index, int status[][50],int &sum,int &count) {
	bool visited[50][50] = { false, };

	PO init;
	init.x = x; init.y = y;
	queue<PO>head;
	visited[y][x] = true;
	head.push(init);

	const int dx[] = { 1,-1,0,0 };
	const int dy[] = { 0,0,1,-1 };
	while (!head.empty()) {
		PO cur= head.front(); head.pop();
		status[cur.y][cur.x] = index;
		++count;
		sum += map[cur.y][cur.x];
		for (int dir = 0; dir < 4; dir++) {
			PO next;
			next.y = cur.y + dy[dir];
			next.x = cur.x + dx[dir];
			if (next.y >= 0 && next.y < n&&next.x >= 0 && next.x < n) {
				int delta = abs(map[cur.y][cur.x] - map[next.y][next.x]);
				if (delta >= l && delta <= r&&!visited[next.y][next.x]) {
					visited[next.y][next.x] = true;
					head.push(next);
				}
			}
		}
	}
}


int main() {
	cin >> n >> l >> r;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> map[y][x];
		}
	}
	int answer = 0;
	bool is_update = true;
	while (is_update) {
		is_update = false;
		int status[50][50] = {0,};
		int sum[2501] = {0,};
		int count[2501] = {0,};
		int index_area = 0;
		//국경선 제거 하고 연합만들기.
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				if (status[y][x] == 0) {
					++index_area;
					create_area(y,x,index_area,status,count[index_area],sum[index_area]);
				}
			}
		}
		//인구이동및 인구수 평균내서 도시마다 업데이트하기.
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				int index = status[y][x];
				int avg = sum[index] / count[index];
				if (map[y][x] != avg) {
					map[y][x] = avg;
					is_update = true;
				}
			}
		}
		if (is_update)++answer;
	}
	cout << answer << endl;
	return 0;
}