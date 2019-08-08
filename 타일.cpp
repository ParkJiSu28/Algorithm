#include<iostream>
using namespace std;
#include<string.h>
int answer[1000000];

int n;


int tail(int n) {
	if (answer[n] > -1)return answer[n];
	else {
		answer[n] = tail(n-1) + tail(n-2);
		answer[n] = answer[n] % 15746;
		return answer[n];
	}
}

int main() {
	cin >> n;
	memset(answer, -1, sizeof(answer));
	answer[0] = 1%15746;
	answer[1] = 1%15746;
	cout << tail(n);
}