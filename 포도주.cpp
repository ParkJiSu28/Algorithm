#include<iostream>
using namespace std;
#include<algorithm>

long long d[10001][3];
long long a[10001];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	long long aws = 0;
	d[1][0] = d[1][1] = d[1][2] = 0;
	for (int i = 2; i <= n; i++) {
		d[i][0] = max(d[i - 1][0], max(d[i - 1][1], d[i - 1][2]));
		d[i][1] = d[i - 1][0] + a[i];
		d[i][2] = d[i - 1][1] + a[i];
		aws = max(aws, max(d[i][0], max(d[i][1], d[i][2])));
	}
	cout << aws;

}
