#include<iostream>
using namespace std;
#include<algorithm>

int dmax[1001];
int dmin[1001];
int a[1001];
int b[1001];
int D_max_min(int n,int a[],int b[]) {
	
	for (int i = 1; i <= n; i++) {
		dmin[i] = 1;
		for (int j = 1; j <= i; j++) {
			if (b[j]<b[i] && dmin[i]<dmin[j] + 1) {
				dmin[i] = dmin[j] + 1;
			}
		}
		
	}
	
	for (int i = 1; i <= n; i++) {
		dmax[i] = 1;
		for (int j = 1; j <= i; j++) {
			if (a[j]<a[i] && dmax[i]<dmax[j] + 1) {
				dmax[i] = dmax[j] + 1;
			}
		}
	}
	
	int anw = 0;
	for (int i = 1; i <= n; i++) {
		if (anw < dmax[i]+dmin[i]-1) {
			anw = dmax[i]+dmin[i]-1;
		}
	}
	return anw;
}

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
	
	 
	cout << D_max_min(n, a, b);
	
}