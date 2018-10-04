#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int D[1000000];

int makeUp(int n) {
	
	
	if (n == 1) {
		return 0;
	}
	if (D[n] > 0) {
		return D[n];
	}
	D[n] = makeUp(n - 1) + 1;
	if (n % 2 == 0) {
		int temp = makeUp(n / 2) + 1;
		if (D[n] > temp) {
			D[n] = temp;
		}
	}
	if (n % 3 == 0) {
		int temp = makeUp(n / 3) + 1;
		if (D[n] > temp) {
			D[n] = temp;
		}
	}

	return D[n];
}

int main() {
	int n;
	cin >> n;
	int count = makeUp(n);
	cout << count;
}