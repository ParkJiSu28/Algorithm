#include<iostream>
using namespace std;
#include<algorithm>
int d[301][2];
int a[301];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	d[0][1] = d[0][2]=0;
	d[1][1]=a[1];
	for (int i = 2; i <= n; i++) {
		d[i][1] = max(d[i - 2][1], d[i - 2][2]) + a[i];
		d[i][2] =d[i - 1][1] + a[i];
	}

	int ans = max(d[n][1],d[n][2]);
	cout << ans;
}