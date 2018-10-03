#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int D[1000];





int main() {
	int n;
	cin >> n;
	D[0] = 1;
	D[1] = 1;
	for (int i = 2; i <= n; i++) {
		D[i] = (D[i - 1] +2* D[i - 2])%10007;
	}
	cout << D[n];
}