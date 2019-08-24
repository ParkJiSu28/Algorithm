#include<iostream>
#include<math.h>
using namespace std;

int Queen[16];
int N;
int cnt;

void backtrack(int x) {
	//Queen�� ���� �� �ִ��� �Ǻ�
	for (int i = 0; i < x; i++) {
		if (Queen[i] == Queen[x] || abs(Queen[i] - Queen[x]) == abs(i - x))return;
	}
	//Queen�� �� ���� ���
	if (x == N - 1) {
		//���� ���� �� �ִ� ����� �� 
		for (int i = 0; i < N; i++)cout <<"Queen�� ���� ��ǥ"<< i<<","<<Queen[i]<<endl;
		cnt++;
		return;
	}
	for (int i = 0; i < N; i++) {
		Queen[x + 1] = i;
		backtrack(x + 1);
	}
}

int main() {
	int i;
	cin >> N;
	for (i = 0; i < N; i++) {
		Queen[0] = i;
		backtrack(0);
	}
	cout << cnt;
}