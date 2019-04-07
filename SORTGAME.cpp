#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<map>
#include<queue>
using namespace std;
//key : ��� n�� ���Ͽ� ���ĵ� �迭���� �ٸ� ��� ���±��� �����ϴµ� �ʿ��� ������ ������ ���� BFS�� ���
//�� ���� �Է� ���� �迭���� ���ڵ��� ����� ũ�⸦ �����ϸ鼭 [0~n-1]������ ���� ������ �ٲ۴�.
map<vector<int>, int>toSort;
//map<vector<int>, int>::iterator iter;
//[0~n-1]�� ��� ������ ���� toSort�� ����� �����Ѵ�.
void precalc(int n) {
	vector<int>perm(n);//0�� �⺻������ ���� n���� ���ͻ���.
	for (int i = 0; i < n; ++i) perm[i] = i; //perm�� �⺻�� ����.
	queue<vector<int> >q; // perm�� �������� �� bfs�� �� queue����
	q.push(perm);
	toSort[perm] = 0; //ó�� ���¿��� value�� ����
	while (!q.empty()) {
		vector<int>here = q.front();//perm���� �������� �� ������ �迭 ����.
		q.pop();
		int cost = toSort[here];//������ ������ Ƚ���� �����ϴ� ����,toSort�� value���� ���
		for (int i = 0; i < n; ++i) {
			for (int j = i + 2; j <= n; ++j) {
				reverse(here.begin() + i, here.begin() + j);//������ ����
				if (toSort.count(here) == 0) {//here �������� ���Ұ����� 0�̸� ������ ������ ���� ���ߴٴ� ���̹Ƿ�
					toSort[here] = cost + 1; //�ռ� �����⿬��Ƚ���� cost+1�� value������ ����
					q.push(here); // ������ ���� queue �� ����
				}
				reverse(here.begin() + i, here.begin() + j);//������ ������ ������ �ٽ� ������ ������ ����
			}
		}
	}

}

int solve(const vector<int>& perm) {
	//perm�� [0~n-1]�� ������ ��ȯ
	int n = perm.size();
	vector<int>fixed(n); //n�����Ұ� �⺻�� 0�������� ���ͻ���
	for (int i = 0; i < n; ++i) {
		int smaller = 0;
		for (int j = 0; j < n; ++j) 
			if (perm[j] < perm[j]) //perm������ ��Ҹ� ���� ���� Ƚ���� ���Ѵ�.
				++smaller;// �迭�� �����ϴµ� �ʿ��� ����Ƚ���� ���ĵ� �迭�� �����迭�� ����� Ƚ���� �����ϴ�.
		fixed[i] = smaller;
		
	}
	return toSort[fixed];
}

int main() {
	int TestCase;
	cin >> TestCase;
	precalc(8);
	while (TestCase--)
	{
		int length;
		cin >> length;
		vector<int>perm(length);
		for (int i = 0; i < length; i++) {
			cin >> perm[i];
		}
		cout << solve(perm)<<endl;	
	}
}