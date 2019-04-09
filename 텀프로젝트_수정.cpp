#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>student; //학생이 가리키는 다른 학생의 번호
vector<int>first_student; //첫번째로 dfs를 시작한 학생 번호
vector<int>visited; //방문여부

int dfs(int start, int current, int cnt) {
	if (visited[current]) {
		//첫번째로 dfs를 시작한 학생이 맞느지 ,사이클이 맞는지.
		if (first_student[current] != start)return 0;
		return cnt - visited[current]; //사이클에 해당되는 학생 수.
	}
	first_student[current] = start;
	visited[current] = cnt;
	return dfs(start, student[current], cnt + 1);
}

int main() {
	int T;
	cin >> T;
	int n;
	for (int i = 0; i < T; i++) {
		cin >> n;
		student = vector<int>(n + 1, 0);
		first_student = vector<int>(n + 1, 0);
		visited = vector<int>(n + 1, 0);

		for (int i = 1; i <= n; i++) {
			cin >> student[i];
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				ans += dfs(i, i, 1);
			}
		}
		cout << n - ans << endl;
	}
	return 0;
}