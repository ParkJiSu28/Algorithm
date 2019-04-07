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
	
	int children[3] = { 0,0,0 };//�ڽ��� ���¸� ǥ���ϱ� ���� �迭
	for (int i = 0; i < adj[here].size(); ++i) {//here�� root�� �� ���д� Ʈ���� �����ŭ ��ȸ
		int there = adj[here][i];
		if (!visited[there])
			++children[dfs(there)];
	}
	//�ڼ� ��� �� ���õ��� ���� ��尡 ���� ��� ī�޶� ��ġ,��������� �ʾ����Ƿ� �����弱��
	if (children[UNWATCHED]) {
		++installed;
		return INSTALLED;
	}
	//�ڼ� ����� ī�޶� ��ġ�� ��尡 ���� ��� ��ġ�� �ʿ䰡 ����.�׿ܿ��� ������ ����X
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
