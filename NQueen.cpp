#include<iostream>
#include<math.h>
using namespace std;

int Queen[16];
int N;
int cnt;

void backtrack(int x) {
	//Queen을 놓을 수 있는지 판별
	for (int i = 0; i < x; i++) {
		if (Queen[i] == Queen[x] || abs(Queen[i] - Queen[x]) == abs(i - x))return;
	}
	//Queen을 다 놓은 경우
	if (x == N - 1) {
		//퀸을 놓을 수 있는 경우의 수 
		for (int i = 0; i < N; i++)cout <<"Queen을 놓은 좌표"<< i<<","<<Queen[i]<<endl;
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