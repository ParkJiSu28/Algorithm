#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int a[10000];
int D[1000];


int main() {
	int n;
	cin >> n;
	a[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			D[i] = max(D[i], D[i - j] + a[j]);
		}
	}
	cout << D[n];
}
