#include<iostream>
using namespace std;
#include<algorithm>
/*
int d[1001];
int a[1001];
int b[1001];
int main() {
	int n;
	cin >> n;
	int k = n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		
	}
	for (int i = 1; i <= n; i++) {
		b[i] = a[k];
		k--;
		
	}
	for (int i = 1; i <= n; i++) {
		d[i] = 1;
	for (int j = 1; j < i; j++) {
		if (b[j]<b[i] && d[i]<d[j] + 1) {
			d[i] = d[j] + 1;
			}
		}
	}
	int anw = 0;
	for (int i = 1; i <= n; i++) {
	if (anw < d[i]) {
		anw = d[i];
		}
	}
	cout << anw;
}*/