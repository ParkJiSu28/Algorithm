

#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;


bool taken[10];
bool areFriend[10][10];

int n;
int m;
int countPair(bool taken[]) {
	int first = -1;
	for (int i = 0; i < n; ++i) {
		if (!taken[i]) {
			first = i;
			break;
		}
	}
	if (first == -1) {
		return 1;
	}
	int answer = 0;
	for (int pairWith = first + 1; pairWith < n; ++pairWith) {
		if (!taken[pairWith] && areFriend[first][pairWith]) {//pairWith��° �л��� ¦�� �Ǿ����� first,pairWith�� ģ���� �����Ǿ��ִ��� Ȯ��
			taken[first] = taken[pairWith] = true;
			answer += countPair(taken);
			taken[first] = taken[pairWith] = false;
		}
	}
	return answer;
}

int main() {
	int test = 0;
	cin >> test;
	for(int i=0;i<test;i++){
		cin >> n;
		cin >> m;
		memset(areFriend, false, sizeof(areFriend));
		memset(taken, false, sizeof(taken));
		for (int i = 0; i < m; i++) {
			int k, l;
			cin >> k >> l;
			areFriend[k][l] = areFriend[l][k] = true;
		}

		int ret=countPair(taken);
		cout << ret<<endl;
	}
	return 0;
}
/*
���� ģ������ Ȯ���ϴ� Ȯ�ι迭�� ����� �л����� ¦�� �ִ� �� ������ Ȯ���ϴ� �迭�� 
����� �� �� ¦�� �ξ��ش�.�̶� �ߺ�ī��Ʈ�� �������� �л� ��ȣ�� ���� ���ں��� ����� �Ѵ�.

*/