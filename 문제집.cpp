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
	//indegree �� 0�� ��� ť�� ����
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) pq.push(i);
	}

	for (int i = 1; i <= n; i++) {
		// �ݺ����� �������� ť�� ��� ����Ŭ�̹Ƿ� �������� �Ұ���
		if (pq.empty()) {
			return;
		}
		int x = pq.top();
		pq.pop();
		result[i] = x;
		//���õ� ������ ���⿡ �μӵ� ������ �����.
		for (auto i: v[x]) {
			//���� ������ indegree�� 0�̶�� q�� ����
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
