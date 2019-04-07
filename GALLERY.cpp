#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<stdlib.h>
using namespace std;

vector<int>adj[1010];
vector<bool>visited;
const int UNWATCHED = 0;
const int WATCHED = 1;
const int INSTALLED = 2;
int installed;


int dfs(int here) {
	visited[here] = true;
	
	int children[3] = { 0,0,0 };//자식의 상태를 표시하기 위한 배열
	for (int i = 0; i < adj[here].size(); ++i) {//here을 root로 한 스패닝 트리에 사이즈만큼 순회
		int there = adj[here][i];
		if (!visited[there])
			++children[dfs(there)];
	}
	//자손 노드 중 감시되지 않은 노드가 있을 경우 카메라를 설치,지배당하지 않았으므로 현재노드선택
	if (children[UNWATCHED]) {
		++installed;
		return INSTALLED;
	}
	//자손 노드중 카메라가 설치된 노드가 있을 경우 설치할 필요가 없다.그외에는 현재노드 선택X
	if (children[WATCHED]) {
		return WATCHED;
	}
	return UNWATCHED;
}

int installCamera(int V) {
	installed = 0;
	visited = vector<bool>(V, false);
	for (int u = 0; u < V; u++)
		if (!visited[u] && dfs(u) == UNWATCHED)
			++installed;
	return installed;

}

int main() {
	int TestCase;
	cin >> TestCase;
	while (TestCase--) {
		int V, h;
		cin >> V >> h;
		for (int i = 0; i < h; i++) {
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		int answer = installCamera(V);
		cout << answer << endl;
		for (int i = 0; i < V; i++) {
			adj[i].clear();
		}
	}
}
