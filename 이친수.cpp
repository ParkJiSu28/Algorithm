#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
long long D[91][3];
int main() {
	int n;
	cin >> n;
	long long answer = 0;
	D[1][0] = 0;
	D[1][1] = 1;
	
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 2; j++) {
			if (j == 0) {
				D[i][0] = D[i - 1][0] + D[i - 1][1];
			}
			if (j == 1) {
				D[i][1] = D[i - 1][0];
			}	
		}
	}
	answer = D[n][0] + D[n][1];
	cout << answer;

}