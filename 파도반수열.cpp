#include<iostream>
#include<string.h>
using namespace std;

long long padoban[101];
int T;


long long pado(int n) {
	if (n < 1)return 0;
	if (padoban[n] > -1)return padoban[n];
	else {
		padoban[n] = pado(n - 1) + pado(n - 5);
		return padoban[n];
	}
}

int main() {
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		memset(padoban, -1, sizeof(padoban));
		padoban[0] = 0;
		padoban[1] = 1;
		padoban[2] = 1;
		padoban[3] = 1;
		padoban[4] = 2;
		padoban[5] = 2;
		cout << pado(n) << endl;
	}
	return 0;
}