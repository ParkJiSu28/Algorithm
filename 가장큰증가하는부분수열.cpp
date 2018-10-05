#include<iostream>
using namespace std;
#include<algorithm>

int d[1001];
int a[1001];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		d[i] = a[i];
		for (int j = 1; j < i; j++) {
			if (a[j]<a[i] && d[i]<d[j] + a[i]) {
				d[i] = d[j] + a[i];
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
}