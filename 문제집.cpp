#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

priority_queue<int,vector<int>,greater<int>>pq; //min heap
vector<vector<int>>v;
int indegree[32001];
int n, m;
int result[32001];
void topologySort() {
	//indegree 가 0인 노드 큐에 삽입
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) pq.push(i);
	}

	for (int i = 1; i <= n; i++) {
		// 반복문이 돌기전에 큐가 비면 사이클이므로 위상정렬 불가능
		if (pq.empty()) {
			return;
		}
		int x = pq.top();
		pq.pop();
		result[i] = x;
		//선택된 정점과 여기에 부속된 간선을 지운다.
		for (auto i: v[x]) {
			//지운 간선의 indegree가 0이라면 q에 삽입
			if (--indegree[i] == 0)
				pq.push(i);
		}
	}

}

int main() {
	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int f;
		int s;
		cin >> f >>s;
		v[f].push_back(s);
		indegree[s]++;
	
	}/*
	vector<vector<int>>::iterator iter;
	vector<int>::iterator it;
	for (iter = v.begin(); iter != v.end(); iter++) {
		for (it = iter->begin(); it != iter->end(); it++) {
			cout << *it << endl;
		}
	}*/
	topologySort();
	for (int i = 1; i <= n; i++)
		cout << result[i] << " ";
	cout << endl;

}
