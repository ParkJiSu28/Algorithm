#include<iostream>
using namespace std;
int decimal[3];

int main() {
	int n;
	cin >> n;
	int hansu;
	int count;
	int number;
	for (int i = 0; i <= n; i++) {
		if (i < 100)hansu=i;
		else if (i == 1000)break;
		number = i;
		count = 0;
		while (number > 0) {
			decimal[count] = number % 10;
			number /= 10; count++;
		}
		if (decimal[0] - decimal[1] == decimal[1] - decimal[2])hansu++;
	}
	cout << hansu;
}
