#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

long long D[1001][10];
long long mod =10007;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i <= 9; i++) {
		D[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= j; k++) {
				D[i][j] += D[i - 1][k];
				D[i][j] %= mod;
			}

		}
	}
	long long answer = 0;
	for (int i = 0; i <= 9; i++) {
		answer += D[n][i];

	}
	long long num =answer %= mod;
	cout << num;

}