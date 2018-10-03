#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
long long mod = 1000000000;
int D[101][10];
int main() {
	
	int n;
	cin >> n;
	for (int i = 1; i <= 9; i++) {
		D[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			D[i][j] = 0;
			if (j - 1 >= 0) {
				D[i][j] += D[i-1][j-1];
			}
			if (j + 1 <= 9) {
				D[i][j] += D[i-1][j+1];
			}
			D[i][j] %= mod;
		}
	}
	long long answer = 0;
	for (int i = 0; i <= 9; i++) {
		answer += D[n][i];

	}
	answer %= mod;
	cout << answer;
	
}