#include<iostream>
using namespace std;
#include<algorithm>

long long d[1000000];
long long a[1000000];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		d[i] = a[i];
		if (i == 0) {
			continue;
		}
		if (d[i] < d[i - 1] + a[i]) {
			d[i] = d[i - 1] + a[i];
		}
	}
	long long anw = d[0];
	for (int i = 1; i < n; i++) {
		if (anw < d[i]) {
			anw = d[i];
		}
	}
	cout << anw;
}