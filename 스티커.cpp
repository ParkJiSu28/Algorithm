#include<iostream>
using namespace std;
#include<algorithm>

long long d[100001][4];
long long a[100001][3];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		for (int i = 1; i <= k; i++) {
			cin >> a[i][0];
		}
		for (int i = 1; i <= k; i++) {
			cin >> a[i][1];
		}
		d[0][0] = d[0][1] = d[0][2] = 0;
		for (int i = 1; i <= k; i++) {
			d[i][0] = max(d[i - 1][0], max(d[i - 1][1], d[i - 1][2]));
			d[i][1] = max(d[i - 1][0], d[i - 1][2]) + a[i][0];
			d[i][2] = max(d[i - 1][0], d[i - 1][1])+a[i][1];
		}
				
		long long answer = 0;
		for (int i = 1; i <= k; i++) {
			answer = max(max(answer, d[i][0]), max(d[i][1], d[i][2]));
		}
		cout << answer << endl;
		
	}

	
}