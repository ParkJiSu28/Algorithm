

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
		if (!taken[pairWith] && areFriend[first][pairWith]) {//pairWith번째 학생이 짝이 되었는지 first,pairWith이 친구로 설정되어있는지 확인
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
먼저 친구인지 확인하는 확인배열을 만들고 학생들이 짝이 있는 지 없는지 확인하는 배열을 
만들어 비교 후 짝을 맺어준다.이때 중복카운트를 막기위해 학생 번호가 빠른 숫자부터 계산을 한다.

*/