#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int D[11];


int combineSum(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {

		return 1;
	}
	if (n == 2) {
		return 2;
	}
	if (n == 3) {
		return 4;
	}
	D[n]=combineSum(n - 1) + combineSum(n - 2) + combineSum(n - 3);
	
	return D[n];
}



int main() {
	
	int n;
	cin >> n;
	int sum_case[11];
	int count=0;
	for (int i = 0; i < n; i++) {
		cin >> sum_case[i];
		count++;
	}
	
	int sum[11];
	for (int i = 0; i < n; i++) {
		
		int a=sum_case[i];
		sum[i]=combineSum(a);
		
	}
	
	for (int i = 0; i < count; i++) {
		cout << sum[i]<<endl;
	}

}
