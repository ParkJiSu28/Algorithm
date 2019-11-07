#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string.h>
using namespace std;
vector<vector<int>>t;
bool visit[32001];
stack<int>res;


void dfs(int here) {
	visit[here] = true;
	for (auto i : t[here]) { //객체 순회!!!!!!!!!! 연결된 간선만 간다.
		if (!visit[i]) {
			dfs(i);
		}
	}
	res.push(here);
}

int main() {
	int n, m;
	cin >> n >> m;
	t.resize(n + 1);
	memset(visit, false, sizeof(visit));
	for (int i = 0; i < m; i++) {
		int  s;
		int f;
		cin >> f >> s;
		t[f].push_back(s);
	}
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			dfs(i);
		}
	}
	while (!res.empty()) {
		cout << res.top() << " ";
		res.pop();
	}
}